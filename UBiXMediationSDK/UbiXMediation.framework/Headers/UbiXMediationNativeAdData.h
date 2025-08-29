//
//  UbiXMediationNativeAdData.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/7.
//

#ifndef UbiXMediationNativeAdData_h
#define UbiXMediationNativeAdData_h

#import "UbiXMImage.h"
#import "UbiXMDislikeReason.h"

typedef NS_ENUM (NSInteger, UbiXMediationNativeAdCallToType) {
    UbiXMediationNativeAdCallToTypeUnknown        = 0,
    UbiXMediationNativeAdCallToTypeNone           = 1,  // pure ad display
    UbiXMediationNativeAdCallToTypeURL            = 2,  // open the webpage using a browser
    UbiXMediationNativeAdCallToTypePage           = 3,  // open the webpage within the app
    UbiXMediationNativeAdCallToTypeDownload       = 4,  // download the app
    UbiXMediationNativeAdCallToTypePhone          = 5,  // make a call
    UbiXMediationNativeAdCallToTypeMessage        = 6,  // send messages
    UbiXMediationNativeAdCallToTypeEmail          = 7,  // send email
    UbiXMediationNativeAdCallToTypeVideoAdDetail  = 8,   // video ad details page
    UbiXMediationNativeAdCallToTypeOthers         = 100 //其他广告sdk返回的类型
};

typedef NS_ENUM (NSInteger, UbiXMediationNativeAdMode) {
    UbiXMediationNativeAdModeUnknown          = 00, // 未知
    UbiXMediationNativeAdModeSmallImage       = 02, // 水平小图样式
    UbiXMediationNativeAdModeLargeImage       = 03, // 水平大图样式
    UbiXMediationNativeAdModeGroupImage       = 04, // 水平组图样式
    UbiXMediationNativeAdModeLandscapeVideo   = 05, // 水平视频样式
    UbiXMediationNativeAdModePortraitVideo    = 15, // 垂直视频样式
    UbiXMediationNativeAdModePortraitImage    = 16, // 垂直图片样式
};

typedef UbiXMediationNativeAdMode;

/// 媒体native ad数据协议，配合UbiXMediationNativeAdViewCreator使用
@protocol UbiXMediationNativeAdData <NSObject>

/// 广告支持的跳转类型
@property (nonatomic, assign, readonly) UbiXMediationNativeAdCallToType callToType;

/// 物料图片集，如果图片有宽高，请尽量配置width和height
@property (nonatomic, copy, readonly, nullable) NSArray<UbiXMImage *> *imageList;

/// app类型广告的广告商app图标，如果图标有宽高，请尽量配置width和height
@property (nonatomic, strong, readonly, nullable) UbiXMImage *icon;

/// 广告adn的logo，如果logo有宽高，请尽量配置width和height
@property (nonatomic, strong, readonly, nullable) UbiXMImage *adLogo;

/// 广告标题
@property (nonatomic, copy, readonly, nullable) NSString *adTitle;

/// 广告详情描述
@property (nonatomic, copy, readonly, nullable) NSString *adDescription;

/// 应用来源、市场，例如'App Store'
@property (nonatomic, copy, readonly, nullable) NSString *source;

/// 按钮文案，例如'下载/安装'
@property (nonatomic, copy, readonly, nullable) NSString *buttonText;

/// 图片/视频模式
@property (nonatomic, assign, readonly) UbiXMediationNativeAdMode imageMode;

/// app评分，区间为1-5，如果没有值返回-1
@property (nonatomic, assign, readonly) NSInteger score;

/// 评论数量，如果没有值返回-1
@property (nonatomic, assign, readonly) NSInteger commentNum;

/// 广告安装包体大小，单位KB，如果没有值返回-1
@property (nonatomic, assign, readonly) NSInteger appSize;

/// 视频时长，单位秒，如果没有值返回0
@property (nonatomic, assign, readonly) NSInteger videoDuration;

/// 视频纵横比(width/height)，如果没有值或者异常返回0
@property (nonatomic, assign, readonly) CGFloat videoAspectRatio;

/// 媒体扩展数据
@property (nonatomic, copy, readonly, nullable) NSDictionary *mediaExt;

/// app购买价格，例如'免费'，没有则为nil
@property (nonatomic, strong, readonly, nullable) NSString *appPrice;

/// 广告商标识，广告商的名称或者链接
@property (nonatomic, copy, readonly, nullable) NSString *advertiser;

/// 品牌名称，若广告返回中无品牌名称则为空
@property (copy, nonatomic, readonly, nullable) NSString *brandName;

/// ADN提供的不喜欢广告的原因，可能为空
@property (nonatomic, copy, readonly, nullable) NSArray<UbiXMDislikeReason *> *dislikeReasons;

/// ADN提供的视频类型广告的资源路径，部分ADN需要申请白名单，可能为空
@property (nonatomic, copy, readonly, nullable) NSString *videoUrl;

@optional
/// be allowed to play video ad via custome player, contact BD to add to allow list.
@property (nonatomic, assign, readonly) BOOL allowCustomVideoPlayer;

/// video resolution width
@property (nonatomic, assign, readonly) NSInteger videoResolutionWidth;

/// video resolution height
@property (nonatomic, assign, readonly) NSInteger videoResolutionHeight;

/// adx name, if it exists, it is recommended to display this text
@property (nonatomic, copy, nullable) NSString *ADXName;

@end

#endif /* UbiXMediationNativeAdData_h */
