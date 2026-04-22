//
//  UbiXMCustomInterstitialAdapterBridge.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/18.
//

#ifndef UbiXMCustomInterstitialAdapterBridge_h
#define UbiXMCustomInterstitialAdapterBridge_h

#import <Foundation/Foundation.h>

@protocol UbiXMCustomInterstitialAdapter;

/// 自定义插屏广告的adapter的回调协议
@protocol UbiXMCustomInterstitialAdapterBridge <NSObject>
@optional

/// 在广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
- (void)interstitialAd:(id<UbiXMCustomInterstitialAdapter>_Nonnull)adapter didLoadWithExt:(NSDictionary *)ext;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)interstitialAd:(id<UbiXMCustomInterstitialAdapter>_Nonnull)adapter didLoadFailWithError:(NSError *_Nullable)error ext:(NSDictionary *)ext;

/// 在广告已经展示时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidVisible:(id<UbiXMCustomInterstitialAdapter>_Nonnull)adapter;

/// 广告展示失败的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)interstitialAdDidShowFailed:(id<UbiXMCustomInterstitialAdapter>)adapter error:(NSError *)error;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidClose:(id<UbiXMCustomInterstitialAdapter>_Nonnull)adapter;

/// 在广告点击事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdDidClick:(id<UbiXMCustomInterstitialAdapter>_Nonnull)adapter;

/// 在广告即将展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdWillPresentFullScreenModal:(id<UbiXMCustomInterstitialAdapter>_Nonnull)adapter;

/// 在广告关闭详情页或者appstore时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdWillDismissFullScreenModal:(id<UbiXMCustomInterstitialAdapter>_Nonnull)adapter;

/// 在模板广告渲染成功时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)interstitialAdRenderSuccess:(id<UbiXMCustomInterstitialAdapter>_Nonnull)adapter;

/// 在广告渲染失败时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)interstitialAd:(id<UbiXMCustomInterstitialAdapter>_Nonnull)adapter renderFailedWithError:(NSError *)error;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;
@end

#endif /* UbiXMCustomInterstitialAdapterBridge_h */
