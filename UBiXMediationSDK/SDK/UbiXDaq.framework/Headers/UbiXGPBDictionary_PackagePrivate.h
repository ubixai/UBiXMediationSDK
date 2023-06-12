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

#import "UbiXGPBDictionary.h"

@class UbiXGPBCodedInputStream;
@class UbiXGPBCodedOutputStream;
@class UbiXGPBExtensionRegistry;
@class UbiXGPBFieldDescriptor;

@protocol UbiXGPBDictionaryInternalsProtocol
- (size_t)computeSerializedSizeAsField:(UbiXGPBFieldDescriptor *)field;
- (void)writeToCodedOutputStream:(UbiXGPBCodedOutputStream *)outputStream
                         asField:(UbiXGPBFieldDescriptor *)field;
- (void)setGPBGenericValue:(UbiXGPBGenericValue *)value
     forGPBGenericValueKey:(UbiXGPBGenericValue *)key;
- (void)enumerateForTextFormat:(void (^)(id keyObj, id valueObj))block;
@end

//%PDDM-DEFINE DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(KEY_NAME)
//%DICTIONARY_POD_PRIV_INTERFACES_FOR_KEY(KEY_NAME)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Object, Object)
//%PDDM-DEFINE DICTIONARY_POD_PRIV_INTERFACES_FOR_KEY(KEY_NAME)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, UInt32, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Int32, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, UInt64, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Int64, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Bool, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Float, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Double, Basic)
//%DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, Enum, Enum)

//%PDDM-DEFINE DICTIONARY_PRIVATE_INTERFACES(KEY_NAME, VALUE_NAME, HELPER)
//%@interface UbiXGPB##KEY_NAME##VALUE_NAME##Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
//% @package
//%  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
//%}
//%EXTRA_DICTIONARY_PRIVATE_INTERFACES_##HELPER()@end
//%

//%PDDM-DEFINE EXTRA_DICTIONARY_PRIVATE_INTERFACES_Basic()
// Empty
//%PDDM-DEFINE EXTRA_DICTIONARY_PRIVATE_INTERFACES_Object()
//%- (BOOL)isInitialized;
//%- (instancetype)deepCopyWithZone:(NSZone *)zone
//%    __attribute__((ns_returns_retained));
//%
//%PDDM-DEFINE EXTRA_DICTIONARY_PRIVATE_INTERFACES_Enum()
//%- (NSData *)serializedDataForUnknownValue:(int32_t)value
//%                                   forKey:(UbiXGPBGenericValue *)key
//%                              keyDataType:(UbiXGPBDataType)keyDataType;
//%

//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(UInt32)
// This block of code is generated, do not edit it directly.
// clang-format off

@interface UbiXGPBUInt32UInt32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt32Int32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt32UInt64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt32Int64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt32BoolDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt32FloatDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt32DoubleDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt32EnumDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(UbiXGPBGenericValue *)key
                              keyDataType:(UbiXGPBDataType)keyDataType;
@end

@interface UbiXGPBUInt32ObjectDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

// clang-format on
//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(Int32)
// This block of code is generated, do not edit it directly.
// clang-format off

@interface UbiXGPBInt32UInt32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt32Int32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt32UInt64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt32Int64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt32BoolDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt32FloatDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt32DoubleDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt32EnumDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(UbiXGPBGenericValue *)key
                              keyDataType:(UbiXGPBDataType)keyDataType;
@end

@interface UbiXGPBInt32ObjectDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

// clang-format on
//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(UInt64)
// This block of code is generated, do not edit it directly.
// clang-format off

@interface UbiXGPBUInt64UInt32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt64Int32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt64UInt64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt64Int64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt64BoolDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt64FloatDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt64DoubleDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBUInt64EnumDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(UbiXGPBGenericValue *)key
                              keyDataType:(UbiXGPBDataType)keyDataType;
@end

@interface UbiXGPBUInt64ObjectDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

// clang-format on
//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(Int64)
// This block of code is generated, do not edit it directly.
// clang-format off

@interface UbiXGPBInt64UInt32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt64Int32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt64UInt64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt64Int64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt64BoolDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt64FloatDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt64DoubleDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBInt64EnumDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(UbiXGPBGenericValue *)key
                              keyDataType:(UbiXGPBDataType)keyDataType;
@end

@interface UbiXGPBInt64ObjectDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

// clang-format on
//%PDDM-EXPAND DICTIONARY_PRIV_INTERFACES_FOR_POD_KEY(Bool)
// This block of code is generated, do not edit it directly.
// clang-format off

@interface UbiXGPBBoolUInt32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBBoolInt32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBBoolUInt64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBBoolInt64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBBoolBoolDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBBoolFloatDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBBoolDoubleDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBBoolEnumDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(UbiXGPBGenericValue *)key
                              keyDataType:(UbiXGPBDataType)keyDataType;
@end

@interface UbiXGPBBoolObjectDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (BOOL)isInitialized;
- (instancetype)deepCopyWithZone:(NSZone *)zone
    __attribute__((ns_returns_retained));
@end

// clang-format on
//%PDDM-EXPAND DICTIONARY_POD_PRIV_INTERFACES_FOR_KEY(String)
// This block of code is generated, do not edit it directly.
// clang-format off

@interface UbiXGPBStringUInt32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBStringInt32Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBStringUInt64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBStringInt64Dictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBStringBoolDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBStringFloatDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBStringDoubleDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

@interface UbiXGPBStringEnumDictionary () <UbiXGPBDictionaryInternalsProtocol> {
 @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
- (NSData *)serializedDataForUnknownValue:(int32_t)value
                                   forKey:(UbiXGPBGenericValue *)key
                              keyDataType:(UbiXGPBDataType)keyDataType;
@end

// clang-format on
//%PDDM-EXPAND-END (6 expansions)

#pragma mark - NSDictionary Subclass

@interface UbiXGPBAutocreatedDictionary : NSMutableDictionary {
  @package
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBMessage *_autocreator;
}
@end

#pragma mark - Helpers

CF_EXTERN_C_BEGIN

// Helper to compute size when an NSDictionary is used for the map instead
// of a custom type.
size_t UbiXGPBDictionaryComputeSizeInternalHelper(NSDictionary *dict,
                                              UbiXGPBFieldDescriptor *field);

// Helper to write out when an NSDictionary is used for the map instead
// of a custom type.
void UbiXGPBDictionaryWriteToStreamInternalHelper(
    UbiXGPBCodedOutputStream *outputStream, NSDictionary *dict,
    UbiXGPBFieldDescriptor *field);

// Helper to check message initialization when an NSDictionary is used for
// the map instead of a custom type.
BOOL UbiXGPBDictionaryIsInitializedInternalHelper(NSDictionary *dict,
                                              UbiXGPBFieldDescriptor *field);

// Helper to read a map instead.
void UbiXGPBDictionaryReadEntry(id mapDictionary, UbiXGPBCodedInputStream *stream,
                            UbiXGPBExtensionRegistry *registry,
                            UbiXGPBFieldDescriptor *field,
                            UbiXGPBMessage *parentMessage);

CF_EXTERN_C_END
