#ifndef	ASN1_PARSER_EXPR2UCLASS_H
#define	ASN1_PARSER_EXPR2UCLASS_H

static int
expr_type2uclass_value[ASN_EXPR_TYPE_MAX]
		__attribute__ ((unused)) = {
	[ ASN_BASIC_BOOLEAN ]		= 1,
	[ ASN_BASIC_INTEGER ]		= 2,
	[ ASN_BASIC_BIT_STRING ]	= 3,
	[ ASN_BASIC_OCTET_STRING ]	= 4,
	[ ASN_BASIC_NULL ]		= 5,
	[ ASN_BASIC_OBJECT_IDENTIFIER ]	= 6,
	[ ASN_BASIC_EXTERNAL ]		= 7,
	[ ASN_STRING_ObjectDescriptor ]	= 7,
	[ ASN_BASIC_REAL ]		= 9,
	[ ASN_BASIC_ENUMERATED ]	= 10,
	[ ASN_BASIC_EMBEDDED_PDV ]	= 11,
	[ ASN_STRING_UTF8String ]	= 12,
	[ ASN_BASIC_RELATIVE_OID ]	= 13,
	[ ASN_CONSTR_SEQUENCE ]		= 16,
	[ ASN_CONSTR_SEQUENCE_OF ]	= 16,
	[ ASN_CONSTR_SET ]		= 17,
	[ ASN_CONSTR_SET_OF ]		= 17,
	[ ASN_STRING_NumericString ]	= 18,
	[ ASN_STRING_PrintableString ]	= 19,
	[ ASN_STRING_TeletexString ]	= 20,
	[ ASN_STRING_T61String ]	= 20,
	[ ASN_STRING_VideotexString ]	= 21,
	[ ASN_STRING_IA5String ]	= 22,
	[ ASN_BASIC_UTCTime ]		= 23,
	[ ASN_BASIC_GeneralizedTime ]	= 24,
	[ ASN_STRING_GraphicString ]	= 25,
	[ ASN_STRING_VisibleString ]	= 26,
	[ ASN_STRING_ISO646String ]	= 26,
	[ ASN_STRING_GeneralString ]	= 27,
	[ ASN_STRING_UniversalString ]	= 28,
	[ ASN_BASIC_CHARACTER_STRING ]	= 29,
	[ ASN_STRING_BMPString ]	= 30,
};

#endif	/* ASN1_PARSER_EXPR2UCLASS_H */