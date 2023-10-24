//
//  UBiXNativeAdData.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/7/13.
//

#import <Foundation/Foundation.h>
#import "UBiXAdSDKDefines.h"

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

/// 广告图片素材地址
@property (nonatomic, strong, readonly) NSArray <NSString *>*imageUrls;

/// 是否是视频类广告
@property (nonatomic, assign, readonly) BOOL isVideoAd;
// @property (nonatomic, assign, getter=isVideoAd) BOOL videoAd;

/// 视频类素材描述
@property (nonatomic, strong, readonly) UBiXNativeAdDataVideoAdInfo *videoAdInfo;

/// 是否下载类广告
@property (nonatomic, assign, readonly) BOOL isDownloadAd;
//@property (nonatomic, assign, getter=isDownloadAd) BOOL downloadAd;

/// 下载类信息描述
@property (nonatomic, strong, readonly) UBiXNativeAdDataDownloadAdInfo *downloadAdInfo;
@end
