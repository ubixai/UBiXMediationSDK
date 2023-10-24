//
//  UbixNativeView.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/6/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UBiXAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class UBiXNativeExpressAdView;
@protocol UBiXNativeExpressAdViewDelegate <NSObject>
/**
 * 广告渲染成功
 */
- (void)ubixNativeExpressAdViewDidRender:(UBiXNativeExpressAdView *)nativeExpressAdView;

/**
 * 广告渲染失败
 * @param error 失败原因
 */
- (void)ubixNativeExpressAdViewFailedToRender:(UBiXNativeExpressAdView *)nativeExpressAdView withError:(NSError *)error;

/**
 *  广告展示完毕
 */
- (void)ubixNativeExpressAdViewDidShow:(UBiXNativeExpressAdView *)nativeExpressAdView;

/**
 *  广告点击回调
 */
- (void)ubixNativeExpressAdViewDidClick:(UBiXNativeExpressAdView *)nativeExpressAdView;

/**
 *  广告点击关闭
 *  详解：开发者应在此回调中移除expressView
 */
- (void)ubixNativeExpressAdViewDidClose:(UBiXNativeExpressAdView *)nativeExpressAdView;

/**
 *  广告转化完成
 */
- (void)ubixNativeExpressAdViewDidFinishConversion:(UBiXNativeExpressAdView *)nativeExpressAdView interactionType:(UBiXAdInteractionType)interactionType;
@end

@protocol UBiXNativeExpressAdViewVideoDelegate <NSObject>
/**
 * 视频开始播放
 */
- (void)ubixNativeExpressAdViewVideoStartPlay:(UBiXNativeExpressAdView *)nativeExpressAdView;

/**
 * 视频暂停播放
 */
- (void)ubixNativeExpressAdViewVideoPausePlay:(UBiXNativeExpressAdView *)nativeExpressAdView;

/**
 * 视频继续播放
 */
- (void)ubixNativeExpressAdViewVideoResumePlay:(UBiXNativeExpressAdView *)nativeExpressAdView;

/**
 * 视频播放进度(秒)
 */
- (void)ubixNativeExpressAdViewVideo:(UBiXNativeExpressAdView *)nativeExpressAdView playedTime:(float)time;

/**
 * 视频播放结束
 * @param error 错误信息
 */
- (void)ubixNativeExpressAdViewVideoDidPlayFinish:(UBiXNativeExpressAdView *)nativeExpressAdView withError:(NSError *)error;

@end

@interface UBiXNativeExpressAdView : UIView;
/// 广告是否可用，渲染成功后为YES
@property (nonatomic, assign, readonly, getter=isValid) BOOL valid;

/// 广告委托对象
@property (nonatomic, weak) id<UBiXNativeExpressAdViewDelegate> delegate;

/// 视频委托对象
@property (nonatomic, weak) id <UBiXNativeExpressAdViewVideoDelegate> videoDelegate;

/// @required 用于打开落地页，确保ta当前无presentedVC，否则将无法打开落地页
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 * 渲染广告，请在渲染成功后再进行view的展示，否则将会显示空白页面或viewSize为CGSizeZero，也会影响曝光回调
 * 在主线程调用
 */
- (void)render;

/**
 * 获取广告价格，单位(分)
 */
- (NSInteger)eCPM;

/**
 * 是否是视频广告
 */
- (BOOL)isVideoAd;

/**
 * 视频时长(s)
 */
- (float)videoDuration;
@end

NS_ASSUME_NONNULL_END
