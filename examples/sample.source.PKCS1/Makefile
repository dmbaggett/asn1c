#
# Use asn1c to generate C code from the PKCS1 v2.1 spec.
#
# NOTE: you must use a modified spec that removes all the | operators
# and renames AlgorithmIdentifier! The stock spec WILL NOT work.
#
all: ../pkcs-1v2-1-modified.asn
	../../asn1c/asn1c ../pkcs-1v2-1-modified.asn
	# Remove files that won't compile:
	rm RSAES-OAEP-params.[ch]
	rm RSASSA-PSS-params.[ch]
	# Remove files that duplicate files in ../sample.source.PKIX1
	rm ANY.h
	rm ANY.c
	rm BOOLEAN.h
	rm BOOLEAN.c
	rm INTEGER.h
	rm NativeEnumerated.h
	rm INTEGER.c
	rm NativeEnumerated.c
	rm NativeInteger.h
	rm NativeInteger.c
	rm OBJECT_IDENTIFIER.h
	rm OBJECT_IDENTIFIER.c
	rm Version.h
	rm Version.c
	rm asn_SEQUENCE_OF.h
	rm asn_SEQUENCE_OF.c
	rm asn_SET_OF.h
	rm asn_SET_OF.c
	rm constr_SEQUENCE.h
	rm constr_SEQUENCE.c
	rm constr_SEQUENCE_OF.h
	rm constr_SEQUENCE_OF.c
	rm constr_SET_OF.h
	rm constr_SET_OF.c
	rm asn_application.h
	rm asn_system.h
	rm asn_codecs.h
	rm asn_internal.h
	rm OCTET_STRING.h
	rm OCTET_STRING.c
	rm BIT_STRING.h
	rm BIT_STRING.c
	rm asn_codecs_prim.c
	rm asn_codecs_prim.h
	rm ber_tlv_length.h
	rm ber_tlv_length.c
	rm ber_tlv_tag.h
	rm ber_tlv_tag.c
	rm ber_decoder.h
	rm ber_decoder.c
	rm der_encoder.h
	rm der_encoder.c
	rm constr_TYPE.h
	rm constr_TYPE.c
	rm constraints.h
	rm constraints.c
	rm xer_support.h
	rm xer_support.c
	rm xer_decoder.h
	rm xer_decoder.c
	rm xer_encoder.h
	rm xer_encoder.c
	rm per_support.h
	rm per_support.c
	rm per_decoder.h
	rm per_decoder.c
	rm per_encoder.h
	rm per_encoder.c
	rm per_opentype.h
	rm per_opentype.c
	rm converter-sample.c

clean:
	rm *.[ch]

