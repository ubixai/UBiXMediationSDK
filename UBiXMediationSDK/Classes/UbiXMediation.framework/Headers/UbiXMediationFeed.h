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

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    UbiXMFeedRenderTypeNone                    = 0,   /*未知<默认值>*/
    UbiXMFeedRenderTypeSelfRender              = 1,   /*自渲染*/
    UbiXMFeedRenderTypeTemplate                = 2,   /*模板渲染*/
}UbiXMFeedRenderType;

@protocol UbiXMediationFeedDelegate;
@protocol UbiXMediationFeedAdViewDelegate;

@interface UbiXMediationFeed : UIView

@property (nonatomic, weak)id<UbiXMediationFeedDelegate, UbiXMediationFeedAdViewDelegate> delegate;

@property (nonatomic, copy)NSString *slotId;

// 信息流渲染方式
@property (nonatomic, assign)UbiXMFeedRenderType renderType;

// 展示落地页的controller, 如果不传默认使用keyWindow.rootVC
@property (nonatomic, weak)UIViewController *rootViewController;

/// 根据slotModel信息初始化开屏对象
- (instancetype) initWithSlotId:(NSString *)slotId;

// load前需要设置好所有参数
- (void)loadAdWithAdSize:(CGSize)adSize;

/// 广告是否准备好
- (BOOL)isReady;
/// 广告是否有效
- (BOOL)isAvaliable;

/// 移除广告
- (void)removeAd;

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
