/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc3280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_Extension_H_
#define	_Extension_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OBJECT_IDENTIFIER.h>
#include <BOOLEAN.h>
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Extension */
typedef struct Extension {
	OBJECT_IDENTIFIER_t	 extnID;
	BOOLEAN_t	*critical	/* DEFAULT FALSE */;
	OCTET_STRING_t	 extnValue;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Extension_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Extension;

#ifdef __cplusplus
}
#endif

#endif	/* _Extension_H_ */
#include <asn_internal.h>
