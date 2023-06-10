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

@interface UbiXMConcealConfig: NSObject

/**  是否允许用户读取定位信息， 默认允许  **/
@property (nonatomic, assign) BOOL isCanReadLocal;

/**  是否允许用户读取网络状态信息， 默认允许  **/
@property (nonatomic, assign) BOOL isCanReadNetType;

/**  是否允许用户读取idfa， 默认允许  **/
@property (nonatomic, assign) BOOL isCanReadIDFA;

/**  是否允许个性化广告推荐 默认允许 0 拒绝，1 允许  **/
@property (nonatomic, assign) BOOL isLimitPersonalAds;

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


@interface UbiXMediationSDK : NSObject

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
+ (void)initializeWithAppId:(NSString *)appId config:(UbiXMConcealConfig *)concealConfig;

/**
 sdk版本 如: @"2.0.0"
 */
+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
