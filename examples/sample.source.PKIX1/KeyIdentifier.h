/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Implicit88"
 * 	found in "../rfc5280-PKIX1Implicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_KeyIdentifier_H_
#define	_KeyIdentifier_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* KeyIdentifier */
typedef OCTET_STRING_t	 KeyIdentifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_KeyIdentifier;
asn_struct_free_f KeyIdentifier_free;
asn_struct_print_f KeyIdentifier_print;
asn_constr_check_f KeyIdentifier_constraint;
ber_type_decoder_f KeyIdentifier_decode_ber;
der_type_encoder_f KeyIdentifier_encode_der;
xer_type_decoder_f KeyIdentifier_decode_xer;
xer_type_encoder_f KeyIdentifier_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _KeyIdentifier_H_ */
#include <asn_internal.h>
