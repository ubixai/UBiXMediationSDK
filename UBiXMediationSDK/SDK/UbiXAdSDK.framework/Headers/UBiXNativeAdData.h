//
//  UBiXNativeAdData.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/7/13.
//

#import <Foundation/Foundation.h>
#import "UBiXAdSDKDefines.h"

/**
 * 图片创意信息
 */
@interface UBiXNativeAdDataImage : NSObject
/// 素材地址
@property (nonatomic, copy, readonly) NSString *imageUrl;
/// 宽
@property (nonatomic, assign, readonly) int width;
/// 高
@property (nonatomic, assign, readonly) int height;
@end


/**
 * 视频类创意信息
 */
@interface UBiXNativeAdDataVideoAdInfo : NSObject
/// 视频素材地址
@property (nonatomic, copy, readonly) NSString *videoUrl;
/// 封面图地址
@property (nonatomic, copy, readonly) NSString *coverImageUrl;
/// 视频时长(s)
@property (nonatomic, assign, readonly) float duration;
@end


/**
 * 下载类信息
 */
__attribute__((deprecated("It will be removed in a future version")))
@interface UBiXNativeAdDataDownloadAdInfo : NSObject
/// app名称
@property (nonatomic, copy, readonly) NSString *name;
/// app描述
@property (nonatomic, copy, readonly) NSString *desc;
/// 版本号
@property (nonatomic, copy, readonly) NSString *version;
/// 开发者
@property (nonatomic, copy, readonly) NSString *publisher;
/// 隐私链接
@property (nonatomic, copy, readonly) NSString *privacyUrl;
/// 权限链接
@property (nonatomic, copy, readonly) NSString *permissionUrl;
/// icon
@property (nonatomic, copy, readonly) NSString *iconUrl;
@end


/**
 * 广告素材
 */
@interface UBiXNativeAdData : NSObject
/// 广告标题
@property (nonatomic, copy, readonly) NSString *title;

/// 广告描述
@property (nonatomic, copy, readonly) NSString *desc;

/// 广告来源
@property (nonatomic, copy, readonly) NSString *source;

/// 按钮文案
@property (nonatomic, copy, readonly) NSString *callToAction;

/// 广告创意图标
@property (nonatomic, copy, readonly) NSString *iconUrl;

/// 广告图片素材地址
@property (nonatomic, strong, readonly) NSArray <NSString *>*imageUrls;

/// 广告图片素材
@property (nonatomic, strong, readonly) NSArray <UBiXNativeAdDataImage *>*images;

/// 是否是视频类广告
@property (nonatomic, assign, readonly) BOOL isVideoAd;
// @property (nonatomic, assign, getter=isVideoAd) BOOL videoAd;

/// 视频类素材描述
@property (nonatomic, strong, readonly) UBiXNativeAdDataVideoAdInfo *videoAdInfo;

/// 是否下载类广告
@property (nonatomic, assign, readonly) BOOL isDownloadAd __attribute__((deprecated("Useless. It will be removed in a future version")));
//@property (nonatomic, assign, getter=isDownloadAd) BOOL downloadAd;

/// 下载类信息描述
@property (nonatomic, strong, readonly) UBiXNativeAdDataDownloadAdInfo *downloadAdInfo __attribute__((deprecated("Useless. It will be removed in a future version")));

/// 应用名称
@property (nonatomic, copy, readonly) NSString *appName;

/// 应用描述
@property (nonatomic, copy, readonly) NSString *appDesc;

/// 应用版本
@property (nonatomic, copy, readonly) NSString *appVersion;

/// 应用开发者
@property (nonatomic, copy, readonly) NSString *appPublisher;

/// 隐私协议
@property (nonatomic, copy, readonly) NSString *privacyUrl;

/// 权限声明
@property (nonatomic, copy, readonly) NSString *permissionUrl;
@end
