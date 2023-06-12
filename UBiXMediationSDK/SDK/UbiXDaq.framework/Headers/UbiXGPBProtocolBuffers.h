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

#import "UbiXGPBBootstrap.h"

#import "UbiXGPBArray.h"
#import "UbiXGPBCodedInputStream.h"
#import "UbiXGPBCodedOutputStream.h"
#import "UbiXGPBDescriptor.h"
#import "UbiXGPBDictionary.h"
#import "UbiXGPBExtensionRegistry.h"
#import "UbiXGPBMessage.h"
#import "UbiXGPBRootObject.h"
#import "UbiXGPBUnknownField.h"
#import "UbiXGPBUnknownFieldSet.h"
#import "UbiXGPBUtilities.h"
#import "UbiXGPBWellKnownTypes.h"
#import "UbiXGPBWireFormat.h"

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(UbiX_GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define UbiX_GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

// Well-known proto types
#if UbiX_GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/UbiXGPBAny.pbobjc.h>
 #import <Protobuf/UbiXGPBApi.pbobjc.h>
 #import <Protobuf/UbiXGPBDuration.pbobjc.h>
 #import <Protobuf/UbiXGPBEmpty.pbobjc.h>
 #import <Protobuf/UbiXGPBFieldMask.pbobjc.h>
 #import <Protobuf/UbiXGPBSourceContext.pbobjc.h>
 #import <Protobuf/UbiXGPBStruct.pbobjc.h>
 #import <Protobuf/UbiXGPBTimestamp.pbobjc.h>
 #import <Protobuf/UbiXGPBType.pbobjc.h>
 #import <Protobuf/UbiXGPBWrappers.pbobjc.h>
#else
 #import "UbiXGPBAny.pbobjc.h"
 #import "UbiXGPBApi.pbobjc.h"
 #import "UbiXGPBDuration.pbobjc.h"
 #import "UbiXGPBEmpty.pbobjc.h"
 #import "UbiXGPBFieldMask.pbobjc.h"
 #import "UbiXGPBSourceContext.pbobjc.h"
 #import "UbiXGPBStruct.pbobjc.h"
 #import "UbiXGPBTimestamp.pbobjc.h"
 #import "UbiXGPBType.pbobjc.h"
 #import "UbiXGPBWrappers.pbobjc.h"
#endif
