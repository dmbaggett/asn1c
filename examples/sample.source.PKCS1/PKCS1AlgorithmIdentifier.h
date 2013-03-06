/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKCS-1"
 * 	found in "../pkcs-1v2-1-modified.asn"
 */

#ifndef	_PKCS1AlgorithmIdentifier_H_
#define	_PKCS1AlgorithmIdentifier_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OBJECT_IDENTIFIER.h>
#include <ANY.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PKCS1AlgorithmIdentifier */
typedef struct PKCS1AlgorithmIdentifier_120P0 {
	OBJECT_IDENTIFIER_t	 algorithm;
	ANY_t	 parameters;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PKCS1AlgorithmIdentifier_120P0_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PKCS1AlgorithmIdentifier_120P0;

#ifdef __cplusplus
}
#endif

#endif	/* _PKCS1AlgorithmIdentifier_H_ */
#include <asn_internal.h>