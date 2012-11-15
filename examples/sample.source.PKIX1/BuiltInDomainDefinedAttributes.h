/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc3280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_BuiltInDomainDefinedAttributes_H_
#define	_BuiltInDomainDefinedAttributes_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BuiltInDomainDefinedAttribute;

/* BuiltInDomainDefinedAttributes */
typedef struct BuiltInDomainDefinedAttributes {
	A_SEQUENCE_OF(struct BuiltInDomainDefinedAttribute) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BuiltInDomainDefinedAttributes_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BuiltInDomainDefinedAttributes;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BuiltInDomainDefinedAttribute.h"

#endif	/* _BuiltInDomainDefinedAttributes_H_ */
#include <asn_internal.h>
