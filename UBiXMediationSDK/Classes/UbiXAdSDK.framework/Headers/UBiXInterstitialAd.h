//
//  UBiXInterstitialAd.h
//  UbiXAdSDK
//
//  Created by fei.li on 2022/12/30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UBiXAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class UBiXInterstitialAd;
@protocol UBiXInterstitialAdDelegate <NSObject>
@optional
/**
 * 广告请求成功
 */
- (void)ubixInterstitialAdDidLoad:(UBiXInterstitialAd *)interstitialAd;

/**
 * 广告请求失败
 * @param error 失败原因
 */
- (void)ubixInterstitialAdFailedToLoad:(UBiXInterstitialAd *)interstitialAd withError:(NSError *)error;

/**
 * 广告将要展示
 */
- (void)ubixInterstitialAdWillShow:(UBiXInterstitialAd *)interstitialAd;

/**
 * 广告展示成功
 */
- (void)ubixInterstitialAdDidShow:(UBiXInterstitialAd *)interstitialAd;

/**
 * 广告展示失败，未能展示在屏幕上
 * @param error 失败原因
 */
- (void)ubixInterstitialAdFailedToShow:(UBiXInterstitialAd *)interstitialAd withError:(NSError *)error;

/**
 * 广告点击
 */
- (void)ubixInterstitialAdDidClick:(UBiXInterstitialAd *)interstitialAd;

/**
 * 广告关闭
 */
- (void)ubixInterstitialAdDidClose:(UBiXInterstitialAd *)interstitialAd;

/**
 * 广告转化完成：关闭落地页或者跳转到其他应用
 */
- (void)ubixInterstitialAdDidFinishConversion:(UBiXInterstitialAd *)interstitialAd interactionType:(UBiXAdInteractionType)interactionType;
@end

@interface UBiXInterstitialAd : NSObject
/// 当前广告的广告位id
@property (nonatomic, copy, readonly) NSString *placementId;

/// 回调委托对象
@property (nonatomic, weak) id<UBiXInterstitialAdDelegate> delegate;

/// 当前广告是否有效，show前检查
@property (nonatomic, assign, readonly, getter=isValid) BOOL valid;

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
 *  @param rootViewController 展示开屏广告的UIViewController
 *  曝光时，请确保rootViewController无presentedVC，否则影响广告展示、点击、落地页打开
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

/**
 * 获取广告价格，单位(分)
 */
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
