//
//  JADNativeAd.h
//  JADYun
//
//  Created by wangshuai331 on 2020/11/2.
//

#import <Foundation/Foundation.h>
#import "JADNativeAdSlot.h"
#import "JADNativeAdData.h"

@protocol JADNativeAdDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 媒体自渲染广告
 
 代码示例：

    // 图片size
    JADNativeSize *imgSize = [[JADNativeSize alloc] init];
    imgSize.width = self.widthSlider.value;
    imgSize.height = self.heightSlider.value;

    // 创建 adSlot 对象
    JADNativeAdSlot *slot = [[JADNativeAdSlot alloc] init];
    slot.slotID = @"YOUR_SLOT_ID";
    slot.type = JADSlotTypeSplash;
    slot.imgSize = imgSize;
    slot.skipTime = 5;
    slot.eventInteractionType = JADEventInteractionTypeShake;

    // 创建 nativeAd 对象
    self.nativeAd = [[JADNativeAd alloc] initWithSlot:slot];
    self.nativeAd.rootViewController = self;
    self.nativeAd.delegate = self;

    // 请求广告
    [self.nativeAd loadAdData];
*/
@interface JADNativeAd : NSObject

/**
 * @brief 广告位
 * @discussion 广告位描述信息  slot包含id,type等
 */
@property (strong, nonatomic, readwrite, nullable) JADNativeAdSlot *adSlot;

/**
 * @brief 返回数据
 * @discussion 广告加载返回的数据
 */
@property (strong, atomic, readonly, nullable) NSArray<JADNativeAdData *> *data;

/**
 * @brief 交互方式
 * @discussion 点击、摇一摇、上划
 */
@property (assign, nonatomic) JADEventInteractionType adEventInteractionType;

/**
 * @brief 规格集
 * @discussion 单图集、组图集
 */
@property (assign, nonatomic) JADMediaSpecSetType adMediaSpecSetType;

/**
 * @brief 自渲染代理
 * @discussion 代理，里面包含了给开发者的回调事件
 */
@property (weak, nonatomic, readwrite, nullable) id <JADNativeAdDelegate> delegate;

/**
 * @brief 控制器
 * @discussion 处理事件的控制器；
 * 弹出落地页广告的控制器。必选。
 * required.
 */
@property (weak, nonatomic, readwrite) UIViewController *rootViewController;

/**
  @brief 初始化
  @param slot ：广告位描述信息，包括 slotID，adType...
  @return JADNativeAd
  @discussion 通过 ad slot 初始化 native ad
 */
- (instancetype)initWithSlot:(JADNativeAdSlot *)slot;

/**
 * @brief 注册视图
 * @param containerView  必选 required. container view of the native ad.
 * @param clickableViews 可选 optional. Array of views that are clickable.
 * @param closableViews 可选 optional. Array of views that are closable.
 * @discussion 注册点击视图与关闭视图
 *
 * Register clickable views in native ads view.
 */
- (void)registerContainer:(__kindof UIView *)containerView
       withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews
        withClosableViews:(NSArray<__kindof UIView *> *_Nullable)closableViews;

/**
 * @brief 注销视图
 * @discussion 注销自渲染注册的点击视图与关闭视图
 *
 * Unregister ad view from the native ad.
 */
- (void)unregisterView;

/**
 * @brief 加载广告
 * @discussion 加载广告数据
 *
 * Actively request nativeAd data.
 */
- (void)loadAdData;

@end

/**
 媒体自渲染广告代理回调

 注意： 2.0.0版本后，所有回调方法均进行了修改，接入时请注意您的回调实现方法是否已按照最新版本更改。
 
 | 回调方法 | 注释
 | :--- | :---
 | jadNativeAdDidLoadSuccess: | 广告物料加载成功回调，建议在此回调方法中进行数据的插入处理，建议在该回调方法中统计您的请求成功数
 | jadNativeAdDidLoadFailure:error: | 返回错误码（error）标识广告加载失败的原因
 | jadNativeAdDidExposure: | 有效曝光回调，建议在该回调方法中统计您的曝光数
 | jadNativeAdDidClick:withView: | 点击回调方法，建议在该回调方法中统计您的点击数
 | jadNativeAdDidClose:withView: | 关闭回调方法
 | jadNativeAdDidCloseOtherController:interactionType: |  跳转页关闭回调
 | jadNativeAdForSplash:countDown: | 倒计时回调
 
*/
@protocol JADNativeAdDelegate <NSObject>

@required

/**
 * @brief 加载成功回调
 * @discussion 广告数据：加载成功
 *
 * This method is called when native ad material loaded successfully.
 */
- (void)jadNativeAdDidLoadSuccess:(JADNativeAd *)nativeAd;

/**
 * @brief 加载失败回调
 * @param error : the reason of error
 * @discussion 广告数据：加载失败
 *
 * This method is called when native ad materia failed to load.
 */
- (void)jadNativeAdDidLoadFailure:(JADNativeAd *)nativeAd error:(NSError *__nullable)error;

/**
 * @brief 有效曝光成功回调
 * @discussion  广告视图：有效曝光
 *
 * This method is called when native ad slot has been shown.
 */
- (void)jadNativeAdDidExposure:(JADNativeAd *)nativeAd;

/**
 * @brief 点击事件回调
 * @discussion 广告视图：点击
 *
 * This method is called when native ad is clicked.
 */
- (void)jadNativeAdDidClick:(JADNativeAd *)nativeAd withView:(UIView *_Nullable)view;

/**
 * @brief 关闭事件回调
 * @discussion 广告视图：关闭
 *
 * This method is called when native ad is closed.
 */
- (void)jadNativeAdDidClose:(JADNativeAd *)nativeAd withView:(UIView *_Nullable)view;

/**
 * @brief 跳转页关闭回调
 * @param interactionType ： open AppStore in app or open the webpage
 * @discussion 当跳转落地页关闭时回调
 *
 * This method is called when another controller has been closed.
 */
- (void)jadNativeAdDidCloseOtherController:(JADNativeAd *)nativeAd
                           interactionType:(JADInteractionType)interactionType;

@optional

/**
 * @brief 倒计时回调
 * @discussion 广告视图：开屏倒计时时间回调
 *
 * This method is called when splash native ad is delay action.
 */
- (void)jadNativeAdForSplash:(JADNativeAd *)nativeAd countDown:(int)countDown;

@end

NS_ASSUME_NONNULL_END

