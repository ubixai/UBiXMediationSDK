//
//  UbiXMediationInterstitial.h
//  UbiXMediation
//
//  Created by stefan.qi on 2022/8/18.
//

#import <Foundation/Foundation.h>
#import <UbiXMediation/UbiXMediationObject.h>

NS_ASSUME_NONNULL_BEGIN

@class UbiXMediationInterstitial;

@protocol UbiXMediationInterstitialDelegate <NSObject>

@optional

// 插屏广告模板加载成功
- (void)mediationInterstitialDidLoad:(UbiXMediationInterstitial *)interstitial;

// 插屏加载失败回调
- (void)mediationInterstitialDidFailToLoad:(UbiXMediationInterstitial *)interstitial error:(NSError *)error;

// 插屏广告展示成功
- (void)mediationInterstitialDidShow:(UbiXMediationInterstitial *)interstitial;

// 插屏广告展示失败
- (void)mediationInterstitialDidFailToShow:(UbiXMediationInterstitial *)interstitial error:(NSError *)error;

// 插屏点击广告回调
- (void)mediationInterstitialDidClick:(UbiXMediationInterstitial *)interstitial;

// 插屏关闭广告回调
- (void)mediationInterstitialDidClosed:(UbiXMediationInterstitial *)interstitial;


@end

@interface UbiXMediationInterstitial : UbiXMediationObject

@property (nonatomic, weak)id<UbiXMediationInterstitialDelegate> delegate;

// 点击后关闭插屏广告，默认不关闭
@property (nonatomic, assign)BOOL closeAfterClick;;

// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;

/** 加载广告 */
- (void)loadAd;

/** 展示广告并设置图层 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

/** 广告是否可用 */
- (BOOL)isReady;

/// 广告是否有效
- (BOOL)isAvaliable;


/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

@end

NS_ASSUME_NONNULL_END
