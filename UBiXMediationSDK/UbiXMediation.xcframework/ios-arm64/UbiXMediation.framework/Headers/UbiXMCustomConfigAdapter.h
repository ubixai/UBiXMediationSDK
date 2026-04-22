//
//  UbiXMCustomConfigAdapter.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/5/27.
//  Copyright © 2024 UBiX. All rights reserved.
//

#ifndef UbiXMCustomConfigAdapter_h
#define UbiXMCustomConfigAdapter_h

#import <Foundation/Foundation.h>
#import "UbiXMSdkInitConfig.h"


/// 自定义adapter的基本配置协议
@protocol UbiXMCustomConfigAdapter <NSObject>
@required
/// 该自定义adapter是基于哪个版本实现的，填写编写时的最新值即可，UBiXM会根据该值进行兼容处理
- (NSString *)basedOnCustomAdapterVersion;

/// adn初始化方法
/// @param initConfig 初始化配置，包括appid、appkey基本信息和部分用户传递配置
- (void)initializeAdapterWithConfiguration:(UbiXMSdkInitConfig *_Nullable)initConfig;

/// adn初始化方法
/// @param initConfig 初始化配置，包括appid、appkey基本信息和部分用户传递配置
- (void)initializeAdapterWithConfiguration:(UbiXMSdkInitConfig *_Nullable)initConfig
                                 completed:(void(^)(BOOL succ, NSError *error))handler;

/// adapter的版本号
- (NSString *_Nonnull)adapterVersion;

/// adn的版本号
- (NSString *_Nonnull)networkSdkVersion;

/// 隐私权限更新，用户更新隐私配置时触发，初始化方法调用前一定会触发一次
- (void)didRequestAdPrivacyConfigUpdate:(NSDictionary *)config;

/// 收到配置更新请求时触发，如主题更新，初始化时设定配置不会触发，具体修改项需自行校验
- (void)didReceiveConfigUpdateRequest:(UbiXMUserConfig *)config;

@optional
/// 无需实现
@property (nonatomic, assign) BOOL isCustomAdapter;

@end


#endif /* UbiXMCustomConfigAdapter_h */
