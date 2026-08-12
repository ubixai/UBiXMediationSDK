//
//  UbiXMCustomSplashAdapterBridge.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/5/30.
//  Copyright © 2024 UBiX. All rights reserved.
//

#ifndef UbiXMCustomSplashAdapterBridge_h
#define UbiXMCustomSplashAdapterBridge_h

@protocol UbiXMCustomSplashAdapter;

/// 自定义开屏广告的adapter的回调协议
@protocol UbiXMCustomSplashAdapterBridge <NSObject>
@optional

/// 在广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
- (void)splashAd:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter didLoadWithExt:(NSDictionary *)ext;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)splashAd:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter didLoadFailWithError:(NSError *_Nullable)error ext:(NSDictionary *)ext;

/// 在广告即将展示时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidShow:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter;

/// 广告展示失败的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)splashAdDidShowFailed:(id<UbiXMCustomSplashAdapter>)adapter error:(NSError *)error;

/// 在广告点击事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClick:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter;

/// 在广告被点击跳过时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClickSkip:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter;

/// 在广告即将关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillClose:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidClose:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
//- (void)splashAdDidClose:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter withType:(BUSplashAdCloseType)closeType;

/// 在广告即将展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillPresentFullScreenModal:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter;

/// 在广告关闭详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdWillDismissFullScreenModal:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter;

/// 在模板广告渲染成功时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidRenderSuccess:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter;

/// 在广告渲染失败时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)splashAd:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter didRenderFailedWithError:(NSError *)error;

/// 在广告倒计时结束时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)splashAdDidCountDownToZero:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter;

/// 在广告视频播放完成或者出错时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 播放错误
- (void)splashAd:(id<UbiXMCustomSplashAdapter>_Nonnull)adapter didPlayFinishWithError:(NSError *)error;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;
@end

#endif /* UbiXMCustomSplashAdapterBridge_h */
