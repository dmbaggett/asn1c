/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc5280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_AttributeTypeAndValue_H_
#define	_AttributeTypeAndValue_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AttributeType.h"
#include "AttributeValue.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* AttributeTypeAndValue */
typedef struct AttributeTypeAndValue {
	AttributeType_t	 type;
	AttributeValue_t	 value;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AttributeTypeAndValue_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AttributeTypeAndValue;

#ifdef __cplusplus
}
#endif

#endif	/* _AttributeTypeAndValue_H_ */
#include <asn_internal.h>
