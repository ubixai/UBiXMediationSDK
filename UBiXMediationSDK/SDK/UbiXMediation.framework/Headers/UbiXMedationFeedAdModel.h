//
//  UbiXMedationFeedAdModel.h
//  UbiXMediation
//
//  Created by stefan.qi on 2023/1/3.
//

#import <Foundation/Foundation.h>
#import <UbiXMediation/UbiXMediationFeedAdView.h>
#import <UbiXMediation/UbiXMediationMaterialData.h>
#import <UbiXMediation/UBiXMFeedbackIconView.h>

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMedationFeedAdModel : NSObject

/// 是否是模板广告
@property (nonatomic, assign) BOOL isExpressAd;

/// 是否是视频广告
@property (nonatomic, assign) BOOL isVideoAd;

/// 信息流广告图层
@property (nonatomic, strong) UbiXMediationFeedAdView *feedAdView;

/// 信息流广告数据
@property (nonatomic, strong) UbiXMediationMaterialData *feedAdMaterialData;

/// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;

/// 绑定点击事件图层
- (void)setContainer:(UIView *)containerView clickableViews:(NSArray *)clickableViews closableViews:(NSArray *)closableViews;

/// 获取用户反馈按钮View，方便媒体在自渲染模式下支持用户反馈
- (UBiXMFeedbackIconView *)getFeedbackView;

- (void)unregistViews;

@end

NS_ASSUME_NONNULL_END
