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

@interface UBiXNativeExpressAdView : UIView;
/// 广告是否可用，渲染成功后为YES
@property (nonatomic, assign, readonly, getter=isValid) BOOL valid;

/// 回调委托对象
@property (nonatomic, weak) id<UBiXNativeExpressAdViewDelegate> delegate;

/// @required 用于打开落地页，确保ta当前无presentedVC，否则将无法打开落地页
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 * 渲染广告，请在渲染成功后再进行view的展示，否则将会显示空白页面或viewSize为CGSizeZero，也会影响曝光回调
 */
- (void)render;

/**
 * 获取广告价格，单位(分)
 */
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
