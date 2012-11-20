/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc5280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_ExtensionAttribute_H_
#define	_ExtensionAttribute_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <ANY.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ExtensionAttribute */
typedef struct ExtensionAttribute {
	long	 extension_attribute_type;
	ANY_t	 extension_attribute_value;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ExtensionAttribute_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ExtensionAttribute;

#ifdef __cplusplus
}
#endif

#endif	/* _ExtensionAttribute_H_ */
#include <asn_internal.h>
