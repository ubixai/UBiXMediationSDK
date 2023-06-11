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

#import "UbiXGPBArray.h"
#import "UbiXGPBMessage.h"
#import "UbiXGPBRuntimeTypes.h"

@class UbiXGPBOneofDescriptor;

CF_EXTERN_C_BEGIN

NS_ASSUME_NONNULL_BEGIN

/**
 * Generates a string that should be a valid "TextFormat" for the C++ version
 * of Protocol Buffers.
 *
 * @param message    The message to generate from.
 * @param lineIndent A string to use as the prefix for all lines generated. Can
 *                   be nil if no extra indent is needed.
 *
 * @return An NSString with the TextFormat of the message.
 **/
NSString *UbiXGPBTextFormatForMessage(UbiXGPBMessage *message,
                                  NSString * __nullable lineIndent);

/**
 * Generates a string that should be a valid "TextFormat" for the C++ version
 * of Protocol Buffers.
 *
 * @param unknownSet The unknown field set to generate from.
 * @param lineIndent A string to use as the prefix for all lines generated. Can
 *                   be nil if no extra indent is needed.
 *
 * @return An NSString with the TextFormat of the unknown field set.
 **/
NSString *UbiXGPBTextFormatForUnknownFieldSet(UbiXGPBUnknownFieldSet * __nullable unknownSet,
                                          NSString * __nullable lineIndent);

/**
 * Checks if the given field number is set on a message.
 *
 * @param self        The message to check.
 * @param fieldNumber The field number to check.
 *
 * @return YES if the field number is set on the given message.
 **/
BOOL UbiXGPBMessageHasFieldNumberSet(UbiXGPBMessage *self, uint32_t fieldNumber);

/**
 * Checks if the given field is set on a message.
 *
 * @param self  The message to check.
 * @param field The field to check.
 *
 * @return YES if the field is set on the given message.
 **/
BOOL UbiXGPBMessageHasFieldSet(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Clears the given field for the given message.
 *
 * @param self  The message for which to clear the field.
 * @param field The field to clear.
 **/
void UbiXGPBClearMessageField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Clears the given oneof field for the given message.
 *
 * @param self  The message for which to clear the field.
 * @param oneof The oneof to clear.
 **/
void UbiXGPBClearOneof(UbiXGPBMessage *self, UbiXGPBOneofDescriptor *oneof);

//%PDDM-EXPAND UbiX_GPB_ACCESSORS()
// This block of code is generated, do not edit it directly.
// clang-format off


//
// Get/Set a given field from/to a message.
//

// Single Fields

/**
 * Gets the value of a bytes field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
NSData *UbiXGPBGetMessageBytesField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of a bytes field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageBytesField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, NSData *value);

/**
 * Gets the value of a string field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
NSString *UbiXGPBGetMessageStringField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of a string field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageStringField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, NSString *value);

/**
 * Gets the value of a message field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
UbiXGPBMessage *UbiXGPBGetMessageMessageField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of a message field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageMessageField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, UbiXGPBMessage *value);

/**
 * Gets the value of a group field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
UbiXGPBMessage *UbiXGPBGetMessageGroupField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of a group field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageGroupField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, UbiXGPBMessage *value);

/**
 * Gets the value of a bool field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
BOOL UbiXGPBGetMessageBoolField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of a bool field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageBoolField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, BOOL value);

/**
 * Gets the value of an int32 field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
int32_t UbiXGPBGetMessageInt32Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of an int32 field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageInt32Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, int32_t value);

/**
 * Gets the value of an uint32 field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
uint32_t UbiXGPBGetMessageUInt32Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of an uint32 field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageUInt32Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, uint32_t value);

/**
 * Gets the value of an int64 field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
int64_t UbiXGPBGetMessageInt64Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of an int64 field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageInt64Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, int64_t value);

/**
 * Gets the value of an uint64 field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
uint64_t UbiXGPBGetMessageUInt64Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of an uint64 field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageUInt64Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, uint64_t value);

/**
 * Gets the value of a float field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
float UbiXGPBGetMessageFloatField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of a float field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageFloatField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, float value);

/**
 * Gets the value of a double field.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 **/
double UbiXGPBGetMessageDoubleField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of a double field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The to set in the field.
 **/
void UbiXGPBSetMessageDoubleField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, double value);

/**
 * Gets the given enum field of a message. For proto3, if the value isn't a
 * member of the enum, @c kGPBUnrecognizedEnumeratorValue will be returned.
 * UbiXGPBGetMessageRawEnumField will bypass the check and return whatever value
 * was set.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 *
 * @return The enum value for the given field.
 **/
int32_t UbiXGPBGetMessageEnumField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Set the given enum field of a message. You can only set values that are
 * members of the enum.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The enum value to set in the field.
 **/
void UbiXGPBSetMessageEnumField(UbiXGPBMessage *self,
                            UbiXGPBFieldDescriptor *field,
                            int32_t value);

/**
 * Get the given enum field of a message. No check is done to ensure the value
 * was defined in the enum.
 *
 * @param self  The message from which to get the field.
 * @param field The field to get.
 *
 * @return The raw enum value for the given field.
 **/
int32_t UbiXGPBGetMessageRawEnumField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Set the given enum field of a message. You can set the value to anything,
 * even a value that is not a member of the enum.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param value The raw enum value to set in the field.
 **/
void UbiXGPBSetMessageRawEnumField(UbiXGPBMessage *self,
                               UbiXGPBFieldDescriptor *field,
                               int32_t value);

// Repeated Fields

/**
 * Gets the value of a repeated field.
 *
 * @param self  The message from which to get the field.
 * @param field The repeated field to get.
 *
 * @return A UbiXGPB*Array or an NSMutableArray based on the field's type.
 **/
id UbiXGPBGetMessageRepeatedField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of a repeated field.
 *
 * @param self  The message into which to set the field.
 * @param field The field to set.
 * @param array A UbiXGPB*Array or NSMutableArray based on the field's type.
 **/
void UbiXGPBSetMessageRepeatedField(UbiXGPBMessage *self,
                                UbiXGPBFieldDescriptor *field,
                                id array);

// Map Fields

/**
 * Gets the value of a map<> field.
 *
 * @param self  The message from which to get the field.
 * @param field The repeated field to get.
 *
 * @return A UbiXGPB*Dictionary or NSMutableDictionary based on the field's type.
 **/
id UbiXGPBGetMessageMapField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);

/**
 * Sets the value of a map<> field.
 *
 * @param self       The message into which to set the field.
 * @param field      The field to set.
 * @param dictionary A UbiXGPB*Dictionary or NSMutableDictionary based on the
 *                   field's type.
 **/
void UbiXGPBSetMessageMapField(UbiXGPBMessage *self,
                           UbiXGPBFieldDescriptor *field,
                           id dictionary);

// clang-format on
//%PDDM-EXPAND-END UbiX_GPB_ACCESSORS()

/**
 * Returns an empty NSData to assign to byte fields when you wish to assign them
 * to empty. Prevents allocating a lot of little [NSData data] objects.
 **/
NSData *UbiXGPBEmptyNSData(void) __attribute__((pure));

/**
 * Drops the `unknownFields` from the given message and from all sub message.
 **/
void UbiXGPBMessageDropUnknownFieldsRecursively(UbiXGPBMessage *message);

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END


//%PDDM-DEFINE UbiX_GPB_ACCESSORS()
//%
//%//
//%// Get/Set a given field from/to a message.
//%//
//%
//%// Single Fields
//%
//%UbiX_GPB_ACCESSOR_SINGLE_FULL(Bytes, NSData, , *)
//%UbiX_GPB_ACCESSOR_SINGLE_FULL(String, NSString, , *)
//%UbiX_GPB_ACCESSOR_SINGLE_FULL(Message, UbiXGPBMessage, , *)
//%UbiX_GPB_ACCESSOR_SINGLE_FULL(Group, UbiXGPBMessage, , *)
//%UbiX_GPB_ACCESSOR_SINGLE(Bool, BOOL, )
//%UbiX_GPB_ACCESSOR_SINGLE(Int32, int32_t, n)
//%UbiX_GPB_ACCESSOR_SINGLE(UInt32, uint32_t, n)
//%UbiX_GPB_ACCESSOR_SINGLE(Int64, int64_t, n)
//%UbiX_GPB_ACCESSOR_SINGLE(UInt64, uint64_t, n)
//%UbiX_GPB_ACCESSOR_SINGLE(Float, float, )
//%UbiX_GPB_ACCESSOR_SINGLE(Double, double, )
//%/**
//% * Gets the given enum field of a message. For proto3, if the value isn't a
//% * member of the enum, @c kGPBUnrecognizedEnumeratorValue will be returned.
//% * UbiXGPBGetMessageRawEnumField will bypass the check and return whatever value
//% * was set.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The field to get.
//% *
//% * @return The enum value for the given field.
//% **/
//%int32_t UbiXGPBGetMessageEnumField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);
//%
//%/**
//% * Set the given enum field of a message. You can only set values that are
//% * members of the enum.
//% *
//% * @param self  The message into which to set the field.
//% * @param field The field to set.
//% * @param value The enum value to set in the field.
//% **/
//%void UbiXGPBSetMessageEnumField(UbiXGPBMessage *self,
//%                            UbiXGPBFieldDescriptor *field,
//%                            int32_t value);
//%
//%/**
//% * Get the given enum field of a message. No check is done to ensure the value
//% * was defined in the enum.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The field to get.
//% *
//% * @return The raw enum value for the given field.
//% **/
//%int32_t UbiXGPBGetMessageRawEnumField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);
//%
//%/**
//% * Set the given enum field of a message. You can set the value to anything,
//% * even a value that is not a member of the enum.
//% *
//% * @param self  The message into which to set the field.
//% * @param field The field to set.
//% * @param value The raw enum value to set in the field.
//% **/
//%void UbiXGPBSetMessageRawEnumField(UbiXGPBMessage *self,
//%                               UbiXGPBFieldDescriptor *field,
//%                               int32_t value);
//%
//%// Repeated Fields
//%
//%/**
//% * Gets the value of a repeated field.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The repeated field to get.
//% *
//% * @return A UbiXGPB*Array or an NSMutableArray based on the field's type.
//% **/
//%id UbiXGPBGetMessageRepeatedField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);
//%
//%/**
//% * Sets the value of a repeated field.
//% *
//% * @param self  The message into which to set the field.
//% * @param field The field to set.
//% * @param array A UbiXGPB*Array or NSMutableArray based on the field's type.
//% **/
//%void UbiXGPBSetMessageRepeatedField(UbiXGPBMessage *self,
//%                                UbiXGPBFieldDescriptor *field,
//%                                id array);
//%
//%// Map Fields
//%
//%/**
//% * Gets the value of a map<> field.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The repeated field to get.
//% *
//% * @return A UbiXGPB*Dictionary or NSMutableDictionary based on the field's type.
//% **/
//%id UbiXGPBGetMessageMapField(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);
//%
//%/**
//% * Sets the value of a map<> field.
//% *
//% * @param self       The message into which to set the field.
//% * @param field      The field to set.
//% * @param dictionary A UbiXGPB*Dictionary or NSMutableDictionary based on the
//% *                   field's type.
//% **/
//%void UbiXGPBSetMessageMapField(UbiXGPBMessage *self,
//%                           UbiXGPBFieldDescriptor *field,
//%                           id dictionary);
//%

//%PDDM-DEFINE UbiX_GPB_ACCESSOR_SINGLE(NAME, TYPE, AN)
//%UbiX_GPB_ACCESSOR_SINGLE_FULL(NAME, TYPE, AN, )
//%PDDM-DEFINE UbiX_GPB_ACCESSOR_SINGLE_FULL(NAME, TYPE, AN, TisP)
//%/**
//% * Gets the value of a##AN NAME$L field.
//% *
//% * @param self  The message from which to get the field.
//% * @param field The field to get.
//% **/
//%TYPE TisP##UbiXGPBGetMessage##NAME##Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field);
//%
//%/**
//% * Sets the value of a##AN NAME$L field.
//% *
//% * @param self  The message into which to set the field.
//% * @param field The field to set.
//% * @param value The to set in the field.
//% **/
//%void UbiXGPBSetMessage##NAME##Field(UbiXGPBMessage *self, UbiXGPBFieldDescriptor *field, TYPE TisP##value);
//%
