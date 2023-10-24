//
//  UbiXMediationBanner.h
//  UbiXMediation
//
//  Created by stefan.qi on 2022/9/1.
//

#import <UIKit/UIKit.h>
#import <UbiXMediation/UbixMediationAdView.h>

NS_ASSUME_NONNULL_BEGIN

@class UbiXMediationBanner;

@protocol UbiXMediationBannerDelegate <NSObject>

@optional
// banner广告加载成功
- (void)mediationBannerDidLoad:(UbiXMediationBanner *)banner;

// banner广告展示成功
- (void)mediationBannerDidShow:(UbiXMediationBanner *)banner;

// banner广告加载失败回调
- (void)mediationBannerDidFailToLoad:(UbiXMediationBanner *)banner error:(NSError *)error;

// banner点击广告回调
- (void)mediationBannerDidClick:(UbiXMediationBanner *)banner;

// banner移除广告回调
- (void)mediationBannerDidClose:(UbiXMediationBanner *)banner;


@end

@interface UbiXMediationBanner : UbiXMediationAdView

@property (nonatomic, weak)id<UbiXMediationBannerDelegate> delegate;

@property (nonatomic, weak) UIViewController *rootViewController;

// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;

/**
 根据广告尺寸加载广告
 load前确定好rootViewController, 用于present落地页
 */
- (void)loadAdWithAdSize:(CGSize)adSize;

/** 广告是否可用 */
- (BOOL)isReady;
/** 广告是否有效 */
- (BOOL)isAvaliable;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

// 销毁广告
- (void)destory;

@end

NS_ASSUME_NONNULL_END
