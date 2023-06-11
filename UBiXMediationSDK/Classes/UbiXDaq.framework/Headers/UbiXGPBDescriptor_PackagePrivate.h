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

// This header is private to the ProtobolBuffers library and must NOT be
// included by any sources outside this library. The contents of this file are
// subject to change at any time without notice.

#import "UbiXGPBDescriptor.h"
#import "UbiXGPBWireFormat.h"

// Describes attributes of the field.
typedef NS_OPTIONS(uint16_t, UbiXGPBFieldFlags) {
  UbiXGPBFieldNone            = 0,
  // These map to standard protobuf concepts.
  UbiXGPBFieldRequired        = 1 << 0,
  UbiXGPBFieldRepeated        = 1 << 1,
  UbiXGPBFieldPacked          = 1 << 2,
  UbiXGPBFieldOptional        = 1 << 3,
  UbiXGPBFieldHasDefaultValue = 1 << 4,

  // Indicate that the field should "clear" when set to zero value. This is the
  // proto3 non optional behavior for singular data (ints, data, string, enum)
  // fields.
  UbiXGPBFieldClearHasIvarOnZero = 1 << 5,
  // Indicates the field needs custom handling for the TextFormat name, if not
  // set, the name can be derived from the ObjC name.
  UbiXGPBFieldTextFormatNameCustom = 1 << 6,
  // Indicates the field has an enum descriptor.
  UbiXGPBFieldHasEnumDescriptor = 1 << 7,

  // These are not standard protobuf concepts, they are specific to the
  // Objective C runtime.

  // These bits are used to mark the field as a map and what the key
  // type is.
  UbiXGPBFieldMapKeyMask     = 0xF << 8,
  UbiXGPBFieldMapKeyInt32    =  1 << 8,
  UbiXGPBFieldMapKeyInt64    =  2 << 8,
  UbiXGPBFieldMapKeyUInt32   =  3 << 8,
  UbiXGPBFieldMapKeyUInt64   =  4 << 8,
  UbiXGPBFieldMapKeySInt32   =  5 << 8,
  UbiXGPBFieldMapKeySInt64   =  6 << 8,
  UbiXGPBFieldMapKeyFixed32  =  7 << 8,
  UbiXGPBFieldMapKeyFixed64  =  8 << 8,
  UbiXGPBFieldMapKeySFixed32 =  9 << 8,
  UbiXGPBFieldMapKeySFixed64 = 10 << 8,
  UbiXGPBFieldMapKeyBool     = 11 << 8,
  UbiXGPBFieldMapKeyString   = 12 << 8,
};

// NOTE: The structures defined here have their members ordered to minimize
// their size. This directly impacts the size of apps since these exist per
// field/extension.

// Describes a single field in a protobuf as it is represented as an ivar.
typedef struct UbiXGPBMessageFieldDescription {
  // Name of ivar.
  const char *name;
  union {
    // className is deprecated and will be removed in favor of clazz.
    // kept around right now for backwards compatibility.
    // clazz is used iff UbiXGPBDescriptorInitializationFlag_UsesClassRefs is set.
    char *className;  // Name of the class of the message.
    Class clazz;  // Class of the message.
    // For enums only: If EnumDescriptors are compiled in, it will be that,
    // otherwise it will be the verifier.
    UbiXGPBEnumDescriptorFunc enumDescFunc;
    UbiXGPBEnumValidationFunc enumVerifier;
  } dataTypeSpecific;
  // The field number for the ivar.
  uint32_t number;
  // The index (in bits) into _has_storage_.
  //   >= 0: the bit to use for a value being set.
  //   = UbiXGPBNoHasBit(INT32_MAX): no storage used.
  //   < 0: in a oneOf, use a full int32 to record the field active.
  int32_t hasIndex;
  // Offset of the variable into it's structure struct.
  uint32_t offset;
  // Field flags. Use accessor functions below.
  UbiXGPBFieldFlags flags;
  // Data type of the ivar.
  UbiXGPBDataType dataType;
} UbiXGPBMessageFieldDescription;

// Fields in messages defined in a 'proto2' syntax file can provide a default
// value. This struct provides the default along with the field info.
typedef struct UbiXGPBMessageFieldDescriptionWithDefault {
  // Default value for the ivar.
  UbiXGPBGenericValue defaultValue;

  UbiXGPBMessageFieldDescription core;
} UbiXGPBMessageFieldDescriptionWithDefault;

// Describes attributes of the extension.
typedef NS_OPTIONS(uint8_t, UbiXGPBExtensionOptions) {
  UbiXGPBExtensionNone          = 0,
  // These map to standard protobuf concepts.
  UbiXGPBExtensionRepeated      = 1 << 0,
  UbiXGPBExtensionPacked        = 1 << 1,
  UbiXGPBExtensionSetWireFormat = 1 << 2,
};

// An extension
typedef struct UbiXGPBExtensionDescription {
  UbiXGPBGenericValue defaultValue;
  const char *singletonName;
  // Before 3.12, `extendedClass` was just a `const char *`. Thanks to nested
  // initialization (https://en.cppreference.com/w/c/language/struct_initialization#Nested_initialization)
  // old generated code with `.extendedClass = UbiXGPBStringifySymbol(Something)`
  // still works; and the current generator can use `extendedClass.clazz`, to
  // pass a Class reference.
  union {
    const char *name;
    Class clazz;
  } extendedClass;
  // Before 3.12, this was `const char *messageOrGroupClassName`. In the
  // initial 3.12 release, we moved the `union messageOrGroupClass`, and failed
  // to realize that would break existing source code for extensions. So to
  // keep existing source code working, we added an unnamed union (C11) to
  // provide both the old field name and the new union. This keeps both older
  // and newer code working.
  // Background: https://github.com/protocolbuffers/protobuf/issues/7555
  union {
    const char *messageOrGroupClassName;
    union {
     const char *name;
     Class clazz;
   } messageOrGroupClass;
  };
  UbiXGPBEnumDescriptorFunc enumDescriptorFunc;
  int32_t fieldNumber;
  UbiXGPBDataType dataType;
  UbiXGPBExtensionOptions options;
} UbiXGPBExtensionDescription;

typedef NS_OPTIONS(uint32_t, UbiXGPBDescriptorInitializationFlags) {
  UbiXGPBDescriptorInitializationFlag_None              = 0,
  UbiXGPBDescriptorInitializationFlag_FieldsWithDefault = 1 << 0,
  UbiXGPBDescriptorInitializationFlag_WireFormat        = 1 << 1,

  // This is used as a stopgap as we move from using class names to class
  // references. The runtime needs to support both until we allow a
  // breaking change in the runtime.
  UbiXGPBDescriptorInitializationFlag_UsesClassRefs     = 1 << 2,

  // This flag is used to indicate that the generated sources already contain
  // the `UbiXGPBFieldClearHasIvarOnZero` flag and it doesn't have to be computed
  // at startup. This allows older generated code to still work with the
  // current runtime library.
  UbiXGPBDescriptorInitializationFlag_Proto3OptionalKnown = 1 << 3,
};

@interface UbiXGPBDescriptor () {
 @package
  NSArray *fields_;
  NSArray *oneofs_;
  uint32_t storageSize_;
}

// fieldDescriptions have to be long lived, they are held as raw pointers.
+ (instancetype)
    allocDescriptorForClass:(Class)messageClass
                  rootClass:(Class)rootClass
                       file:(UbiXGPBFileDescriptor *)file
                     fields:(void *)fieldDescriptions
                 fieldCount:(uint32_t)fieldCount
                storageSize:(uint32_t)storageSize
                      flags:(UbiXGPBDescriptorInitializationFlags)flags;

- (instancetype)initWithClass:(Class)messageClass
                         file:(UbiXGPBFileDescriptor *)file
                       fields:(NSArray *)fields
                  storageSize:(uint32_t)storage
                   wireFormat:(BOOL)wireFormat;

// Called right after init to provide extra information to avoid init having
// an explosion of args. These pointers are recorded, so they are expected
// to live for the lifetime of the app.
- (void)setupOneofs:(const char **)oneofNames
              count:(uint32_t)count
      firstHasIndex:(int32_t)firstHasIndex;
- (void)setupExtraTextInfo:(const char *)extraTextFormatInfo;
- (void)setupExtensionRanges:(const UbiXGPBExtensionRange *)ranges count:(int32_t)count;
- (void)setupContainingMessageClass:(Class)msgClass;
- (void)setupMessageClassNameSuffix:(NSString *)suffix;

// Deprecated. Use setupContainingMessageClass instead.
- (void)setupContainingMessageClassName:(const char *)msgClassName;

@end

@interface UbiXGPBFileDescriptor ()
- (instancetype)initWithPackage:(NSString *)package
                     objcPrefix:(NSString *)objcPrefix
                         syntax:(UbiXGPBFileSyntax)syntax;
- (instancetype)initWithPackage:(NSString *)package
                         syntax:(UbiXGPBFileSyntax)syntax;
@end

@interface UbiXGPBOneofDescriptor () {
 @package
  const char *name_;
  NSArray *fields_;
  SEL caseSel_;
}
// name must be long lived.
- (instancetype)initWithName:(const char *)name fields:(NSArray *)fields;
@end

@interface UbiXGPBFieldDescriptor () {
 @package
  UbiXGPBMessageFieldDescription *description_;
  UbiX_GPB_UNSAFE_UNRETAINED UbiXGPBOneofDescriptor *containingOneof_;

  SEL getSel_;
  SEL setSel_;
  SEL hasOrCountSel_;  // *Count for map<>/repeated fields, has* otherwise.
  SEL setHasSel_;
}

// Single initializer
// description has to be long lived, it is held as a raw pointer.
- (instancetype)initWithFieldDescription:(void *)description
                         includesDefault:(BOOL)includesDefault
                           usesClassRefs:(BOOL)usesClassRefs
                     proto3OptionalKnown:(BOOL)proto3OptionalKnown
                                  syntax:(UbiXGPBFileSyntax)syntax;

@end

@interface UbiXGPBEnumDescriptor ()
// valueNames, values and extraTextFormatInfo have to be long lived, they are
// held as raw pointers.
+ (instancetype)
    allocDescriptorForName:(NSString *)name
                valueNames:(const char *)valueNames
                    values:(const int32_t *)values
                     count:(uint32_t)valueCount
              enumVerifier:(UbiXGPBEnumValidationFunc)enumVerifier;
+ (instancetype)
    allocDescriptorForName:(NSString *)name
                valueNames:(const char *)valueNames
                    values:(const int32_t *)values
                     count:(uint32_t)valueCount
              enumVerifier:(UbiXGPBEnumValidationFunc)enumVerifier
       extraTextFormatInfo:(const char *)extraTextFormatInfo;

- (instancetype)initWithName:(NSString *)name
                  valueNames:(const char *)valueNames
                      values:(const int32_t *)values
                       count:(uint32_t)valueCount
                enumVerifier:(UbiXGPBEnumValidationFunc)enumVerifier;
@end

@interface UbiXGPBExtensionDescriptor () {
 @package
  UbiXGPBExtensionDescription *description_;
}
@property(nonatomic, readonly) UbiXGPBWireFormat wireType;

// For repeated extensions, alternateWireType is the wireType with the opposite
// value for the packable property.  i.e. - if the extension was marked packed
// it would be the wire type for unpacked; if the extension was marked unpacked,
// it would be the wire type for packed.
@property(nonatomic, readonly) UbiXGPBWireFormat alternateWireType;

// description has to be long lived, it is held as a raw pointer.
- (instancetype)initWithExtensionDescription:(UbiXGPBExtensionDescription *)desc
                               usesClassRefs:(BOOL)usesClassRefs;
// Deprecated. Calls above with `usesClassRefs = NO`
- (instancetype)initWithExtensionDescription:(UbiXGPBExtensionDescription *)desc;

- (NSComparisonResult)compareByFieldNumber:(UbiXGPBExtensionDescriptor *)other;
@end

CF_EXTERN_C_BEGIN

// Direct access is use for speed, to avoid even internally declaring things
// read/write, etc. The warning is enabled in the project to ensure code calling
// protos can turn on -Wdirect-ivar-access without issues.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdirect-ivar-access"

UbiX_GPB_INLINE BOOL UbiXGPBFieldIsMapOrArray(UbiXGPBFieldDescriptor *field) {
  return (field->description_->flags &
          (UbiXGPBFieldRepeated | UbiXGPBFieldMapKeyMask)) != 0;
}

UbiX_GPB_INLINE UbiXGPBDataType UbiXGPBGetFieldDataType(UbiXGPBFieldDescriptor *field) {
  return field->description_->dataType;
}

UbiX_GPB_INLINE int32_t UbiXGPBFieldHasIndex(UbiXGPBFieldDescriptor *field) {
  return field->description_->hasIndex;
}

UbiX_GPB_INLINE uint32_t UbiXGPBFieldNumber(UbiXGPBFieldDescriptor *field) {
  return field->description_->number;
}

#pragma clang diagnostic pop

uint32_t UbiXGPBFieldTag(UbiXGPBFieldDescriptor *self);

// For repeated fields, alternateWireType is the wireType with the opposite
// value for the packable property.  i.e. - if the field was marked packed it
// would be the wire type for unpacked; if the field was marked unpacked, it
// would be the wire type for packed.
uint32_t UbiXGPBFieldAlternateTag(UbiXGPBFieldDescriptor *self);

UbiX_GPB_INLINE BOOL UbiXGPBHasPreservingUnknownEnumSemantics(UbiXGPBFileSyntax syntax) {
  return syntax == UbiXGPBFileSyntaxProto3;
}

UbiX_GPB_INLINE BOOL UbiXGPBExtensionIsRepeated(UbiXGPBExtensionDescription *description) {
  return (description->options & UbiXGPBExtensionRepeated) != 0;
}

UbiX_GPB_INLINE BOOL UbiXGPBExtensionIsPacked(UbiXGPBExtensionDescription *description) {
  return (description->options & UbiXGPBExtensionPacked) != 0;
}

UbiX_GPB_INLINE BOOL UbiXGPBExtensionIsWireFormat(UbiXGPBExtensionDescription *description) {
  return (description->options & UbiXGPBExtensionSetWireFormat) != 0;
}

// Helper for compile time assets.
#ifndef UbiXGPBInternalCompileAssert
  #if __has_feature(c_static_assert) || __has_extension(c_static_assert)
    #define UbiXGPBInternalCompileAssert(test, msg) _Static_assert((test), #msg)
  #else
    // Pre-Xcode 7 support.
    #define UbiXGPBInternalCompileAssertSymbolInner(line, msg) UbiXGPBInternalCompileAssert ## line ## __ ## msg
    #define UbiXGPBInternalCompileAssertSymbol(line, msg) UbiXGPBInternalCompileAssertSymbolInner(line, msg)
    #define UbiXGPBInternalCompileAssert(test, msg) \
        typedef char UbiXGPBInternalCompileAssertSymbol(__LINE__, msg) [ ((test) ? 1 : -1) ]
  #endif  // __has_feature(c_static_assert) || __has_extension(c_static_assert)
#endif // UbiXGPBInternalCompileAssert

// Sanity check that there isn't padding between the field description
// structures with and without a default.
UbiXGPBInternalCompileAssert(sizeof(UbiXGPBMessageFieldDescriptionWithDefault) ==
                         (sizeof(UbiXGPBGenericValue) +
                          sizeof(UbiXGPBMessageFieldDescription)),
                         DescriptionsWithDefault_different_size_than_expected);

CF_EXTERN_C_END
