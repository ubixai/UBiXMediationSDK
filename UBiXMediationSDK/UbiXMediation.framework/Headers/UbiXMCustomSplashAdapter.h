//
//  UbiXMCustomSplashAdapter.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/5/30.
//  Copyright © 2024 UBiX. All rights reserved.
//

#ifndef UbiXMCustomSplashAdapter_h
#define UbiXMCustomSplashAdapter_h

#import "UbiXMCustomSplashAdapterBridge.h"
#import "UbiXMCustomAdapter.h"

/// 开屏广告自定义实现协议
@protocol UbiXMCustomSplashAdapter <UbiXMCustomAdapter>

/// 加载开屏广告
/// @param slotID 广告位ID
/// @param parameter 广告加载参数
- (void)loadSplashAdWithSlotID:(NSString *)slotID andParameter:(NSDictionary *)parameter;

/// 展示开屏广告
/// @param window 广告展示窗口
/// @param parameter 广告展示参数
- (void)showSplashAdInWindow:(UIWindow *)window parameter:(NSDictionary *)parameter;

/// 广告关闭实现，在外部使用开发者调用`destoryAd`时触发
- (void)dismissSplashAd;

/// 当前加载的广告的状态
- (UbiXMMediatedAdStatus)mediatedAdStatus;

@optional

/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<UbiXMCustomSplashAdapterBridge > bridge;


@end

#endif /* UbiXMCustomSplashAdapter_h */
