//
//  JADFeedViewDelegate.h
//  JADYun
//
//  Created by wangshuai331 on 2021/1/18.
//

#ifndef JADFeedViewDelegate_h
#define JADFeedViewDelegate_h

@class JADFeedView;

NS_ASSUME_NONNULL_BEGIN

/**
  信息流广告视图代理回调
 
   The methods declared by the JADFeedViewDelegate protocol allow the adopting delegate to respond to messages from the
   JADFeedView class and thus respond to operations such as whether the native ad has been loaded.
 
   注意： 2.0.0版本后，所有回调方法均进行了修改，接入时请注意您的回调实现方法是否已按照最新版本更改。
   
 | 回调方法 | 注释
 | :--- | :---
 | jadFeedViewDidLoadSuccess: | 加载成功回调
 | jadFeedViewDidLoadFailure:error: | 返回的错误码（error），表示广告加载失败的原因
 | jadFeedViewDidRenderSuccess: | 渲染成功回调 ，建议在该回调方法中统计您的填充数据
 | jadFeedViewDidRenderFailure:error: | 渲染失败，网络原因或者硬件原因导致渲染失败，可以更换手机或者网络环境测试。
 | jadFeedViewDidExposure: | 有效曝光回调 ，建议在该回调方法中统计您的曝光数据
 | jadFeedViewDidClick: | 点击回调 ，建议在该回调方法中统计您的点击数据
 | jadFeedViewDidClose: | 关闭回调，建议在此回调方法中直接进行广告对象的移除动作，并将广告对象置为nil
 | jadFeedViewDidCloseOtherController:interactionType: | 跳转页关闭回调
 */
@protocol JADFeedViewDelegate <NSObject>

@required

/**
 * @brief 加载成功回调
 * @param feedView : view for feedView
 * @discussion 广告数据：加载成功
 *
 * This method is called when feedView ad slot loaded successfully.
 */
- (void)jadFeedViewDidLoadSuccess:(JADFeedView *)feedView;

/**
 * @brief 加载失败回调
 * @param error : the reason of error
 * @discussion 广告数据：加载失败
 *
 * This method is called when feedView ad slot failed to load.
 */
- (void)jadFeedViewDidLoadFailure:(JADFeedView *)feedView error:(NSError *__nullable)error;

/**
 * @brief 渲染成功回调
 * @param feedView : view for feedView
 * @discussion 广告视图：渲染完成
 *
 * This method is called when rendering a feedView succeed, and feedView.size.height has been updated
 *
 */
- (void)jadFeedViewDidRenderSuccess:(JADFeedView *)feedView;

/**
 * @brief 渲染失败回调
 * @discussion 广告视图：渲染失败
 *
 * This method is called when a feedView failed to render
 */
- (void)jadFeedViewDidRenderFailure:(JADFeedView *)feedView error:(NSError *__nullable)error;;

/**
 * @brief 有效曝光成功回调
 * @discussion 广告视图：有效曝光
 *
 * This method is called when feedView  will be showing.
 */
- (void)jadFeedViewDidExposure:(JADFeedView *)feedView;

/**
 * @brief 点击事件回调
 * @discussion 广告视图：点击
 *
 * Sent when an ad view is clicked
 */
- (void)jadFeedViewDidClick:(JADFeedView *)feedView;

/**
 * @brief 关闭事件回调
 * @discussion 广告视图：关闭
 *
 * Sent when an ad view is closed
 */
- (void)jadFeedViewDidClose:(JADFeedView *)feed;

/**
 * @brief 跳转页关闭回调
 * @param interactionType ： open AppStore in app or open the webpage
 * @discussion 当跳转落地页关闭时回调
 *
 * This method is called when another controller has been closed.
 */
- (void)jadFeedViewDidCloseOtherController:(JADFeedView *)feedView
                           interactionType:(JADInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END

#endif /* JADFeedViewDelegate_h */
