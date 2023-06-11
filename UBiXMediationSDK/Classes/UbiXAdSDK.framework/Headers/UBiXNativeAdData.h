//
//  UBiXNativeAdData.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/7/13.
//

#import <Foundation/Foundation.h>
#import "UBiXAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 视频类创意信息
 */
@interface UBiXNativeAdDataVideoAdInfo : NSObject
/// 视频素材地址
@property (nonatomic, copy) NSString *videoUrl;
/// 视频时长
@property (nonatomic, assign) float duration;
/// 封面图地址
@property (nonatomic, copy) NSString *coverImageUrl;
@end


/**
 * 下载类信息
 */
@interface UBiXNativeAdDataDownloadAdInfo : NSObject
/// app名称
@property (nonatomic, copy) NSString *name;
/// app描述
@property (nonatomic, copy) NSString *desc;
/// 版本号
@property (nonatomic, copy) NSString *version;
/// 开发者
@property (nonatomic, copy) NSString *publisher;
/// 隐私链接
@property (nonatomic, copy) NSString *privacyUrl;
/// 权限链接
@property (nonatomic, copy) NSString *permissionUrl;
/// icon
@property (nonatomic, copy) NSString *iconUrl;
@end


/**
 * 广告素材
 */
@interface UBiXNativeAdData : NSObject
/// 广告标题
@property (nonatomic, copy) NSString *title;

/// 广告描述
@property (nonatomic, copy) NSString *desc;

/// 广告来源
@property (nonatomic, copy) NSString *source;

/// 按钮文案
@property (nonatomic, copy) NSString *callToAction;

/// 广告图片素材地址
@property (nonatomic, strong) NSArray <NSString *>*imageUrls;

/// 是否是视频类广告
@property (nonatomic, assign, getter=isVideoAd) BOOL videoAd;

/// 视频类素材描述
@property (nonatomic, strong) UBiXNativeAdDataVideoAdInfo *videoAdInfo;

/// 是否下载类广告
@property (nonatomic, assign, getter=isDownloadAd) BOOL downloadAd;

/// 下载类信息描述
@property (nonatomic, strong) UBiXNativeAdDataDownloadAdInfo *downloadAdInfo;
@end

NS_ASSUME_NONNULL_END
