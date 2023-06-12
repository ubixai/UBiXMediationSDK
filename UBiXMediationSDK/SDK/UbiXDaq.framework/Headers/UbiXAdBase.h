//
//  UbiXAdBase.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/5/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
#define UbiXCheckNSNull(object) ([object isKindOfClass:[NSNull class]]) ? nil : object

typedef NS_ENUM(UInt8, UXLogLevel) {
    UXLogLevelNone = UINT8_MAX,
    UXLogLevelDebug = 2,
    UXLogLevelInfo = 3,  // Default
    UXLogLevelWarn = 4,
    UXLogLevelError = 5,
};

/// 设置控制台日志打印级别
void UXSetLogLevel(UXLogLevel level);
void UXLogDebug(NSString * _Nonnull fmt, ...);
void UXLogInfo(NSString * _Nonnull fmt, ...);
void UXLogWarn(NSString * _Nonnull fmt, ...);
void UXLogError(NSString * _Nonnull fmt, ...);

@interface UbiXAdBase : NSObject

@property (nonatomic, assign)BOOL enableLog;

+ (NSString *)getBundleName;

+ (NSString *)getUserAgent;

+ (NSString *)getIPAddress;

+ (NSString *)getIdfa;

+ (NSString *)getIdfv;

+ (NSString *)getSystemLanguage;

+ (NSString *)getCountryCode;

+ (NSString *)getNetworkCode;

+ (NSString *)getLocaleCountryCode;

+ (NSString *)getLocaleLanguageCode;

+ (NSString *)getDeviceModel;

+ (NSString *)getDeviceType;

+ (NSString *)getBase64Encode:(NSString*)data;

+ (NSString *)getOSVersion;

+ (NSString *)getCPUType;

+ (NSString *)getDeviceInfo;

+ (NSString *)getDeviceName;

+ (NSDate *)stringToDate:(NSString *)string;

+ (NSString *)dateToString:(NSDate *)date;

+ (NSString *)md5:(NSString *)str;

+ (NSString *)getBundlePath:(NSString *)assetName;

+ (unsigned long)getActiveProcessorCount;

+ (unsigned long long)getMemoryUsage;

+ (float)getTotalDiskSpace;

+ (float)getFreeDiskSpace;

+ (NSInteger)getCurrentNetState;

+ (NSString *)getBootUpTime;

+ (NSString *)getBootUpTimeStamp;

+ (NSString *)getSystemUpdateTime;

+ (int)getPhysicalCoresCount;

+ (int)getBatteryLevel;

+ (NSUInteger)getIDFAAuthStatus;

+ (unsigned long long)getPhysicalMemory;

+ (unsigned long long)getAvailableMemorySize;

+ (void)copyToClipboard:(NSString *)content;

+ (UIViewController *)getCurrentVC;

+ (UIViewController *)getCurrentVC:(UIWindow *)window;

+ (UIViewController *)getCurrentVCFrom:(UIViewController *)rootVC;

+ (int)creativeOrientation;

+ (NSDate *)dateFromString:(NSString *)dateTimeStr;

+ (BOOL)jailbreak;

+ (BOOL)isNum:(NSString *)checkedNumString;

+ (void)enableUbiXLog;

+ (void)ubixLog:(NSString *)log;

/** 是否是 nil 空格 */
+ (BOOL)stringIsBlank:(NSString * _Nullable)str;

@end

NS_ASSUME_NONNULL_END
