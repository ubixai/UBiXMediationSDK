//
//  UbixNativeAd.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/7/13.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

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
 */
- (instancetype)initWithPlacementId:(NSString *)placementId;

/**
 * 加载1条广告
 */
- (void)loadAd;

/**
 * 加载多条广告, 建议最多3条
 */
- (void)loadAdsWithCount:(int)count;
@end

NS_ASSUME_NONNULL_END
