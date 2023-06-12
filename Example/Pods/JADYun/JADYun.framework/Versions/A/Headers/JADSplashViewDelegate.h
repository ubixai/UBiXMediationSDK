//
//  JADSplashViewDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2021/1/18.
//

#ifndef JADSplashViewDelegate_h
#define JADSplashViewDelegate_h

@class JADSplashView;

NS_ASSUME_NONNULL_BEGIN

/**
  开屏广告视图代理回调
 
  注意： 2.0.0版本后，所有回调方法均进行了修改，接入时请注意您的回调实现方法是否已按照最新版本更改。
 
 | 回调方法 | 注释
 | :--- | :---
 | jadSplashViewDidLoadSuccess: | 加载成功回调，建议在该回调方法中统计您的请求成功数
 | jadSplashViewDidLoadFailure:error: | 返回的错误码（error），表示广告加载失败的原因
 | jadSplashViewDidRenderSuccess: | 渲染成功回调，建议在该回调方法中统计您的填充数
 | jadSplashViewDidRenderFailure:error: | 渲染失败回调，网络原因或者硬件原因导致渲染失败，可以更换手机或者网络环境测试。
 | jadSplashViewDidExposure: | 有效曝光回调，建议在该回调方法中统计您的曝光数
 | jadSplashViewDidClick: | 点击回调，建议在该回调方法中统计您的点击数
 | jadSplashViewDidClose: | 关闭回调，当点击跳过按钮或者用户点击广告时会直接触发此回调，建议在此回调方法中直接进行广告对象的移除动作，并将广告对象置为nil
 
 */
@protocol JADSplashViewDelegate <NSObject>

@required

/**
 * @brief 加载成功回调
 * @discussion 广告数据：加载完成
 *
 * This method is called when splash ad material loaded successfully.
 */
- (void)jadSplashViewDidLoadSuccess:(JADSplashView *)splashView;

/**
 * @brief 加载失败回调
 * @param error : the reason of error
 * @discussion 广告数据：加载失败
 *
 * This method is called when splash ad material failed to load.
 */
- (void)jadSplashViewDidLoadFailure:(JADSplashView *)splashView error:(NSError *__nullable)error;

/**
 * @brief 渲染成功回调
 * @discussion 广告视图：渲染完成
 *
 * This method is called when rendering a splash ad succeed.
 */
- (void)jadSplashViewDidRenderSuccess:(JADSplashView *)splashView;

/**
 * @brief 渲染失败回调
 * @param error : the reason of error
 * @discussion 广告视图：渲染失败
 *
 * This method is called when a splash ad failed to render.
 */
- (void)jadSplashViewDidRenderFailure:(JADSplashView *)splashView error:(NSError *__nullable)error;

/**
 * @brief 有效曝光成功回调
 * @discussion 广告视图：有效曝光回调
 *
 * This method is called when splash ad slot will be showing.
 */
- (void)jadSplashViewDidExposure:(JADSplashView *)splashView;

/**
 * @brief 点击事件回调
 * @discussion 广告视图：点击
 *
 * This method is called when splash ad is clicked.
 */
- (void)jadSplashViewDidClick:(JADSplashView *)splashView;

/**
 * @brief 关闭事件回调
 * @discussion 广告视图：关闭
 * This method is called when splash ad is closed.
 */
- (void)jadSplashViewDidClose:(JADSplashView *)splashView;

/**
 * @brief 跳转页关闭回调
 * @param interactionType ： open AppStore in app or open the webpage
 * @discussion This method is called when another controller has been closed.
 */
- (void)jadSplashViewDidCloseOtherController:(JADSplashView *)splashView
                             interactionType:(JADInteractionType)interactionType;

/**
 * @brief 倒计时回调
 * @param countDown ：  倒计时秒数，单位s
 * @discussion 广告视图：开屏倒计时时间回调
 *
 * This method is called when splash native ad is delay action.
 */
- (void)jadSplashView:(JADSplashView *)splashView countDown:(int)countDown;

@end

NS_ASSUME_NONNULL_END
#endif /* JADSplashViewDelegate_h */
