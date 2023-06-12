//
//  JADInterstitialAdDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2021/1/20.
//

#ifndef JADInterstitialAdDelegate_h
#define JADInterstitialAdDelegate_h

@class JADInterstitialAd;

NS_ASSUME_NONNULL_BEGIN

/**
  插屏广告视图代理回调
 
  The methods declared by the JADInterstitialAdDelegate protocol allow the adopting delegate to respond to messages from the JADInterstitialAd class and thus respond to operations such as whether the interstitial ad has been loaded.
 
  注意： 2.0.0版本后，所有回调方法均进行了修改，接入时请注意您的回调实现方法是否已按照最新版本更改。
 
 | 回调方法 | 注释
 | :--- | :---
 | jadInterstitialAdDidLoadSuccess: | 加载成功回调，建议在该回调方法中统计您的请求成功数
 | jadInterstitialAdDidLoadFailure:error: | 返回的错误码（error），表示广告加载失败的原因
 | jadInterstitialAdDidRenderSuccess: | 渲染成功回调，建议在该回调方法中统计您的填充数
 | jadInterstitialAdDidRenderFailure:error | 渲染失败，网络原因或者硬件原因导致渲染失败，可以更换手机或者网络环境测试。
 | jadInterstitialAdDidExposure: | 有效曝光回调，建议在该回调方法中统计您的曝光数
 | jadInterstitialAdDidClick: | 点击回调，建议在该回调方法中统计您的点击数
 | jadInterstitialAdDidClose: | 关闭回调，建议在此回调方法中直接进行广告对象的移除动作，并将广告对象置为nil
 | jadInterstitialAdDidCloseOtherController:interactionType: | 跳转页关闭回调
 */
@protocol JADInterstitialAdDelegate <NSObject>

@required

/**
 * @brief 加载成功回调
 * @discussion 广告数据：加载完成
 *
 * This method is called when interstitial ad material loaded successfully.
 */
- (void)jadInterstitialAdDidLoadSuccess:(JADInterstitialAd *)interstitialAd;

/**
 * @brief 加载失败回调
 * @param error : the reason of error
 * @discussion 广告数据：加载失败
 *
 * This method is called when interstitial ad material failed to load.
 */
- (void)jadInterstitialAdDidLoadFailure:(JADInterstitialAd *)interstitialAd error:(NSError *__nullable)error;

/**
 * @brief 渲染成功回调
 * @discussion 广告视图：渲染完成
 *
 * This method is called when rendering a interstitial ad succeed.
 */
- (void)jadInterstitialAdDidRenderSuccess:(JADInterstitialAd *)interstitialAd;

/**
 * @brief 渲染失败回调
 * @param error : the reason of error
 * @discussion 广告视图：渲染失败
 *
 * This method is called when a interstitial ad failed to render.
 */
- (void)jadInterstitialAdDidRenderFailure:(JADInterstitialAd *)interstitialAd error:(NSError *__nullable)error;

/**
 * @brief 有效曝光成功回调
 * @discussion 广告视图：有效曝光回调
 *
 * This method is called when interstitial ad  will be showing.
 */
- (void)jadInterstitialAdDidExposure:(JADInterstitialAd *)interstitialAd;

/**
 * @brief 点击事件回调
 * @discussion 广告视图：点击
 *
 * This method is called when interstitial ad is clicked.
 */
- (void)jadInterstitialAdDidClick:(JADInterstitialAd *)interstitialAd;

/**
 * @brief 关闭事件回调
 * @discussion 广告视图：关闭
 *
 * This method is called when interstitial ad is closed.
 */
- (void)jadInterstitialAdDidClose:(JADInterstitialAd *)interstitialAd;

/**
 * @brief 跳转页关闭回调
 * @param interactionType ： open AppStore in app or open the webpage
 * @discussion 当跳转落地页关闭时回调
 * 
 * This method is called when another controller has been closed.
 */
- (void)jadInterstitialAdDidCloseOtherController:(JADInterstitialAd *)interstitialAd
                                 interactionType:(JADInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END

#endif /* JADInterstitialAdDelegate_h */
