/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Implicit88"
 * 	found in "../rfc3280-PKIX1Implicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_BaseCRLNumber_H_
#define	_BaseCRLNumber_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CRLNumber.h"

#ifdef __cplusplus
extern "C" {
#endif

/* BaseCRLNumber */
typedef CRLNumber_t	 BaseCRLNumber_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BaseCRLNumber;
asn_struct_free_f BaseCRLNumber_free;
asn_struct_print_f BaseCRLNumber_print;
asn_constr_check_f BaseCRLNumber_constraint;
ber_type_decoder_f BaseCRLNumber_decode_ber;
der_type_encoder_f BaseCRLNumber_encode_der;
xer_type_decoder_f BaseCRLNumber_decode_xer;
xer_type_encoder_f BaseCRLNumber_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _BaseCRLNumber_H_ */
#include <asn_internal.h>
