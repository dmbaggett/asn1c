#include "asn1fix_internal.h"

static int _compare_value(asn1p_expr_t *expr1, asn1p_expr_t *expr2) {
	if(expr2->value->type == ATV_INTEGER
	&& expr1->value->type == ATV_INTEGER) {
		return expr2->value->value.v_integer
			- expr1->value->value.v_integer;
	} else {
		return -1;
	}
}

/*
 * Check the validity of an INTEGER type.
 */
int
asn1f_fix_integer(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *iv;
	int rvalue = 0;
	int ret;

	if(expr->expr_type != ASN_BASIC_INTEGER)
		return 0;	/* Just ignore it */

	DEBUG("%s(\"%s\", %x) for line %d", __func__,
		expr->Identifier, expr->expr_type, expr->_lineno);

	/*
	 * Scan the integer values in search for inconsistencies.
	 */
	TQ_FOR(iv, &(expr->members), next) {

		DEBUG("\tItem %s(%s)", iv->Identifier,
			asn1f_printable_value(iv->value));

		/*
		 * Found "...", check correctness.
		 */
		if(iv->expr_type == A1TC_EXTENSIBLE) {
			arg->eh(1,
				"INTEGER %s at line %d: "
				"Extension marker is not allowed",
				expr->Identifier,
				iv->_lineno
			);
			rvalue = -1;
			continue;
		}

		if(iv->Identifier == NULL
		|| iv->expr_type != A1TC_UNIVERVAL) {
			arg->eh(1,
				"INTEGER %s at line %d: "
				"Unsupported enumeration element %s",
				expr->Identifier,
				iv->_lineno,
				iv->Identifier?iv->Identifier:"<Anonymous>"
			);
			rvalue = -1;
			continue;
		}

		if(iv->value == NULL) {
			arg->eh(1,
				"INTEGER %s at line %d: "
				"Value for the identifier %s "
				"must be set explicitly",
				expr->Identifier,
				iv->_lineno,
				iv->Identifier
			);
			rvalue = -1;
			continue;
		} else if(iv->value->type == ATV_REFERENCED) {
			/*
			 * Resolve the value, once and for all.
			 */
			if(asn1f_value_resolve(arg, iv)) {
				/* This function will emit messages */
				rvalue = -1;
				continue;
			}
		}

		if(iv->value->type != ATV_INTEGER) {
			arg->eh(1,
				"INTEGER %s at line %d: "
				"Value for the identifier %s "
				"is not compatible with INTEGER type",
				expr->Identifier,
				iv->_lineno);
			rvalue = -1;
			continue;
		}

		/*
		 * Check that all identifiers are distinct.
		 */
		ret = asn1f_check_unique_expr_child(arg, iv, NULL);
		RET2RVAL(ret, rvalue);
		/*
		 * Check that all values are distinct.
		 */
		ret = asn1f_check_unique_expr_child(arg, iv, _compare_value);
		RET2RVAL(ret, rvalue);
	}


	return rvalue;
}

static int
_asn1f_make_sure_type_is(arg_t *arg, asn1p_expr_t *expr, asn1p_expr_type_e type) {
	asn1p_module_t *mod = NULL;
	asn1p_expr_t *next_expr;
	asn1p_expr_type_e expr_type;
	int ret;

	expr_type = expr->expr_type;

	/*
	 * Here we're trying to make sure that the type of the given
	 * expression is really what is expected.
	 * This is ensured in two ways.
	 * First, if the immediate type matches the provided one,
	 * this is a clear hit.
	 */
	if(expr_type == type)
		return 0;

	/*
	 * Otherwise, it must be either a reference or a different type.
	 */
	if(expr_type != A1TC_REFERENCE) {
		errno = EPERM;
		return -1;
	}

	assert(expr_type == A1TC_REFERENCE);
	assert(expr->reference);

	/*
	 * Then, it is a reference. For a reference, try to resolve type
	 * and try again.
	 */
	next_expr = asn1f_lookup_symbol(arg, expr->reference, &mod);
	if(next_expr == NULL) {
		errno = ESRCH;
		return -1;
	}

	/*
	 * If symbol is here, recursively check that it conforms to the type.
	 */
	WITH_MODULE(mod, ret = _asn1f_make_sure_type_is(arg, next_expr, type));

	return ret;
}

