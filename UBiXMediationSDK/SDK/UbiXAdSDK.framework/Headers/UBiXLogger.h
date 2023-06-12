//
//  UBiXLogger.h
//  UbiXAdSDK
//
//  Created by fei.li on 2022/9/28.
//

#import <Foundation/Foundation.h>

typedef enum : UInt8 {
    UBiXLoggerLevelNone  = UINT8_MAX,
    UBiXLoggerLevelDebug = 2,
    UBiXLoggerLevelInfo  = 3,  // Default
    UBiXLoggerLevelWarn  = 4,
    UBiXLoggerLevelError = 5,
} UBiXLoggerLevel;

/// 设置控制台日志打印级别
void UBiXSetLoggerLevel(UBiXLoggerLevel level);
void UBiXDebug(NSString * _Nonnull fmt, ...);
void UBiXInfo(NSString * _Nonnull fmt, ...);
void UBiXWarn(NSString * _Nonnull fmt, ...);
void UBiXError(NSString * _Nonnull fmt, ...);
