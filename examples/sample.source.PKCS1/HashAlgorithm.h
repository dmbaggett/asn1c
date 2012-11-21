/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKCS-1"
 * 	found in "../pkcs-1v2-1-modified.asn"
 */

#ifndef	_HashAlgorithm_H_
#define	_HashAlgorithm_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AlgorithmIdentifier.h"

#ifdef __cplusplus
extern "C" {
#endif

/* HashAlgorithm */
typedef AlgorithmIdentifier_120P0_t	 HashAlgorithm_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HashAlgorithm;
asn_struct_free_f HashAlgorithm_free;
asn_struct_print_f HashAlgorithm_print;
asn_constr_check_f HashAlgorithm_constraint;
ber_type_decoder_f HashAlgorithm_decode_ber;
der_type_encoder_f HashAlgorithm_encode_der;
xer_type_decoder_f HashAlgorithm_decode_xer;
xer_type_encoder_f HashAlgorithm_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _HashAlgorithm_H_ */
#include <asn_internal.h>
