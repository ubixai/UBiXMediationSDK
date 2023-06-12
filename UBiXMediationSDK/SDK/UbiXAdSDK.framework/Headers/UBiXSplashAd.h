//
//  UBiXSplashAd.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/6/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UBiXAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class UBiXSplashAd;
@protocol UBiXSplashAdDelegate <NSObject>
@optional
/**
 *  广告请求成功，并且素材加载完成，在此选择调用showAd来展示广告
 */
- (void)ubixSplashAdDidLoad:(UBiXSplashAd *)splashAd;

/**
 *  广告请求失败
 *  @param error 失败原因
 */
- (void)ubixSplashAdFailedToLoad:(UBiXSplashAd *)splashAd withError:(NSError *)error;

/**
 *  广告即将展示
 */
- (void)ubixSplashAdWillShow:(UBiXSplashAd *)splashAd;

/**
 *  广告展示完毕
 */
- (void)ubixSplashAdDidShow:(UBiXSplashAd *)splashAd;

/**
 *  广告展示失败，未能正确显示在屏幕上: 如调用showAd时，window不是keywindow
 *  @param error 失败原因
 */
- (void)ubixSplashAdFailedToShow:(UBiXSplashAd *)splashAd withError:(NSError *)error;
/**
 *  广告点击回调
 */
- (void)ubixSplashAdDidClick:(UBiXSplashAd *)splashAd;

/**
 * 广告点击跳过的回调
 */
- (void)ubixSplashAdDidClickSkip:(UBiXSplashAd *)splashAd;

/**
 *  广告关闭回调：跳过/倒计时结束/点击广告后广告view被移除
 */
- (void)ubixSplashAdDidClose:(UBiXSplashAd *)splashAd;

/**
 *  广告转化完成：关闭落地页或者跳转到其他应用
 */
- (void)ubixSplashAdDidFinishConversion:(UBiXSplashAd *)splashAd interactionType:(UBiXAdInteractionType)interactionType;
@end

/**
 * 开屏广告对象，需强持有
 */
@class UBiXAdReviewParams;
@interface UBiXSplashAd : NSObject
/// 当前广告的广告位id
@property (nonatomic, copy, readonly) NSString *placementId;

/// 回调委托对象
@property (nonatomic, weak) id<UBiXSplashAdDelegate> delegate;

/// @required 用于打开落地页，确保ta当前无presentedVC，否则将无法打开落地页
@property (nonatomic, weak) UIViewController *rootViewController;

/// 当前广告是否有效，show前检查
@property (nonatomic, assign, readonly, getter=isValid) BOOL valid;

/// 设置加载广告超时时长(秒)，默认为5秒
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

/// 素材审核用
@property (nonatomic, strong, readonly) UBiXAdReviewParams *reviewParams;
/**
 *  构造方法
 *  @param placementId 广告位ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 *  展示开屏广告
 *  @param window 展示开屏广告的UIWindow
 *  @param bottomView 开发者自定义底部logo，建议高度不超过屏幕高度的1/4
 *  曝光时，请确保window.rootViewController无presentedVC，否则影响广告展示、点击、落地页打开
 */
- (void)showAdToWindow:(UIWindow *)window bottomView:(UIView * _Nullable)bottomView;

/**
 * 获取广告价格，单位(分)
 */
- (NSInteger)eCPM;

// ------ bidding ------ //
/**
 * 获取bidding token
 * 需要在主线程获取，否则获取失败
 */
- (NSString *)getBiddingToken;

/**
 * 加载bidding广告
 * @param adm 服务器返回的json字符串 @"{\"messge\":\"Cia...\",\"request_id\":\3af4..."\",\"auction_price\":\"320\"}"
 */
- (void)loadBiddingAd:(NSString *)adm;
// --------------------- //
@end

NS_ASSUME_NONNULL_END
