// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#import <Foundation/Foundation.h>

#import "UbiXGPBUtilities.h"

#import "UbiXGPBDescriptor_PackagePrivate.h"

// Macros for stringifying library symbols. These are used in the generated
// UbiXGPB descriptor classes wherever a library symbol name is represented as a
// string.
#define UbiXGPBStringify(S) #S
#define UbiXGPBStringifySymbol(S) UbiXGPBStringify(S)

#define UbiXGPBNSStringify(S) @#S
#define UbiXGPBNSStringifySymbol(S) UbiXGPBNSStringify(S)

// Macros for generating a Class from a class name. These are used in
// the generated UbiXGPB descriptor classes wherever an Objective C class
// reference is needed for a generated class.
#define UbiXGPBObjCClassSymbol(name) OBJC_CLASS_$_##name
#define UbiXGPBObjCClass(name) \
    ((__bridge Class)&(UbiXGPBObjCClassSymbol(name)))
#define UbiXGPBObjCClassDeclaration(name) \
    extern const UbiXGPBObjCClass_t UbiXGPBObjCClassSymbol(name)

// Constant to internally mark when there is no has bit.
#define UbiXGPBNoHasBit INT32_MAX

CF_EXTERN_C_BEGIN

// These two are used to inject a runtime check for version mismatch into the
// generated sources to make sure they are linked with a supporting runtime.
void UbiXGPBCheckRuntimeVersionSupport(int32_t objcRuntimeVersion);
UbiX_GPB_INLINE void UbiX_GPB_DEBUG_CHECK_RUNTIME_VERSIONS() {
  // NOTE: By being inline here, this captures the value from the library's
  // headers at the time the generated code was compiled.
#if defined(DEBUG) && DEBUG
  UbiXGPBCheckRuntimeVersionSupport(GOOGLE_PROTOBUF_OBJC_VERSION);
#endif
}

// Legacy version of the checks, remove when GOOGLE_PROTOBUF_OBJC_GEN_VERSION
// goes away (see more info in UbiXGPBBootstrap.h).
void UbiXGPBCheckRuntimeVersionInternal(int32_t version);
UbiX_GPB_INLINE void UbiXGPBDebugCheckRuntimeVersion() {
#if defined(DEBUG) && DEBUG
  UbiXGPBCheckRuntimeVersionInternal(GOOGLE_PROTOBUF_OBJC_GEN_VERSION);
#endif
}

// Conversion functions for de/serializing floating point types.

UbiX_GPB_INLINE int64_t UbiXGPBConvertDoubleToInt64(double v) {
  UbiXGPBInternalCompileAssert(sizeof(double) == sizeof(int64_t), double_not_64_bits);
  int64_t result;
  memcpy(&result, &v, sizeof(result));
  return result;
}

UbiX_GPB_INLINE int32_t UbiXGPBConvertFloatToInt32(float v) {
  UbiXGPBInternalCompileAssert(sizeof(float) == sizeof(int32_t), float_not_32_bits);
  int32_t result;
  memcpy(&result, &v, sizeof(result));
  return result;
}

UbiX_GPB_INLINE double UbiXGPBConvertInt64ToDouble(int64_t v) {
  UbiXGPBInternalCompileAssert(sizeof(double) == sizeof(int64_t), double_not_64_bits);
  double result;
  memcpy(&result, &v, sizeof(result));
  return result;
}

UbiX_GPB_INLINE float UbiXGPBConvertInt32ToFloat(int32_t v) {
  UbiXGPBInternalCompileAssert(sizeof(float) == sizeof(int32_t), float_not_32_bits);
  float result;
  memcpy(&result, &v, sizeof(result));
  return result;
}

UbiX_GPB_INLINE int32_t UbiXGPBLogicalRightShift32(int32_t value, int32_t spaces) {
  return (int32_t)((uint32_t)(value) >> spaces);
}

UbiX_GPB_INLINE int64_t UbiXGPBLogicalRightShift64(int64_t value, int32_t spaces) {
  return (int64_t)((uint64_t)(value) >> spaces);
}

// Decode a ZigZag-encoded 32-bit value.  ZigZag encodes signed integers
// into values that can be efficiently encoded with varint.  (Otherwise,
// negative values must be sign-extended to 64 bits to be varint encoded,
// thus always taking 10 bytes on the wire.)
UbiX_GPB_INLINE int32_t UbiXGPBDecodeZigZag32(uint32_t n) {
  return (int32_t)(UbiXGPBLogicalRightShift32((int32_t)n, 1) ^ -((int32_t)(n) & 1));
}

// Decode a ZigZag-encoded 64-bit value.  ZigZag encodes signed integers
// into values that can be efficiently encoded with varint.  (Otherwise,
// negative values must be sign-extended to 64 bits to be varint encoded,
// thus always taking 10 bytes on the wire.)
UbiX_GPB_INLINE int64_t UbiXGPBDecodeZigZag64(uint64_t n) {
  return (int64_t)(UbiXGPBLogicalRightShift64((int64_t)n, 1) ^ -((int64_t)(n) & 1));
}

// Encode a ZigZag-encoded 32-bit value.  ZigZag encodes signed integers
// into values that can be efficiently encoded with varint.  (Otherwise,
// negative values must be sign-extended to 64 bits to be varint encoded,
// thus always taking 10 bytes on the wire.)
UbiX_GPB_INLINE uint32_t UbiXGPBEncodeZigZag32(int32_t n) {
  // Note:  the right-shift must be arithmetic
  return ((uint32_t)n << 1) ^ (uint32_t)(n >> 31);
}

// Encode a ZigZag-encoded 64-bit value.  ZigZag encodes signed integers
// into values that can be efficiently encoded with varint.  (Otherwise,
// negative values must be sign-extended to 64 bits to be varint encoded,
// thus always taking 10 bytes on the wire.)
UbiX_GPB_INLINE uint64_t UbiXGPBEncodeZigZag64(int64_t n) {
  // Note:  the right-shift must be arithmetic
  return ((uint64_t)n << 1) ^ (uint64_t)(n >> 63);
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch-enum"
#pragma clang diagnostic ignored "-Wdirect-ivar-access"

UbiX_GPB_INLINE BOOL UbiXGPBDataTypeIsObject(UbiXGPBDataType type) {
  switch (type) {
    case UbiXGPBDataTypeBytes:
    case UbiXGPBDataTypeString:
    case UbiXGPBDataTypeMessage:
    case UbiXGPBDataTypeGroup:
      return YES;
    default:
      return NO;
  }
}

UbiX_GPB_INLINE BOOL UbiXGPBDataTypeIsMessage(UbiXGPBDataType type) {
  switch (type) {
    case UbiXGPBDataTypeMessage:
    case UbiXGPBDataTypeGroup:
      return YES;
    default:
      return NO;
  }
}

UbiX_GPB_INLINE BOOL UbiXGPBFieldDataTypeIsMessage(UbiXGPBFieldDescriptor *field) {
  return UbiXGPBDataTypeIsMessage(field->description_->dataType);
}

UbiX_GPB_INLINE BOOL UbiXGPBFieldDataTypeIsObject(UbiXGPBFieldDescriptor *field) {
  return UbiXGPBDataTypeIsObject(field->description_->dataType);
}

UbiX_GPB_INLINE BOOL UbiXGPBExtensionIsMessage(UbiXGPBExtensionDescriptor *ext) {
  return UbiXGPBDataTypeIsMessage(ext->description_->dataType);
}

// The field is an array/map or it has an object value.
UbiX_GPB_INLINE BOOL UbiXGPBFieldStoresObject(UbiXGPBFieldDescriptor *field) {
  UbiXGPBMessageFieldDescription *desc = field->description_;
  if ((desc->flags & (UbiXGPBFieldRepeated | UbiXGPBFieldMapKeyMask)) != 0) {
    return YES;
  }
  return UbiXGPBDataTypeIsObject(desc->dataType);
}

BOOL UbiXGPBGetHasIvar(UbiXGPBMessage *self, int32_t index, uint32_t fieldNumber);
void UbiXGPBSetHasIvar(UbiXGPBMessage *self, int32_t idx, uint32_t fieldNumber,
                   BOOL value);
uint32_t UbiXGPBGetHasOneof(UbiXGPBMessage *self, int32_t index);

UbiX_GPB_INLINE BOOL
UbiXGPBGetHasIvarField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field) {
  UbiXGPBMessageFieldDescription *fieldDesc = field->description_;
  return UbiXGPBGetHasIvar(self, fieldDesc->hasIndex, fieldDesc->number);
}

#pragma clang diagnostic pop

//%PDDM-DEFINE UbiX_GPB_IVAR_SET_DECL(NAME, TYPE)
//%void UbiXGPBSet##NAME##IvarWithFieldPrivate(UbiXGPBMessage *self,
//%            NAME$S                    UbiXGPBFieldDescriptor *field,
//%            NAME$S                    TYPE value);
//%PDDM-EXPAND UbiX_GPB_IVAR_SET_DECL(Bool, BOOL)
// This block of code is generated, do not edit it directly.
// clang-format off

void UbiXGPBSetBoolIvarWithFieldPrivate(UbiXGPBMessage *self,
                                    UbiXGPBFieldDescriptor *field,
                                    BOOL value);
// clang-format on
//%PDDM-EXPAND UbiX_GPB_IVAR_SET_DECL(Int32, int32_t)
// This block of code is generated, do not edit it directly.
// clang-format off

void UbiXGPBSetInt32IvarWithFieldPrivate(UbiXGPBMessage *self,
                                     UbiXGPBFieldDescriptor *field,
                                     int32_t value);
// clang-format on
//%PDDM-EXPAND UbiX_GPB_IVAR_SET_DECL(UInt32, uint32_t)
// This block of code is generated, do not edit it directly.
// clang-format off

void UbiXGPBSetUInt32IvarWithFieldPrivate(UbiXGPBMessage *self,
                                      UbiXGPBFieldDescriptor *field,
                                      uint32_t value);
// clang-format on
//%PDDM-EXPAND UbiX_GPB_IVAR_SET_DECL(Int64, int64_t)
// This block of code is generated, do not edit it directly.
// clang-format off

void UbiXGPBSetInt64IvarWithFieldPrivate(UbiXGPBMessage *self,
                                     UbiXGPBFieldDescriptor *field,
                                     int64_t value);
// clang-format on
//%PDDM-EXPAND UbiX_GPB_IVAR_SET_DECL(UInt64, uint64_t)
// This block of code is generated, do not edit it directly.
// clang-format off

void UbiXGPBSetUInt64IvarWithFieldPrivate(UbiXGPBMessage *self,
                                      UbiXGPBFieldDescriptor *field,
                                      uint64_t value);
// clang-format on
//%PDDM-EXPAND UbiX_GPB_IVAR_SET_DECL(Float, float)
// This block of code is generated, do not edit it directly.
// clang-format off

void UbiXGPBSetFloatIvarWithFieldPrivate(UbiXGPBMessage *self,
                                     UbiXGPBFieldDescriptor *field,
                                     float value);
// clang-format on
//%PDDM-EXPAND UbiX_GPB_IVAR_SET_DECL(Double, double)
// This block of code is generated, do not edit it directly.
// clang-format off

void UbiXGPBSetDoubleIvarWithFieldPrivate(UbiXGPBMessage *self,
                                      UbiXGPBFieldDescriptor *field,
                                      double value);
// clang-format on
//%PDDM-EXPAND-END (7 expansions)

void UbiXGPBSetEnumIvarWithFieldPrivate(UbiXGPBMessage *self,
                                    UbiXGPBFieldDescriptor *field,
                                    int32_t value);

id UbiXGPBGetObjectIvarWithField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

void UbiXGPBSetObjectIvarWithFieldPrivate(UbiXGPBMessage *self,
                                      UbiXGPBFieldDescriptor *field, id value);
void UbiXGPBSetRetainedObjectIvarWithFieldPrivate(UbiXGPBMessage *self,
                                              UbiXGPBFieldDescriptor *field,
                                              id __attribute__((ns_consumed))
                                              value);

// UbiXGPBGetObjectIvarWithField will automatically create the field (message) if
// it doesn't exist. UbiXGPBGetObjectIvarWithFieldNoAutocreate will return nil.
id UbiXGPBGetObjectIvarWithFieldNoAutocreate(UbiXGPBMessage *self,
                                         UbiXGPBFieldDescriptor *field);

// Clears and releases the autocreated message ivar, if it's autocreated. If
// it's not set as autocreated, this method does nothing.
void UbiXGPBClearAutocreatedMessageIvarWithField(UbiXGPBMessage *self,
                                             UbiXGPBFieldDescriptor *field);

// Returns an Objective C encoding for |selector|. |instanceSel| should be
// YES if it's an instance selector (as opposed to a class selector).
// |selector| must be a selector from MessageSignatureProtocol.
const char *UbiXGPBMessageEncodingForSelector(SEL selector, BOOL instanceSel);

// Helper for text format name encoding.
// decodeData is the data describing the special decodes.
// key and inputString are the input that needs decoding.
NSString *UbiXGPBDecodeTextFormatName(const uint8_t *decodeData, int32_t key,
                                  NSString *inputString);


// Shims from the older generated code into the runtime.
void UbiXGPBSetInt32IvarWithFieldInternal(UbiXGPBMessage *self,
                                      UbiXGPBFieldDescriptor *field,
                                      int32_t value,
                                      UbiXGPBFileSyntax syntax);
void UbiXGPBMaybeClearOneof(UbiXGPBMessage *self, UbiXGPBOneofDescriptor *oneof,
                        int32_t oneofHasIndex, uint32_t fieldNumberNotToClear);

// A series of selectors that are used solely to get @encoding values
// for them by the dynamic protobuf runtime code. See
// UbiXGPBMessageEncodingForSelector for details. UbiXGPBRootObject conforms to
// the protocol so that it is encoded in the Objective C runtime.
@protocol UbiXGPBMessageSignatureProtocol
@optional

#define UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(TYPE, NAME) \
  -(TYPE)get##NAME;                             \
  -(void)set##NAME : (TYPE)value;               \
  -(TYPE)get##NAME##AtIndex : (NSUInteger)index;

UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(BOOL, Bool)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(uint32_t, Fixed32)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(int32_t, SFixed32)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(float, Float)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(uint64_t, Fixed64)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(int64_t, SFixed64)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(double, Double)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(int32_t, Int32)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(int64_t, Int64)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(int32_t, SInt32)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(int64_t, SInt64)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(uint32_t, UInt32)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(uint64_t, UInt64)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(NSData *, Bytes)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(NSString *, String)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(UbiXGPBMessage *, Message)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(UbiXGPBMessage *, Group)
UbiX_GPB_MESSAGE_SIGNATURE_ENTRY(int32_t, Enum)

#undef UbiX_GPB_MESSAGE_SIGNATURE_ENTRY

- (id)getArray;
- (NSUInteger)getArrayCount;
- (void)setArray:(NSArray *)array;
+ (id)getClassValue;
@end

BOOL UbiXGPBClassHasSel(Class aClass, SEL sel);

CF_EXTERN_C_END
