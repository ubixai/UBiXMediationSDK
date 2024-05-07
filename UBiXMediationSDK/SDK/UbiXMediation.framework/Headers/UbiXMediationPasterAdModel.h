//
//  UbiXMediationPasterAdModel.h
//  UbiXMediation
//
//  Created by stefan.qi on 2023/1/4.
//

#import <Foundation/Foundation.h>
#import <UbiXMediation/UbiXMediationMediaView.h>
#import <UbiXMediation/UbiXMediationMaterialData.h>

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMediationPasterAdModel : NSObject

/// 是否是模板广告
@property (nonatomic, assign) BOOL isExpressAd;

/// 是否是视频广告
@property (nonatomic, assign) BOOL isVideoAd;

/// 是否需要传入自定义播放器
@property (nonatomic, assign) BOOL isNeedCustomerPlayer;

/// 贴片广告图层
@property (nonatomic, strong) UbiXMediationMediaView *pasterAdView;

/// 贴片广告图层素材
@property (nonatomic, strong) UbiXMediationMaterialData *pasterAdMaterialData;

// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;

- (void)unregistViews;


@end

NS_ASSUME_NONNULL_END
