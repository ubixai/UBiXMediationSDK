//
//  UbixNativeAd.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/7/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UBiXAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class UBiXNativeAd;
@protocol UBiXNativeAdDelegate <NSObject>
@optional
/**
 * 广告请求成功
 */
- (void)ubixNativeAdDidLoad:(UBiXNativeAd *)nativeAd;

/**
 * 广告请求失败
 * @param error 失败原因
 */
- (void)ubixNativeAdFailedToLoad:(UBiXNativeAd *)nativeAd withError:(NSError *)error;
@end

/**
 * 信息流自渲染广告
 */
@class UBiXNativeAdObject;
@interface UBiXNativeAd : NSObject
/// 当前广告位id
@property (nonatomic, copy, readonly)NSString *placementId;

/// 回调委托对象
@property (nonatomic, weak) id<UBiXNativeAdDelegate> delegate;

/// 广告对象，在ubixNativeAdDidLoad回调后有值
@property (nonatomic, strong, readonly, nullable) NSArray <UBiXNativeAdObject *> *nativeAdObjects;

/**
 *  构造方法
 *  @param placementId 广告位ID
 *  默认广告类型adType = UBiXNativeAdType_Native
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 *  构造方法 v2.3.1新增
 *  @param placementId 广告位ID
 *  @param adType 广告类型
 */
- (instancetype)initWithPlacementId:(NSString *)placementId adType:(UBiXNativeAdType)adType;

/**
 * 加载1条广告
 */
- (void)loadAd;

/**
 * 加载多条广告, 建议最多3条
 */
- (void)loadAdsWithCount:(int)count;

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
