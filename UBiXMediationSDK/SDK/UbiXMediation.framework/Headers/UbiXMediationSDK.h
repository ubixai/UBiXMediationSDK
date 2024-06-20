//
//  UbiXMediationSDK.h
//  UbiXMediation
//
//  Created by UbiX on 2021/7/30.
//

#import <Foundation/Foundation.h>

#if __has_include(<CoreLocation/CoreLocation.h>)
#import <CoreLocation/CoreLocation.h>
#else
#endif


NS_ASSUME_NONNULL_BEGIN
/// 【可选】NSNumber，是否在adn中使用位置，如果是，adn将自己获得纬度和经度，而不是使用传入的值（  kUbiXMPrivacyLongitude/  kUbiXMPrivacyLatitude）。
const static NSString *kUbiXMPrivacyCanLocation = @"kUbiXMPrivacyCanLocation";
/// 【可选】NSNumber，经度的值。默认值是0.0。
const static NSString *  kUbiXMPrivacyLongitude = @"kUbiXMPrivacyLongitude";
/// 【可选】NSNumber，纬度的值。默认值是0.0。
const static NSString *  kUbiXMPrivacyLatitude = @"kUbiXMPrivacyLatitude";
/// 【可选】NSNumber，是否限制个性化广告:0-不限制，1-限制，默认为0。
const static NSString *kUbiXMPrivacyLimitPersonalAds = @"kUbiXMPrivacyLimitPersonalAds";
/// 【可选】NSNumber，是否禁止CAID：0-不禁止，1-禁止，默认为0。
const static NSString *  kUbiXMPrivacyForbiddenCAID = @"kUbiXMPrivacyForbiddenCAID";
/// 【可选】NSNumber，是否禁止IDFA：0-不禁止，1-禁止，默认为0。
const static NSString *  kUbiXMPrivacyForbiddenIDFA = @"kUbiXMPrivacyForbiddenIDFA";


@interface UbiXMConcealConfig: NSObject

/**  是否允许用户读取定位信息， 默认允许  **/
@property (nonatomic, assign) BOOL isCanReadLocal;

/**  是否允许用户读取网络状态信息， 默认允许  **/
@property (nonatomic, assign) BOOL isCanReadNetType;

/**  是否允许用户读取idfa， 默认允许  **/
@property (nonatomic, assign) BOOL isCanReadIDFA;

/**  是否允许个性化广告推荐 默认允许 0 拒绝，1 允许  **/
@property (nonatomic, assign) BOOL isLimitPersonalAds DEPRECATED_MSG_ATTRIBUTE("即将废弃，请使用[UbiXMediationSDK setLimitPersonalAds:]");

/** 允许用户传递idfa，如果用户传递了此值，则聚合SDK不再进行该值的获取 */
@property (nonatomic, copy) NSString *idfa;

#if __has_include(<CoreLocation/CoreLocation.h>)
/** 允许用户传递定位信息，如果用户传递了此值，则聚合SDK不再进行该值的获取 */
@property (nonatomic, assign)CLLocationDegrees latitude;
@property (nonatomic, assign)CLLocationDegrees longitude;
#else
#endif

/**  是否打开日志模式，默认不打开  **/
@property (nonatomic, assign) BOOL isOpenLog;


@end

/// 用户性别, 0: Unknown, 1: Male, 2: Female
typedef NS_ENUM (int, UbixMUserInfoGender) {
    UbiXMUserInfoGender_Unknown                  = 0,
    UbiXMUserInfoGender_Male                     = 1,
    UbiXMUserInfoGender_Female                   = 2,
};
/// 付费用户, 0: 未知；1: 否；2: 是
typedef NS_ENUM (int, UbixMUserInfoSubscribe) {
    UbiXMUserInfoSubscribe_Unknown              = 0,
    UbiXMUserInfoSubscribe_No                   = 1,
    UbiXMUserInfoSubscribe_Yes                  = 2,
};

/// 流量分组信息
@interface UbiXMUserInfoConfig : NSObject
/// 用户在媒体上注册的 ID
@property (nonatomic, copy) NSString *userId;
/// 渠道，字符的规则：[A-Za-z0-9_]
@property (nonatomic, copy) NSString *channel;
/// 子渠道， 字符的规则：[A-Za-z0-9_]
@property (nonatomic, copy) NSString *subChannel;
/// 用户年龄，用户的年龄段。
/// [1-18):1;[18-24):18;[24-31):24;[31- 41):31;[41-51):41;50 以上传 50
@property (nonatomic, assign) int age;
/// 用户性别
@property (nonatomic, assign) UbixMUserInfoGender gender;
/// 付费用户, 0: 未知；1: 否；2: 是
@property (nonatomic, assign) UbixMUserInfoSubscribe isSubscriber;
/// 流量分组ID或者标签ID
@property (nonatomic, copy) NSString *pubSegmentId;
/// 自定义，
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *customUserInfo;

@end

/// 聚合SDK 配置项
@interface UbiXMAdConfig: NSObject
/// 隐私相关信息配置
@property (nonatomic, strong) UbiXMConcealConfig *concealConfig;
/// 流量分组信息配置
@property (nonatomic, strong) UbiXMUserInfoConfig *userInfoConfig;

@end


@interface UbiXMediationSDK : NSObject

/**
 * 可选, 是否限制个性化推荐:  NO-不限制、YES-限制，默认为NO。官方维护版本中只适用于CSJ，Ks、百度、GDT 、UbiX
 */
@property (class, nonatomic, assign) BOOL limitPersonalAds;

/**
 初始化方法
 @param appId 聚合appId
 */
+ (void)initializeWithAppId:(NSString *)appId;

/**
 初始化方法
 @param appId 聚合appId
 @param concealConfig 隐私相关的获取配置
 */
+ (void)initializeWithAppId:(NSString *)appId config:(UbiXMConcealConfig *)concealConfig DEPRECATED_MSG_ATTRIBUTE("接口即将废弃，请使用 + (void)initializeWithAppId:(NSString *)appId adConfig:(UbiXMAdConfig *)adConfig");

/**
 初始化方法
 @param appId 聚合appId
 @param adConfig 聚合sdk配置
 */
+ (void)initializeWithAppId:(NSString *)appId adConfig:(UbiXMAdConfig *)adConfig;

/**
 sdk版本 如: @"2.0.0"
 */
+ (NSString *)sdkVersion;

/**
 初始化方法
 @param filePathBundle 预配置文件的bundle
 */
+ (void)setPresetConfigPathBundle:(NSBundle *)filePathBundle;

@end

NS_ASSUME_NONNULL_END
