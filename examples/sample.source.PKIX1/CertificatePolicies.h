/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Implicit88"
 * 	found in "../rfc3280-PKIX1Implicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_CertificatePolicies_H_
#define	_CertificatePolicies_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PolicyInformation;

/* CertificatePolicies */
typedef struct CertificatePolicies {
	A_SEQUENCE_OF(struct PolicyInformation) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CertificatePolicies_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CertificatePolicies;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PolicyInformation.h"

#endif	/* _CertificatePolicies_H_ */
#include <asn_internal.h>
