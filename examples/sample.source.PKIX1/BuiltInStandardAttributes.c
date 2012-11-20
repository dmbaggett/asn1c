/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc5280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#include "BuiltInStandardAttributes.h"

static asn_TYPE_member_t asn_MBR_BuiltInStandardAttributes_1[] = {
	{ ATF_POINTER, 9, offsetof(struct BuiltInStandardAttributes, country_name),
		(ASN_TAG_CLASS_APPLICATION | (1 << 2)),
		0,
		&asn_DEF_CountryName,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"country-name"
		},
	{ ATF_POINTER, 8, offsetof(struct BuiltInStandardAttributes, administration_domain_name),
		(ASN_TAG_CLASS_APPLICATION | (2 << 2)),
		0,
		&asn_DEF_AdministrationDomainName,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"administration-domain-name"
		},
	{ ATF_POINTER, 7, offsetof(struct BuiltInStandardAttributes, network_address),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NetworkAddress,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"network-address"
		},
	{ ATF_POINTER, 6, offsetof(struct BuiltInStandardAttributes, terminal_identifier),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TerminalIdentifier,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"terminal-identifier"
		},
	{ ATF_POINTER, 5, offsetof(struct BuiltInStandardAttributes, private_domain_name),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_PrivateDomainName,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"private-domain-name"
		},
	{ ATF_POINTER, 4, offsetof(struct BuiltInStandardAttributes, organization_name),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OrganizationName,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"organization-name"
		},
	{ ATF_POINTER, 3, offsetof(struct BuiltInStandardAttributes, numeric_user_identifier),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NumericUserIdentifier,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"numeric-user-identifier"
		},
	{ ATF_POINTER, 2, offsetof(struct BuiltInStandardAttributes, personal_name),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PersonalName,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"personal-name"
		},
	{ ATF_POINTER, 1, offsetof(struct BuiltInStandardAttributes, organizational_unit_names),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OrganizationalUnitNames,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"organizational-unit-names"
		},
};
static ber_tlv_tag_t asn_DEF_BuiltInStandardAttributes_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_BuiltInStandardAttributes_tag2el_1[] = {
    { (ASN_TAG_CLASS_APPLICATION | (1 << 2)), 0, 0, 0 }, /* country-name at 474 */
    { (ASN_TAG_CLASS_APPLICATION | (2 << 2)), 1, 0, 0 }, /* administration-domain-name at 475 */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 2, 0, 0 }, /* network-address at 476 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 3, 0, 0 }, /* terminal-identifier at 478 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 4, 0, 0 }, /* private-domain-name at 479 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 5, 0, 0 }, /* organization-name at 480 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 6, 0, 0 }, /* numeric-user-identifier at 483 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 7, 0, 0 }, /* personal-name at 484 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 8, 0, 0 } /* organizational-unit-names at 487 */
};
static asn_SEQUENCE_specifics_t asn_SPC_BuiltInStandardAttributes_specs_1 = {
	sizeof(struct BuiltInStandardAttributes),
	offsetof(struct BuiltInStandardAttributes, _asn_ctx),
	asn_MAP_BuiltInStandardAttributes_tag2el_1,
	9,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_BuiltInStandardAttributes = {
	"BuiltInStandardAttributes",
	"BuiltInStandardAttributes",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_BuiltInStandardAttributes_tags_1,
	sizeof(asn_DEF_BuiltInStandardAttributes_tags_1)
		/sizeof(asn_DEF_BuiltInStandardAttributes_tags_1[0]), /* 1 */
	asn_DEF_BuiltInStandardAttributes_tags_1,	/* Same as above */
	sizeof(asn_DEF_BuiltInStandardAttributes_tags_1)
		/sizeof(asn_DEF_BuiltInStandardAttributes_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_BuiltInStandardAttributes_1,
	9,	/* Elements count */
	&asn_SPC_BuiltInStandardAttributes_specs_1	/* Additional specs */
};

