/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Implicit88"
 * 	found in "../rfc3280-PKIX1Implicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#include "DistributionPointName.h"

static asn_TYPE_member_t asn_MBR_DistributionPointName_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DistributionPointName, choice.fullName),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GeneralNames,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"fullName"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DistributionPointName, choice.nameRelativeToCRLIssuer),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RelativeDistinguishedName,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"nameRelativeToCRLIssuer"
		},
};
static asn_TYPE_tag2member_t asn_MAP_DistributionPointName_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* fullName at 239 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* nameRelativeToCRLIssuer at 240 */
};
static asn_CHOICE_specifics_t asn_SPC_DistributionPointName_specs_1 = {
	sizeof(struct DistributionPointName),
	offsetof(struct DistributionPointName, _asn_ctx),
	offsetof(struct DistributionPointName, present),
	sizeof(((struct DistributionPointName *)0)->present),
	asn_MAP_DistributionPointName_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_DistributionPointName = {
	"DistributionPointName",
	"DistributionPointName",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_DistributionPointName_1,
	2,	/* Elements count */
	&asn_SPC_DistributionPointName_specs_1	/* Additional specs */
};

