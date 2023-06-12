//
//  UBiXAdReviewParams.h
//  UbiXAdSDK
//
//  Created by fei.li on 2023/1/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UBiXAdReviewParams : NSObject
/// 是否是视频广告
@property (nonatomic, assign, getter = isVideoAd) BOOL videoAd;
/// 素材地址
@property (nonatomic, strong) NSArray <NSString *> *mediaUrls;
@end

NS_ASSUME_NONNULL_END
