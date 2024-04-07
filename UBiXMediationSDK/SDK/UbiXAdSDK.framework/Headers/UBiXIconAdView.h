//
//  UBiXIconAdView.h
//  UbiXAdSDK
//
//  Created by fei.li on 2024/1/10.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "UBiXAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class UBiXIconAdView;
@protocol UBiXIconAdViewDelegate <NSObject>
/**
 * 广告请求成功，并且素材加载完成。
 */
- (void)ubixIconAdViewDidLoad:(UBiXIconAdView *)iconAdView;

/**
 * 广告请求失败
 * @param error 失败原因
 */
- (void)ubixIconAdViewFailedToLoad:(UBiXIconAdView *)iconAdView withError:(NSError *)error;

/**
 * 广告展示成功
 */
- (void)ubixIconAdViewDidShow:(UBiXIconAdView *)iconAdView;

/**
 * 广告点击
 */
- (void)ubixIconAdViewDidClick:(UBiXIconAdView *)iconAdView;

/**
 * 广告关闭，代表的是点击了关闭按钮
 */
- (void)ubixIconAdViewDidClose:(UBiXIconAdView *)iconAdView;

/**
 * 广告转化完成：关闭落地页或者跳转到其他应用
 */
- (void)ubixIconAdViewDidFinishConversion:(UBiXIconAdView *)iconAdView interactionType:(UBiXAdInteractionType)interactionType;
@end


/**
 * icon广告对象，需被强引用
 */
@interface UBiXIconAdView : UIView
/// 当前广告的广告位id
@property (nonatomic, copy, readonly) NSString *placementId;

/// 回调委托对象
@property (nonatomic, weak) id<UBiXIconAdViewDelegate> delegate;

/// @required 用于打开落地页，确保ta当前无presentedVC，否则将无法打开落地页
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 * 初始化
 * @param placementId 广告位id
 * @param adSize 广告size 建议80x80。取最小边长构造正方形view，宽或高范围60-100
 */
- (instancetype)initWithPlacementId:(NSString *)placementId
                             adSize:(CGSize)adSize;

/**
 *  加载广告
 */
- (void)loadAd;

/**
 * 获取当前曝光的广告价格，单位(分)
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
