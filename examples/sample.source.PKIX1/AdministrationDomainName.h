/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc5280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_AdministrationDomainName_H_
#define	_AdministrationDomainName_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NumericString.h>
#include <PrintableString.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum AdministrationDomainName_PR {
	AdministrationDomainName_PR_NOTHING,	/* No components present */
	AdministrationDomainName_PR_numeric,
	AdministrationDomainName_PR_printable
} AdministrationDomainName_PR;

/* AdministrationDomainName */
typedef struct AdministrationDomainName {
	AdministrationDomainName_PR present;
	union AdministrationDomainName_u {
		NumericString_t	 numeric;
		PrintableString_t	 printable;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AdministrationDomainName_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AdministrationDomainName;

#ifdef __cplusplus
}
#endif

#endif	/* _AdministrationDomainName_H_ */
#include <asn_internal.h>
