//
//  UbiXMCustomRewardedVideoAdapterBridge.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/17.
//

#ifndef UbiXMCustomRewardedVideoAdapterBridge_h
#define UbiXMCustomRewardedVideoAdapterBridge_h

#import <Foundation/Foundation.h>
#import "UbiXMediationEnum.h"

@class UbiXMAdapterRewardAdInfo;

@protocol UbiXMCustomRewardedVideoAdapter;

/// 自定义激励视频广告的adapter的回调协议
@protocol UbiXMCustomRewardedVideoAdapterBridge <NSObject>
@optional

/// 在广告加载完成时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param ext 回传信息
- (void)rewardedVideoAd:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter didLoadWithExt:(NSDictionary *)ext;

/// 在广告加载失败时调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
/// @param ext 回传信息
- (void)rewardedVideoAd:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter didLoadFailWithError:(NSError *_Nullable)error ext:(NSDictionary *)ext;

/// 在广告中视频素材加载完成时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdVideoDidLoad:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter;

/// 在广告已经展示时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdDidVisible:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter;

/// 广告展示失败的时候调用该方法，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)rewardedVideoAdDidShowFailed:(id<UbiXMCustomRewardedVideoAdapter>)adapter error:(NSError *)error;

/// 在广告关闭时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdDidClose:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter;

/// 在广告点击事件触发时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdDidClick:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter;

/// 在广告视频播放状态变化时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param state 状态信息
- (void)rewardedVideoAd:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter didChangeState:(UbiXMVideoPlayerStatus)state;

/// 在广告视频播放完成时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)rewardedVideoAd:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter didPlayFinishWithError:(NSError *_Nullable)error;

/// 在ADN验证激励成功时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param infoBuilder 激励信息
- (void)rewardedVideoAd:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter didServerRewardSuccessWithInfo:(void(^)(UbiXMAdapterRewardAdInfo *info))infoBuilder;

/// 在广告被点击跳过时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdDidClickSkip:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter;

/// 在模板广告渲染成功时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdRenderSuccess:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter;

/// 在广告渲染失败时调用，非模板广告无需调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
/// @param error 错误信息
- (void)rewardedVideoAd:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter renderFailedWithError:(NSError *_Nullable)error;

/// 在广告即将展示详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdWillPresentFullScreenModel:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter;

/// 在广告关闭详情页或者app store时调用，直接调用即可，无需做响应判断
/// @param adapter 当前适配器
- (void)rewardedVideoAdWillDismissFullScreenModel:(id<UbiXMCustomRewardedVideoAdapter>_Nonnull)adapter;

/// 广告点击跳转使用的控制器
- (UIViewController *)viewControllerForPresentingModalView;
@end


#endif /* UbiXMCustomRewardedVideoAdapterBridge_h */
