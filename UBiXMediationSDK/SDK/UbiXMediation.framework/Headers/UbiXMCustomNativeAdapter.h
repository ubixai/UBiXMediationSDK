//
//  UbiXMCustomNativeAdapter.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/4.
//  Copyright © 2024 UBiX. All rights reserved.
//

#ifndef UbiXMCustomNativeAdapter_h
#define UbiXMCustomNativeAdapter_h

#import "UbiXMCustomAdapter.h"
#import "UbiXMCustomNativeAdapterBridge.h"
#import "UbiXMediationNativeAd.h"

@class UbiXMediationMediaView;

/// 自定义Native广告的adapter广告协议
@protocol UbiXMCustomNativeAdapter <UbiXMCustomAdapter>

/// 加载广告的方法
/// @param slotID adn的广告位ID
/// @param size 广告展示尺寸
/// @param imageSize 图片或视频展示尺寸
/// @param parameter 广告加载的参数
- (void)loadNativeAdWithSlotID:(NSString *)slotID andSize:(CGSize)size imageSize:(CGSize)imageSize parameter:(NSDictionary *)parameter;

/// 渲染广告，为模板广告时会回调该方法，需对广告进行渲染
/// @param expressAdView 模板广告
- (void)renderForExpressAdView:(UIView *)expressAdView;

/// 为模板广告设置控制器
/// @param viewController 控制器
/// @param expressAdView 模板广告
- (void)setRootViewController:(UIViewController *)viewController forExpressAdView:(UIView *)expressAdView;

/// 为非模板广告设置控制器
/// @param viewController 控制器
/// @param nativeAd 非模板广告
- (void)setRootViewController:(UIViewController *)viewController forNativeAd:(id)nativeAd;

/// 注册容器和可点击区域
/// @param containerView 容器视图
/// @param views 可点击视图组
- (void)registerContainerView:(__kindof UIView *)containerView andClickableViews:(NSArray<__kindof UIView *> *)views closableViews:(NSArray *)closableViews forNativeAd:(id)nativeAd;

- (UIView *)shakeViewForNativeAd:(id)nativeAd size:(CGSize)size;

- (void)unRegisterView;

@optional
- (void)renderView:(UbiXMediationMediaView *)view selfRenderView:(nonnull UIView *)selfRenderView;

/// 当前加载的广告的状态，native模板广告
- (UbiXMMediatedAdStatus)mediatedAdStatusWithExpressView:(UIView *)view;

/// 当前加载的广告的状态，native非模板广告
- (UbiXMMediatedAdStatus)mediatedAdStatusWithMediatedNativeAd:(UbiXMediationNativeAd *)ad;

/// 广告视图即将被展示回调，只会调用一次
/// @param expressAdView 模板广告视图
/// @param mediatedNativeAd GroMore包装的广告数据
- (void)adViewWillAddToSuperViewWithExpressAdView:(__kindof UIView *)expressAdView orMediatedNativeAd:(UbiXMediationNativeAd *)mediatedNativeAd;

/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<UbiXMCustomNativeAdapterBridge> bridge;

/// 上报dislike的原因，仅限非模板广告自定义关闭按钮时使用
/// @param ad GroMore包装的非模板广告数据
/// @param reasons dislike的原因。数据基于ADN提供的原因修改
- (void)reportDislikeAd:(UbiXMediationNativeAd *)ad withReasons:(NSArray<UbiXMDislikeReason *> *)reasons;

/// 待上报的视频事件枚举类型
//typedef NS_ENUM(NSInteger, BUMVideoAdEvent) {
//    BUMVideoAdEventVideoDidPlay = 1, // 视频开始播放
//    BUMVideoAdEventVideoDidFinish = 2, // 视频播放完成，无异常
//    BUMVideoAdEventVideoDidPause = 3, // 视频暂停
//    BUMVideoAdEventVideoDidResume = 4, // 视频恢复播放
//    BUMVideoAdEventVideoDidBreak = 5, // 视频意外终止，如跳过、视频切出屏幕等
//    BUMVideoAdEventVideoDidClick = 6, // 视频被点击
//    BUMVideoAdEventVideoDidStartFailed = 7, // 视频开始播放时出现异常
//    BUMVideoAdEventVideoDidPlayFailed = 8, // 视频播放中出现异常
//
//};
- (void)reportVideoEvent:(NSInteger)event forAd:(UbiXMediationNativeAd *)ad withParameters:(NSDictionary *)parameters;

@end

#endif /* UbiXMCustomNativeAdapter_h */
