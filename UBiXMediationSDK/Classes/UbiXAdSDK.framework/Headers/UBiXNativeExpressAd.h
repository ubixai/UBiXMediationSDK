//
//  UBiXNativeAd.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/6/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UBiXNativeExpressAd;
@class UBiXNativeExpressAdView;

@protocol UBiXNativeExpressAdDelegate <NSObject>
@optional
/**
 *  广告请求成功
 */
- (void)ubixNativeExpressAdDidLoad:(UBiXNativeExpressAd *)nativeExpressAd;

/**
 *  广告请求失败
 *  @param error 失败原因
 */
- (void)ubixNativeExpressAdFailedToLoad:(UBiXNativeExpressAd *)nativeExpressAd withError:(NSError *)error;
@end

/**
 * 信息流模版广告
 */
@interface UBiXNativeExpressAd : NSObject
/// 当前广告位id
@property (nonatomic, copy, readonly) NSString *placementId;

/// 回调委托对象
@property (nonatomic, weak) id<UBiXNativeExpressAdDelegate> delegate;

/// 模板views，在ubixNativeExpressAdDidLoad回调后有值
@property (nonatomic, strong, readonly, nullable) NSArray <UBiXNativeExpressAdView *> *nativeExpressAdViews;

/**
 *  构造方法
 *  @param placementId 广告位ID
 */
- (instancetype)initWithPlacementId:(NSString *)placementId adSize:(CGSize)adSize;

/**
 *  加载1条广告
 */
- (void)loadAd;

/**
 * 加载多条广告, 建议最多3条
 */
- (void)loadAdsWithCount:(int)count;
@end

NS_ASSUME_NONNULL_END
