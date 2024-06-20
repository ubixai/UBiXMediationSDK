//
//  UbiXMSdkInitConfig.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/5/27.
//  Copyright © 2024 UBiX. All rights reserved.
//

#import "UbiXMInterfaceBaseObject.h"
#import "UbiXMUserConfig.h"

NS_ASSUME_NONNULL_BEGIN

/// adn初始化配置信息
@interface UbiXMSdkInitConfig : UbiXMInterfaceBaseObject
/// 用户自定义配置
@property (nonatomic, strong, readonly) UbiXMUserConfig *userConfig;

/// appID
@property (nonatomic, copy, readonly) NSString *appID;

/// appKey
@property (nonatomic, copy, readonly) NSString *appKey;

/// adn的标识
@property (nonatomic, copy, readonly) NSString *name;

/// 是否可用状态
@property (nonatomic, assign, readonly) BOOL valid;

/// 是否是自定义adapter，白名单用户权限
@property (nonatomic, assign, readonly) BOOL custom;

/// 自定义adapter初始化的配置类名，该类对象遵循UbiXMCustomConfigAdapter协议
@property (nonatomic, copy, readonly) NSString *customAdnClassName;

/// 自定义adapter banner广告的配置类名，该类对象遵循UbiXMCustomBannerAdapter协议
@property (nonatomic, copy, readonly) NSString *customBannerAdapterClassName;

/// 自定义adapter 插屏广告的配置类名，该类对象遵循UbiXMCustomInterstitialAdapter协议
@property (nonatomic, copy, readonly) NSString *customInterstitialAdapterClassName;

/// 自定义adapter 激励视频广告的配置类名，该类对象遵循UbiXMCustomRewardedVideoAdapter协议
@property (nonatomic, copy, readonly) NSString *customRewardedVideoAdapterClassName;

/// 自定义adapter 全屏广告的配置类名，该类对象遵循UbiXMCustomFullscreenVideoAdapter协议
@property (nonatomic, copy, readonly) NSString *customFullscreenVideoAdapterClassName;

/// 自定义adapter 开屏广告的配置类名，该类对象遵循UbiXMCustomSplashAdapter协议
@property (nonatomic, copy, readonly) NSString *customSplashAdapterClassName;

/// 自定义adapter native广告的配置类名，该类对象遵循UbiXMCustomNativeAdapter协议
@property (nonatomic, copy, readonly) NSString *customNativeAdapterClassName;

/// 自定义adapter draw广告的配置类名，该类对象遵循UbiXMCustomDrawAdapter协议
//@property (nonatomic, copy, readonly) NSString *customDrawAdapterClassName;

@end

NS_ASSUME_NONNULL_END
