//
//  UBiXNativeAdVideoReporter.h
//  UbiXAdSDK
//
//  Created by fei.li on 2023/7/6.
//
/**
 * 视频事件上报
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UBiXNativeAdVideoReporter : NSObject
/// 上报开始播放 (duration:视频长度 秒s)
- (void)reportStartWithDuration:(float)duration;

/// 上报暂停播放 (currentTime:当前播放时长 秒s)
- (void)reportPause:(float)currentTime;

/// 上报继续播放 (currentTime:当前播放时长 秒s)
- (void)reportResume:(float)currentTime;

/// 上报播放进度 (time:已播放时长 秒s)
- (void)reportPlayedTime:(float)time;

/// 上报播放完成
- (void)reportFinish;

/// 上报播放失败及错误信息
- (void)reportFailedWithError:(NSError * __nullable)error;
@end

NS_ASSUME_NONNULL_END
