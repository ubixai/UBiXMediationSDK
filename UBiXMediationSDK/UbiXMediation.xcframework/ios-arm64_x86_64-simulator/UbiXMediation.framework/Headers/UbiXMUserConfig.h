//
//  UbiXMUserConfig.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/5/27.
//  Copyright © 2024 UBiX. All rights reserved.
//

#import "UbiXMInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

// Theme mode for iOS.
typedef NS_ENUM(NSInteger, UbiXMAdSDKThemeStatus) {
    UbiXMAdSDKThemeStatus_None = -1,
    UbiXMAdSDKThemeStatus_Normal = 0,
    UbiXMAdSDKThemeStatus_Night  = 1,
};

@interface UbiXMUserConfig : UbiXMInterfaceBaseObject
/// 设置广告主题，扩展暗黑模式
@property (nonatomic, assign) UbiXMAdSDKThemeStatus themeStatus;

/// 设置扩展设备信息，如不了解该功能，请勿使用。 如@"[{\"device_id\":\"62271333038\"}]"
@property (nonatomic, copy) NSDictionary *extraDeviceMap;

/// 自定义IDFA，格式需与IDFA格式相同，xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx，当前定制版本由 UBiX/KS/JT Adapter 按各自能力处理
@property (nonatomic, copy, nullable) NSString *customIDFA;

@end

NS_ASSUME_NONNULL_END
