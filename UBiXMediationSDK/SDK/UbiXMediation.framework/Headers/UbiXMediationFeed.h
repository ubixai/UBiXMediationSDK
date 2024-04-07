//
//  UbiXMediationNative.h
//  UbiXMediation
//
//  Created by stefan.qi on 2022/7/11.
//

#import <UIKit/UIKit.h>
#import <UbiXMediation/UbiXMediationFeedAdView.h>
#import <UbiXMediation/UbiXMediationMaterialData.h>
#import <UbiXMediation/UbiXMediationMediaView.h>
#import <UbiXMediation/UbiXMedationFeedAdModel.h>
#import <UbiXMediation/UbiXMediationAdView.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    UbiXMFeedRenderTypeNone                    = 0,   /*未知<默认值>*/
    UbiXMFeedRenderTypeSelfRender              = 1,   /*自渲染*/
    UbiXMFeedRenderTypeTemplate                = 2,   /*模板渲染*/
}UbiXMFeedRenderType;

@protocol UbiXMediationFeedDelegate;
@protocol UbiXMediationFeedAdViewDelegate;

@interface UbiXMediationFeed : UbiXMediationAdView

@property (nonatomic, weak)id<UbiXMediationFeedDelegate, UbiXMediationFeedAdViewDelegate> delegate;

// 信息流渲染方式
@property (nonatomic, assign)UbiXMFeedRenderType renderType;

// load前需要设置好所有参数
- (void)loadAdWithAdSize:(CGSize)adSize;
// 销毁广告
- (void)destroyAd;

/// 广告是否准备好
- (BOOL)isReady;
/// 广告是否有效
- (BOOL)isAvaliable;

/** 设置可以点击和关闭的图层 */
- (void)setContainer:(UIView *)containerView clickableViews:(NSArray *)clickableViews closableViews:(NSArray *)closableViews;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

@end


@protocol UbiXMediationFeedDelegate <NSObject>

// 原生广告加载成功
- (void)mediationFeedDidLoad:(NSArray<UbiXMedationFeedAdModel *> *)feedAds;

// 原生广告加载失败回调
- (void)mediationFeedDidFailToLoad:(UbiXMediationFeed *)native error:(NSError *)error;

@end


NS_ASSUME_NONNULL_END
