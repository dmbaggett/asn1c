#include "asn1c_internal.h"

static void default_logger_cb(int, const char *fmt, ...);
static int asn1c_compile_expr(arg_t *arg);
static int asn1c_attach_streams(asn1p_expr_t *expr);

int
asn1_compile(asn1p_t *asn, const char *datadir, enum asn1c_flags flags) {
	arg_t arg_s;
	arg_t *arg = &arg_s;
	int ret;

	/*
	 * Initialize target language.
	 */
	ret = asn1c_with_language(ASN1C_LANGUAGE_C);
	assert(ret == 0);

	memset(arg, 0, sizeof(*arg));
	arg->default_cb = asn1c_compile_expr;
	arg->logger_cb = default_logger_cb;
	arg->flags = flags;
	arg->asn = asn;

	/*
	 * Compile each individual top level structure.
	 */
	TQ_FOR(arg->mod, &(asn->modules), mod_next) {
		TQ_FOR(arg->expr, &(arg->mod->members), next) {
			compiler_streams_t *cs = NULL;

			if(asn1c_attach_streams(arg->expr))
				return -1;

			cs = arg->expr->data;
			cs->target = OT_TYPE_DECLS;
			arg->target = cs;

			ret = asn1c_compile_expr(arg);
			if(ret) {
				FATAL("Cannot compile %s (%x:%x) at line %d",
					arg->expr->Identifier,
					arg->expr->expr_type,
					arg->expr->meta_type,
					arg->expr->_lineno);
				return ret;
			}
		}
	}

	DEBUG("Saving compiled data");

	/*
	 * Save or print out the compiled result.
	 */
	if(asn1c_save_compiled_output(arg, datadir))
		return -1;

	return 0;
}

static int
asn1c_compile_expr(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	int (*type_cb)(arg_t *);
	int ret;

	assert((int)expr->meta_type >= AMT_INVALID);
	assert(expr->meta_type < AMT_EXPR_META_MAX);
	assert((int)expr->expr_type >= A1TC_INVALID);
	assert(expr->expr_type < ASN_EXPR_TYPE_MAX);

	type_cb = asn1_lang_map[expr->meta_type][expr->expr_type].type_cb;
	if(type_cb) {

		if(arg->indent_level == 0)
			OUT("\n");

		DEBUG("Compiling %s at line %d",
			expr->Identifier,
			expr->_lineno);

		ret = type_cb(arg);
	} else {
		ret = -1;
		/*
		 * Even if the target language compiler does not know
		 * how to compile the given expression, we know that
		 * certain expressions need not to be compiled at all.
		 */
		switch(expr->meta_type) {
		case AMT_PARAMTYPE:
		case AMT_OBJECT:
		case AMT_OBJECTSET:
		case AMT_VALUE:
		case AMT_VALUESET:
			ret = 0;
			break;
		default:
			break;
		}

		switch(expr->expr_type) {
		case A1TC_TYPEID:
			ret = 0;	/* TYPE-IDENTIFIER is a CLASS */
		default:
			break;
		}
	}

	if(ret == -1) {
		OUT("#error Cannot compile \"%s\" (%x/%x) at line %d\n",
			arg->expr->Identifier,
			arg->expr->meta_type,
			arg->expr->expr_type,
			arg->expr->_lineno
		);
	}

	return ret;
}

static int
asn1c_attach_streams(asn1p_expr_t *expr) {
	compiler_streams_t *cs;
	int i;

	if(expr->data)
		return 0;	/* Already attached? */

	expr->data = calloc(1, sizeof(compiler_streams_t));
	if(expr->data == NULL)
		return -1;

	cs = expr->data;
	for(i = 0; i < OT_MAX; i++) {
		TQ_INIT(&(cs->targets[i]));
	}

	return 0;
}

static void
default_logger_cb(int _severity, const char *fmt, ...) {
	va_list ap;
	char *pfx = "";

	switch(_severity) {
	case -1: pfx = "DEBUG: "; break;
	case 0: pfx = "WARNING: "; break;
	case 1: pfx = "FATAL: "; break;
	}

	fprintf(stderr, "%s", pfx);
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
}
