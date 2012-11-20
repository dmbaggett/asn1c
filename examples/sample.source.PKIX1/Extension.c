/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc5280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#include "Extension.h"

static asn_TYPE_member_t asn_MBR_Extension_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Extension, extnID),
		(ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
		0,
		&asn_DEF_OBJECT_IDENTIFIER,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"extnID"
		},
	{ ATF_POINTER, 1, offsetof(struct Extension, critical),
		(ASN_TAG_CLASS_UNIVERSAL | (1 << 2)),
		0,
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"critical"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Extension, extnValue),
		(ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
		0,
		&asn_DEF_OCTET_STRING,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"extnValue"
		},
};
static ber_tlv_tag_t asn_DEF_Extension_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_Extension_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (1 << 2)), 1, 0, 0 }, /* critical at 402 */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 2, 0, 0 }, /* extnValue at 403 */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 } /* extnID at 401 */
};
static asn_SEQUENCE_specifics_t asn_SPC_Extension_specs_1 = {
	sizeof(struct Extension),
	offsetof(struct Extension, _asn_ctx),
	asn_MAP_Extension_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_Extension = {
	"Extension",
	"Extension",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_Extension_tags_1,
	sizeof(asn_DEF_Extension_tags_1)
		/sizeof(asn_DEF_Extension_tags_1[0]), /* 1 */
	asn_DEF_Extension_tags_1,	/* Same as above */
	sizeof(asn_DEF_Extension_tags_1)
		/sizeof(asn_DEF_Extension_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Extension_1,
	3,	/* Elements count */
	&asn_SPC_Extension_specs_1	/* Additional specs */
};

