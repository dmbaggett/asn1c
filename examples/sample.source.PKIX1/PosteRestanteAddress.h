/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc5280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_PosteRestanteAddress_H_
#define	_PosteRestanteAddress_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PDSParameter.h"

#ifdef __cplusplus
extern "C" {
#endif

/* PosteRestanteAddress */
typedef PDSParameter_t	 PosteRestanteAddress_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PosteRestanteAddress;
asn_struct_free_f PosteRestanteAddress_free;
asn_struct_print_f PosteRestanteAddress_print;
asn_constr_check_f PosteRestanteAddress_constraint;
ber_type_decoder_f PosteRestanteAddress_decode_ber;
der_type_encoder_f PosteRestanteAddress_encode_der;
xer_type_decoder_f PosteRestanteAddress_decode_xer;
xer_type_encoder_f PosteRestanteAddress_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _PosteRestanteAddress_H_ */
#include <asn_internal.h>
