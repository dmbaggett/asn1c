/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc3280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#include "PhysicalDeliveryOfficeName.h"

int
PhysicalDeliveryOfficeName_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_PDSParameter.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using PDSParameter,
 * so here we adjust the DEF accordingly.
 */
static void
PhysicalDeliveryOfficeName_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_PDSParameter.free_struct;
	td->print_struct   = asn_DEF_PDSParameter.print_struct;
	td->ber_decoder    = asn_DEF_PDSParameter.ber_decoder;
	td->der_encoder    = asn_DEF_PDSParameter.der_encoder;
	td->xer_decoder    = asn_DEF_PDSParameter.xer_decoder;
	td->xer_encoder    = asn_DEF_PDSParameter.xer_encoder;
	td->uper_decoder   = asn_DEF_PDSParameter.uper_decoder;
	td->uper_encoder   = asn_DEF_PDSParameter.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_PDSParameter.per_constraints;
	td->elements       = asn_DEF_PDSParameter.elements;
	td->elements_count = asn_DEF_PDSParameter.elements_count;
	td->specifics      = asn_DEF_PDSParameter.specifics;
}

void
PhysicalDeliveryOfficeName_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	PhysicalDeliveryOfficeName_1_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

int
PhysicalDeliveryOfficeName_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	PhysicalDeliveryOfficeName_1_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
PhysicalDeliveryOfficeName_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	PhysicalDeliveryOfficeName_1_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
PhysicalDeliveryOfficeName_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	PhysicalDeliveryOfficeName_1_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
PhysicalDeliveryOfficeName_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	PhysicalDeliveryOfficeName_1_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
PhysicalDeliveryOfficeName_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	PhysicalDeliveryOfficeName_1_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static ber_tlv_tag_t asn_DEF_PhysicalDeliveryOfficeName_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (17 << 2))
};
asn_TYPE_descriptor_t asn_DEF_PhysicalDeliveryOfficeName = {
	"PhysicalDeliveryOfficeName",
	"PhysicalDeliveryOfficeName",
	PhysicalDeliveryOfficeName_free,
	PhysicalDeliveryOfficeName_print,
	PhysicalDeliveryOfficeName_constraint,
	PhysicalDeliveryOfficeName_decode_ber,
	PhysicalDeliveryOfficeName_encode_der,
	PhysicalDeliveryOfficeName_decode_xer,
	PhysicalDeliveryOfficeName_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_PhysicalDeliveryOfficeName_tags_1,
	sizeof(asn_DEF_PhysicalDeliveryOfficeName_tags_1)
		/sizeof(asn_DEF_PhysicalDeliveryOfficeName_tags_1[0]), /* 1 */
	asn_DEF_PhysicalDeliveryOfficeName_tags_1,	/* Same as above */
	sizeof(asn_DEF_PhysicalDeliveryOfficeName_tags_1)
		/sizeof(asn_DEF_PhysicalDeliveryOfficeName_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	0, 0,	/* Defined elsewhere */
	0	/* No specifics */
};

