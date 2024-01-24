//
//  UBiXRewardedVideoAd.h
//  UBiXAdSDK
//
//  Created by fei.li on 2022/12/20.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UBiXAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class UBiXRewardedVideoAd;
@protocol UBiXRewardedVideoAdDelegate <NSObject>
@optional
/**
 * 广告请求成功
 * 若此时调用show，将会在线进行播放；为提高用户体验，建议在视频缓存后再进行show。
 */
- (void)ubixRewardedVideoAdDidLoad:(UBiXRewardedVideoAd *)rewardedVideoAd;

/**
 * 广告请求失败
 * @param error 失败原因
 */
- (void)ubixRewardedVideoAdFailedToLoad:(UBiXRewardedVideoAd *)rewardedVideoAd withError:(NSError *)error;

/**
 * 广告视频资源缓存成功
 * 为得到更好的体验，建议此时调用show
 */
- (void)ubixRewardedVideoAdDidCache:(UBiXRewardedVideoAd *)rewardedVideoAd;

/**
 * 广告视频资源缓存失败
 * @param error 失败原因
 */
- (void)ubixRewardedVideoAdFailedToCache:(UBiXRewardedVideoAd *)rewardedVideoAd withError:(NSError *)error;

/**
 * 广告将要展示
 */
- (void)ubixRewardedVideoAdWillShow:(UBiXRewardedVideoAd *)rewardedVideoAd;

/**
 * 广告展示成功
 */
- (void)ubixRewardedVideoAdDidShow:(UBiXRewardedVideoAd *)rewardedVideoAd;

/**
 * 广告展示失败，未能展示在屏幕上
 * @param error 失败原因
 */
- (void)ubixRewardedVideoAdFailedToShow:(UBiXRewardedVideoAd *)rewardedVideoAd withError:(NSError *)error;

/**
 * 广告点击
 */
- (void)ubixRewardedVideoAdDidClick:(UBiXRewardedVideoAd *)rewardedVideoAd;

/**
 * 广告关闭
 */
- (void)ubixRewardedVideoAdDidClose:(UBiXRewardedVideoAd *)rewardedVideoAd;

/**
 * 广告转化完成：关闭落地页或者跳转到其他应用
 */
- (void)ubixRewardedVideoAdDidFinishConversion:(UBiXRewardedVideoAd *)rewardedVideoAd interactionType:(UBiXAdInteractionType)interactionType;

/**
 * 视频开始播放
 */
- (void)ubixRewardedVideoAdStartPlay:(UBiXRewardedVideoAd *)rewardedVideoAd;

/**
 * 视频播放结束，中途可能会播放失败
 * @param error 失败原因
 */
- (void)ubixRewardedVideoAdDidPlayFinish:(UBiXRewardedVideoAd *)rewardedVideoAd withError:(NSError * _Nullable)error;

/**
 * 广告激励发放
 */
- (void)ubixRewardVideoAdDidRewardEffective:(UBiXRewardedVideoAd *)rewardedVideoAd;
@end

/**
 * 激励视频广告对象，需强持有
 */
@interface UBiXRewardedVideoAd : NSObject
/// 当前广告的广告位id
@property (nonatomic, copy, readonly) NSString *placementId;

/// 回调委托对象
@property (nonatomic, weak) id<UBiXRewardedVideoAdDelegate> delegate;

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

// ------ bidding ------ //
/**
 * 获取bidding token
 * 需要在主线程获取，否则获取失败
 */
- (nullable NSString *)getBiddingToken;

/**
 * 加载bidding广告
 * @param adm 服务器返回的json字符串 @"{\"messge\":\"Cia...\",\"request_id\":\3af4..."\",\"auction_price\":\"320\"}"
 */
- (void)loadBiddingAd:(NSString *)adm;
// --------------------- //
@end

NS_ASSUME_NONNULL_END
