/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc5280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_TBSCertList_H_
#define	_TBSCertList_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Version.h"
#include "AlgorithmIdentifier.h"
#include "Name.h"
#include "Time.h"
#include <asn_SEQUENCE_OF.h>
#include "CertificateSerialNumber.h"
#include <constr_SEQUENCE.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Time;
struct Extensions;

/* TBSCertList */
typedef struct TBSCertList {
	Version_t	*version	/* OPTIONAL */;
	AlgorithmIdentifier_t	 signature;
	Name_t	 issuer;
	Time_t	 thisUpdate;
	struct Time	*nextUpdate	/* OPTIONAL */;
	struct revokedCertificates {
		A_SEQUENCE_OF(struct Member {
			CertificateSerialNumber_t	 userCertificate;
			Time_t	 revocationDate;
			struct Extensions	*crlEntryExtensions	/* OPTIONAL */;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} ) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *revokedCertificates;
	struct Extensions	*crlExtensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TBSCertList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TBSCertList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Time.h"
#include "Extensions.h"

#endif	/* _TBSCertList_H_ */
#include <asn_internal.h>