//
//  UbiXMediationMaterialData.h
//  UbiXMediation
//
//  Created by stefan.qi on 2022/8/11.
//

#import <Foundation/Foundation.h>
#import <UbiXMediation/UbiXMediationPasterReporter.h>
#import "UbiXMediationNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMediationMaterialData : NSObject

/// 标题
@property (nonatomic, copy) NSString *title;

/// 副标题
@property (nonatomic, copy) NSString *body;

/// icon图片下载链接
@property (nonatomic, copy) NSString *iconUrl;

/// 点击按钮文案
@property (nonatomic, copy) NSString *callToAction;

/// App Store评分
@property (nonatomic, assign) double rating;

/// 素材地址
@property (nonatomic, strong) NSArray <NSString *> *imageUrls;

@property (nonatomic, assign) BOOL rendering;

/// 是否是视频素材的广告
@property (nonatomic, assign) BOOL isVideoAd;

/// 视频时长
@property (nonatomic, assign) NSInteger videoDuration;
/// 视频地址
@property (nonatomic, copy) NSString *videoUrl;

/// 广告附属字段
@property (nonatomic, assign) NSInteger adSourcetype;

/// 广告状态上报对象
@property (nonatomic, strong) UbiXMediationPasterReporter *reporter;

/// 给开发者的出价
@property(nonatomic, assign) NSInteger adBidPrice;

/// 广告源名称
@property (nonatomic, copy) NSString *adSourceName;

@property (nonatomic, strong) UbiXMediationNativeAd *customAdnNativeAd;

@end

NS_ASSUME_NONNULL_END
