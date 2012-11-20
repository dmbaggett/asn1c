/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc5280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_ORAddress_H_
#define	_ORAddress_H_


#include <asn_application.h>

/* Including external dependencies */
#include "BuiltInStandardAttributes.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BuiltInDomainDefinedAttributes;
struct ExtensionAttributes;

/* ORAddress */
typedef struct ORAddress {
	BuiltInStandardAttributes_t	 built_in_standard_attributes;
	struct BuiltInDomainDefinedAttributes	*built_in_domain_defined_attributes	/* OPTIONAL */;
	struct ExtensionAttributes	*extension_attributes	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ORAddress_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ORAddress;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BuiltInDomainDefinedAttributes.h"
#include "ExtensionAttributes.h"

#endif	/* _ORAddress_H_ */
#include <asn_internal.h>
