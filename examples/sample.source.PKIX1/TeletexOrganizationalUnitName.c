/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc5280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#include "TeletexOrganizationalUnitName.h"

int
TeletexOrganizationalUnitName_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const TeletexString_t *st = (const TeletexString_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 1 && size <= 32)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

/*
 * This type is implemented using TeletexString,
 * so here we adjust the DEF accordingly.
 */
static void
TeletexOrganizationalUnitName_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_TeletexString.free_struct;
	td->print_struct   = asn_DEF_TeletexString.print_struct;
	td->ber_decoder    = asn_DEF_TeletexString.ber_decoder;
	td->der_encoder    = asn_DEF_TeletexString.der_encoder;
	td->xer_decoder    = asn_DEF_TeletexString.xer_decoder;
	td->xer_encoder    = asn_DEF_TeletexString.xer_encoder;
	td->uper_decoder   = asn_DEF_TeletexString.uper_decoder;
	td->uper_encoder   = asn_DEF_TeletexString.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_TeletexString.per_constraints;
	td->elements       = asn_DEF_TeletexString.elements;
	td->elements_count = asn_DEF_TeletexString.elements_count;
	td->specifics      = asn_DEF_TeletexString.specifics;
}

void
TeletexOrganizationalUnitName_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	TeletexOrganizationalUnitName_1_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

int
TeletexOrganizationalUnitName_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	TeletexOrganizationalUnitName_1_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
TeletexOrganizationalUnitName_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	TeletexOrganizationalUnitName_1_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
TeletexOrganizationalUnitName_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	TeletexOrganizationalUnitName_1_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
TeletexOrganizationalUnitName_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	TeletexOrganizationalUnitName_1_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
TeletexOrganizationalUnitName_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	TeletexOrganizationalUnitName_1_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static ber_tlv_tag_t asn_DEF_TeletexOrganizationalUnitName_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (20 << 2))
};
asn_TYPE_descriptor_t asn_DEF_TeletexOrganizationalUnitName = {
	"TeletexOrganizationalUnitName",
	"TeletexOrganizationalUnitName",
	TeletexOrganizationalUnitName_free,
	TeletexOrganizationalUnitName_print,
	TeletexOrganizationalUnitName_constraint,
	TeletexOrganizationalUnitName_decode_ber,
	TeletexOrganizationalUnitName_encode_der,
	TeletexOrganizationalUnitName_decode_xer,
	TeletexOrganizationalUnitName_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_TeletexOrganizationalUnitName_tags_1,
	sizeof(asn_DEF_TeletexOrganizationalUnitName_tags_1)
		/sizeof(asn_DEF_TeletexOrganizationalUnitName_tags_1[0]), /* 1 */
	asn_DEF_TeletexOrganizationalUnitName_tags_1,	/* Same as above */
	sizeof(asn_DEF_TeletexOrganizationalUnitName_tags_1)
		/sizeof(asn_DEF_TeletexOrganizationalUnitName_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	0	/* No specifics */
};

