//
//  UBiXNativeAdRelatedView.h
//  UbiXAdSDK
//
//  Created by fei.li on 2023/1/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "UBiXNativeAdObject.h"
#import "UBiXNativeAdVideoView.h"
#import "UBiXNativeAdVideoReporter.h"

NS_ASSUME_NONNULL_BEGIN
/**
 * 信息流组件工具
 *  - 生成视频view和视频事件上报reporter
 */
@interface UBiXNativeAdRelatedView : NSObject
/// 视频组件(刷新数据后获取)
@property (nonatomic, strong, readonly, nullable) UBiXNativeAdVideoView *videoView;

/// 视频事件上报，仅当使用自定义播放器时，需要用reporter进行事件上报
@property (nonatomic, strong, readonly, nullable) UBiXNativeAdVideoReporter *videoReporter;

/// 刷新组件，每次调用都会得到一个新的videoView & videoReporter
- (void)refreshWithNativeAdObject:(UBiXNativeAdObject *)nativeAdObject;
@end

NS_ASSUME_NONNULL_END
