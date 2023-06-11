// Protocol Buffers - Google's data interchange format
// Copyright 2016 Google Inc.  All rights reserved.
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

#import "UbiXGPBCodedOutputStream.h"

NS_ASSUME_NONNULL_BEGIN

CF_EXTERN_C_BEGIN

size_t UbiXGPBComputeDoubleSize(int32_t fieldNumber, double value)
    __attribute__((const));
size_t UbiXGPBComputeFloatSize(int32_t fieldNumber, float value)
    __attribute__((const));
size_t UbiXGPBComputeUInt64Size(int32_t fieldNumber, uint64_t value)
    __attribute__((const));
size_t UbiXGPBComputeInt64Size(int32_t fieldNumber, int64_t value)
    __attribute__((const));
size_t UbiXGPBComputeInt32Size(int32_t fieldNumber, int32_t value)
    __attribute__((const));
size_t UbiXGPBComputeFixed64Size(int32_t fieldNumber, uint64_t value)
    __attribute__((const));
size_t UbiXGPBComputeFixed32Size(int32_t fieldNumber, uint32_t value)
    __attribute__((const));
size_t UbiXGPBComputeBoolSize(int32_t fieldNumber, BOOL value)
    __attribute__((const));
size_t UbiXGPBComputeStringSize(int32_t fieldNumber, NSString *value)
    __attribute__((const));
size_t UbiXGPBComputeGroupSize(int32_t fieldNumber, UbiXGPBMessage *value)
    __attribute__((const));
size_t UbiXGPBComputeUnknownGroupSize(int32_t fieldNumber,
                                  UbiXGPBUnknownFieldSet *value)
    __attribute__((const));
size_t UbiXGPBComputeMessageSize(int32_t fieldNumber, UbiXGPBMessage *value)
    __attribute__((const));
size_t UbiXGPBComputeBytesSize(int32_t fieldNumber, NSData *value)
    __attribute__((const));
size_t UbiXGPBComputeUInt32Size(int32_t fieldNumber, uint32_t value)
    __attribute__((const));
size_t UbiXGPBComputeSFixed32Size(int32_t fieldNumber, int32_t value)
    __attribute__((const));
size_t UbiXGPBComputeSFixed64Size(int32_t fieldNumber, int64_t value)
    __attribute__((const));
size_t UbiXGPBComputeSInt32Size(int32_t fieldNumber, int32_t value)
    __attribute__((const));
size_t UbiXGPBComputeSInt64Size(int32_t fieldNumber, int64_t value)
    __attribute__((const));
size_t UbiXGPBComputeTagSize(int32_t fieldNumber) __attribute__((const));
size_t UbiXGPBComputeWireFormatTagSize(int field_number, UbiXGPBDataType dataType)
    __attribute__((const));

size_t UbiXGPBComputeDoubleSizeNoTag(double value) __attribute__((const));
size_t UbiXGPBComputeFloatSizeNoTag(float value) __attribute__((const));
size_t UbiXGPBComputeUInt64SizeNoTag(uint64_t value) __attribute__((const));
size_t UbiXGPBComputeInt64SizeNoTag(int64_t value) __attribute__((const));
size_t UbiXGPBComputeInt32SizeNoTag(int32_t value) __attribute__((const));
size_t UbiXGPBComputeFixed64SizeNoTag(uint64_t value) __attribute__((const));
size_t UbiXGPBComputeFixed32SizeNoTag(uint32_t value) __attribute__((const));
size_t UbiXGPBComputeBoolSizeNoTag(BOOL value) __attribute__((const));
size_t UbiXGPBComputeStringSizeNoTag(NSString *value) __attribute__((const));
size_t UbiXGPBComputeGroupSizeNoTag(UbiXGPBMessage *value) __attribute__((const));
size_t UbiXGPBComputeUnknownGroupSizeNoTag(UbiXGPBUnknownFieldSet *value)
    __attribute__((const));
size_t UbiXGPBComputeMessageSizeNoTag(UbiXGPBMessage *value) __attribute__((const));
size_t UbiXGPBComputeBytesSizeNoTag(NSData *value) __attribute__((const));
size_t UbiXGPBComputeUInt32SizeNoTag(int32_t value) __attribute__((const));
size_t UbiXGPBComputeEnumSizeNoTag(int32_t value) __attribute__((const));
size_t UbiXGPBComputeSFixed32SizeNoTag(int32_t value) __attribute__((const));
size_t UbiXGPBComputeSFixed64SizeNoTag(int64_t value) __attribute__((const));
size_t UbiXGPBComputeSInt32SizeNoTag(int32_t value) __attribute__((const));
size_t UbiXGPBComputeSInt64SizeNoTag(int64_t value) __attribute__((const));

// Note that this will calculate the size of 64 bit values truncated to 32.
size_t UbiXGPBComputeSizeTSizeAsInt32NoTag(size_t value) __attribute__((const));

size_t UbiXGPBComputeRawVarint32Size(int32_t value) __attribute__((const));
size_t UbiXGPBComputeRawVarint64Size(int64_t value) __attribute__((const));

// Note that this will calculate the size of 64 bit values truncated to 32.
size_t UbiXGPBComputeRawVarint32SizeForInteger(NSInteger value)
    __attribute__((const));

// Compute the number of bytes that would be needed to encode a
// MessageSet extension to the stream.  For historical reasons,
// the wire format differs from normal fields.
size_t UbiXGPBComputeMessageSetExtensionSize(int32_t fieldNumber, UbiXGPBMessage *value)
    __attribute__((const));

// Compute the number of bytes that would be needed to encode an
// unparsed MessageSet extension field to the stream.  For
// historical reasons, the wire format differs from normal fields.
size_t UbiXGPBComputeRawMessageSetExtensionSize(int32_t fieldNumber, NSData *value)
    __attribute__((const));

size_t UbiXGPBComputeEnumSize(int32_t fieldNumber, int32_t value)
    __attribute__((const));

CF_EXTERN_C_END

NS_ASSUME_NONNULL_END
