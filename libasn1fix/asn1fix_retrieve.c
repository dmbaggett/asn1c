#include "asn1fix_internal.h"

static asn1p_expr_t *asn1f_find_terminal_thing(arg_t *arg, asn1p_expr_t *expr, asn1p_module_t **optm, int type_or_value);
static int asn1f_compatible_with_exports(arg_t *arg, asn1p_module_t *mod, const char *name);


/*
 * Lookup a child by its name.
 */
asn1p_expr_t *
asn1f_lookup_child(asn1p_expr_t *tc, const char *name) {
	asn1p_expr_t *child_tc;

	TQ_FOR(child_tc, &(tc->members), next) {
		if(child_tc->Identifier
		&& strcmp(child_tc->Identifier, name) == 0) {
			return child_tc;
		}
	}

	errno = ESRCH;
	return NULL;
}

asn1p_module_t *
asn1f_lookup_in_imports(arg_t *arg, const char *name) {
	asn1p_module_t *mod;
	asn1p_xports_t *xp;
	asn1p_expr_t *tc;

	/*
	 * Search in which exactly module this name is defined.
	 */
	TQ_FOR(xp, &(arg->mod->imports), xp_next) {
		TQ_FOR(tc, &(xp->members), next) {
			if(strcmp(name, tc->Identifier) == 0)
				break;
		}
		if(tc) break;
	}
	if(xp == NULL) {
		errno = ESRCH;
		return NULL;
	}

	/*
	 * Okay, right now we have a module name and, hopefully, an OID.
	 * Search the arg->asn for the specified module.
	 */
	mod = asn1f_lookup_module(arg, xp->from, xp->from_oid);
	if(mod == NULL) {
		/* ENOENT/ETOOMANYREFS */
		return NULL;
	}

	/*
	 * Check that the EXPORTS section of this module contains
	 * the symbol we care about, or it is EXPORTS ALL.
	 */
	if(asn1f_compatible_with_exports(arg, mod, name)) {
		errno = EPERM;
		return NULL;
	}

	return mod;
}

asn1p_module_t *
asn1f_lookup_module(arg_t *arg, const char *module_name, asn1p_oid_t *oid) {
	asn1p_module_t *mod;

	assert(module_name);

	/*
	 * If OID is given, the module_name is unused.
	 * If OID is not given, the module_name may mean
	 * either the real module's name, or the symbol which is the
	 * result of renaming. Check this first.
	 */
	if(oid == 0) {
		asn1p_xports_t *xp;
		/*
		 * Check inside the IMPORTS section for possible renaming.
		 * Renaming practically means that a module_name is mentioned
		 * somewhere in the IMPORTS section AND OID is given.
		 */
		TQ_FOR(xp, &(arg->mod->imports), xp_next) {
			if(strcmp(module_name, xp->from))
				continue;
			if(oid) {
				FATAL("Ambiguous reference: "
					"%s "
					"matches several modules",
					module_name);
				errno = ETOOMANYREFS;
				return NULL;
			}
			/*
			 * Yes, there is a renaming.
			 * Make lookup use OID instead.
			 */
			oid = xp->from_oid;
		}
	}

	/*
	 * Perform lookup using OID or module_name.
	 */
	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		if(oid) {
			if(mod->module_oid) {
				if(asn1p_oid_compare(oid,
					mod->module_oid)) {
					continue;
				} else {
					/* Match! Even if name doesn't. */
					return mod;
				}
			} else {
				/* Not match, even if name is the same. */
				continue;
			}
		}
	
		if(strcmp(module_name, mod->Identifier) == 0)
			return mod;
	}

	DEBUG("\tModule \"%s\" not found", module_name);

	errno = ENOENT;
	return NULL;
}



asn1p_expr_t *
asn1f_lookup_symbol(arg_t *arg, asn1p_ref_t *ref, asn1p_module_t **module_r) {
	asn1p_expr_t *ref_tc;			/* Referenced tc */
	asn1p_module_t *src_mod;
	char *modulename;
	char *identifier;

	/*
	 * First of all, a reference to a symbol may be specified
	 * using several possible forms:
	 * a) simple identifier
	 *	v INTEGER ::= value
	 * b) external reference
	 * 	v INTEGER ::= Module1.value
	 * c) class-related stuff (the most complex stuff)
	 * 	v ::= <[A-Z][A-Z0-9a-z-]*>.&<[A-Z0-9a-z-]+>.
	 * All other forms are not implemented at this moment.
	 */

	DEBUG("%s(%s) in %s for line %d", __func__,
		asn1f_printable_reference(ref),
		arg->mod->Identifier,
		ref->_lineno);

	if(ref->comp_count == 1) {
		modulename = NULL;
		identifier = ref->components[0].name;
	} else if(ref->comp_count == 2
		&& ref->components[1].name[0] != '&') {
		modulename = ref->components[0].name;
		identifier = ref->components[1].name;
	} else if(ref->comp_count > 1
		&& isupper(ref->components[0].name[0])
		&& ref->components[1].name[0] == '&') {
		asn1p_expr_t *extract;
		/*
		 * This is a reference to a CLASS-related stuff.
		 * Employ a separate function for that.
		 */
		extract = asn1f_class_access(arg, ref, module_r);
		
		return extract;
	} else {
		DEBUG("\tToo many components: %d", ref->comp_count);
		errno = EINVAL;
		return NULL;
	}

	/*
	 * If module name is specified explicitly
	 * OR the current module's IMPORTS clause contains the identifier,
	 * fetch that module.
	 */
	if(modulename) {
		src_mod = asn1f_lookup_module(arg, modulename, 0);
		if(src_mod == NULL) {
			FATAL("Module \"%s\" "
				"mentioned at line %d is not found",
				modulename, ref->_lineno);
			return NULL;
		}

		/*
		 * Check that the EXPORTS section of this module contains
		 * the symbol we care about, or it is EXPORTS ALL.
		 */
		if(asn1f_compatible_with_exports(arg, src_mod, identifier)) {
			errno = EPERM;
			return NULL;
		}
	} else {
		src_mod = asn1f_lookup_in_imports(arg, identifier);
		if(src_mod == NULL && errno != ESRCH) {
			/*
			 * Return only of the name was not found.
			 * If module was not found or more serious error
			 * encountered, just return preserving the errno.
			 */
			return NULL;
		}
	}

	if(src_mod == 0) src_mod = arg->mod;

	/*
	 * Now we know where to search for a value.
	 */
	TQ_FOR(ref_tc, &(src_mod->members), next) {
		if(ref_tc->Identifier)
		if(strcmp(ref_tc->Identifier, identifier) == 0)
			break;
	}
	if(ref_tc == NULL) {
		DEBUG("Module \"%s\" does not contain \"%s\" "
			"mentioned at line %d",
			src_mod->Identifier,
			identifier,
			ref->_lineno
		);
		errno = ESRCH;
		return NULL;
	}

	if(module_r)
		*module_r = src_mod;

	return ref_tc;
}


asn1p_expr_t *
asn1f_find_terminal_type(arg_t *arg, asn1p_expr_t *expr,
		asn1p_module_t **optm) {
	return asn1f_find_terminal_thing(arg, expr, optm, 0);
}

asn1p_expr_t *
asn1f_find_terminal_value(arg_t *arg, asn1p_expr_t *expr,
		asn1p_module_t **optm) {
	return asn1f_find_terminal_thing(arg, expr, optm, 1);
}

static asn1p_expr_t *
asn1f_find_terminal_thing(arg_t *arg, asn1p_expr_t *expr,
	asn1p_module_t **optm, int type_or_value) {
	asn1p_module_t *mod;
	asn1p_ref_t *ref;
	asn1p_expr_t *tc;

	if(type_or_value) {
		/* VALUE */
		assert(expr->meta_type == AMT_VALUE);
		assert(expr->value);
		if(expr->value->type != ATV_REFERENCED) {
			/* Expression is a terminal value itself */
			if(optm) *optm = arg->mod;
			return expr;
		}
		ref = expr->value->value.reference;
	} else {
		/* TYPE */
		if(expr->expr_type != A1TC_REFERENCE) {
			/* Expression is a terminal type itself */
			if(optm) *optm = arg->mod;
			return expr;
		}
		ref = expr->reference;
	}

	DEBUG("%s:%s(%s->%s) for line %d",
		__func__, type_or_value?"VALUE":"TYPE",
		expr->Identifier, asn1f_printable_reference(ref),
		expr->_lineno);

	assert(ref);

	/*
	 * Lookup inside the type itself (ENUMERATED, INTEGER, etc).
	 */
	if(type_or_value) {
		asn1p_expr_t *val_type_tc;
		val_type_tc = asn1f_find_terminal_type(arg, expr, 0);
		if(val_type_tc
		&& asn1f_look_value_in_type(arg, val_type_tc, expr))
			return NULL;
		if(expr->value->type != ATV_REFERENCED) {
			if(optm) *optm = arg->mod;
			return expr;
		}
		assert(ref == expr->value->value.reference);
		ref = expr->value->value.reference;
	}

	/*
	 * Lookup inside the default module.
	 */
	tc = asn1f_lookup_symbol(arg, ref, &mod);
	if(tc == NULL) {
		DEBUG("\tSymbol \"%s\" not found",
			asn1f_printable_reference(ref));
		return NULL;
	}

	/*
	 * Recursive loops detection.
	 */
	if(tc->_mark & TM_RECURSION) {
		DEBUG("Recursion loop detected for %s at line %d",
			asn1f_printable_reference(ref), ref->_lineno);
		errno = EPERM;
		return NULL;
	}

	tc->_mark |= TM_RECURSION;
	WITH_MODULE(mod,
		expr = asn1f_find_terminal_thing(arg, tc, optm, type_or_value));
	tc->_mark &= ~TM_RECURSION;

	return expr;
}

/*
 * Make sure that the specified name is present or otherwise does
 * not contradict with the EXPORTS clause of the specified module.
 */
static int
asn1f_compatible_with_exports(arg_t *arg, asn1p_module_t *mod, const char *name) {
	asn1p_xports_t *exports;
	asn1p_expr_t *item;

	assert(mod);
	assert(name);

	exports = TQ_FIRST(&(mod->exports));
	if(exports == NULL) {
		/* No EXPORTS section or EXPORTS ALL; */
		return 0;
	}

	TQ_FOR(item, &(exports->members), next) {
		if(strcmp(item->Identifier, name) == 0)
			return 0;
	}

	DEBUG("Symbol \"%s\" contradicts with EXPORTS of module %s",
		name, mod->Identifier);

	errno = ESRCH;
	return -1;
}