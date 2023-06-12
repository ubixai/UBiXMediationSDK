//
//  JADBannerViewDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2021/1/18.
//

#ifndef JADBannerViewDelegate_h
#define JADBannerViewDelegate_h

#import <Foundation/Foundation.h>

@class JADBannerView;

NS_ASSUME_NONNULL_BEGIN

/**
  横幅广告视图代理回调
 
  The methods declared by the JADBannerViewDelegate protocol allow the adopting delegate to respond to messages from the
  JADBannerView class and thus respond to operations such as whether the ad has been loaded, the person has clicked the ad.
 
  注意： 2.0.0版本后，所有回调方法均进行了修改，接入时请注意您的回调实现方法是否已按照最新版本更改。
 
 | 回调方法 | 注释
 | :--- | :---
 | jadBannerViewDidLoadSuccess: | 加载成功回调，建议在该回调方法中统计您的请求成功数
 | jadBannerViewDidLoadFailure:error: | 返回的错误码（error），表示广告加载失败的原因
 | jadBannerViewDidRenderSuccess: | 渲染成功回调，建议在该回调方法中统计您的填充数
 | jadBannerViewDidRenderFailure:error: | 渲染失败，网络原因或者硬件原因导致渲染失败，可以更换手机或者网络环境测试。
 | jadBannerViewDidExposure: | 有效曝光回调，建议在该回调方法中统计您的曝光数
 | jadBannerViewDidClick: | 点击回调，建议在该回调方法中统计您的点击数
 | jadBannerViewDidClose: | 关闭回调，建议在此回调方法中直接进行广告对象的移除动作，并将广告对象置为nil
 | jadBannerViewDidCloseOtherController:interactionType: | 落地页关闭回调
 */
@protocol JADBannerViewDelegate <NSObject>

@required

/**
 * @brief 加载成功回调
 * @discussion 广告数据：加载完成
 * 
 * Sent when an ad has been successfully loaded.
 */
- (void)jadBannerViewDidLoadSuccess:(JADBannerView *)bannerView;

/**
 * @brief 加载失败回调
 * @param error : the reason of error
 * @discussion 广告数据：加载失败
 *
 * Sent after an JADBannerView fails to load the ad.
 */
- (void)jadBannerViewDidLoadFailure:(JADBannerView *)bannerView error:(NSError *__nullable)error;

/**
 * @brief 渲染成功回调
 * @discussion 广告视图：渲染完成
 *
 * This method is called when rendering a bannerView succeed.
 */
- (void)jadBannerViewDidRenderSuccess:(JADBannerView *)bannerView;

/**
 * @brief 渲染失败回调
 * @param error : the reason of error
 * @discussion 广告视图：渲染失败
 *
 * This method is called when a bannerView failed to render.
 */
- (void)jadBannerViewDidRenderFailure:(JADBannerView *)bannerView error:(NSError *__nullable)error;

/**
 * @brief 有效曝光成功回调
 * @discussion 广告视图：有效曝光回调
 *
 * Sent immediately before the impression of an JADBannerView object will be logged.
 */
- (void)jadBannerViewDidExposure:(JADBannerView *)bannerView;

/**
 * @brief 点击事件回调
 * @discussion 广告视图：点击
 *
 * Sent after an ad has been clicked by the person.
 */
- (void)jadBannerViewDidClick:(JADBannerView *)bannerView;

/**
 * @brief 关闭事件回调
 * @discussion 广告视图：关闭
 *
 * Sent after a full screen content has been dismissed.
 */
- (void)jadBannerViewDidClose:(JADBannerView *)bannerView;

/**
 * @brief 跳转页关闭回调
 * @param interactionType ： open AppStore in app or open the webpage
 * @discussion 此回调在落地页关闭时返回 This method is called when another controller has been closed.
 */
- (void)jadBannerViewDidCloseOtherController:(JADBannerView *)bannerView
                             interactionType:(JADInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END

#endif /* JADBannerViewDelegate_h */
