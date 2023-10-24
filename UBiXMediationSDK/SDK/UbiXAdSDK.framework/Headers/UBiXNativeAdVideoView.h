//
//  UBiXNativeAdVideoView.h
//  UbiXAdSDK
//
//  Created by fei.li on 2023/7/6.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UBiXNativeAdVideoView;
@protocol UBiXNativeAdVideoViewDelegate <NSObject>
/**
 * 视频开始播放
 */
- (void)ubixNativeAdVideoViewStartPlay:(UBiXNativeAdVideoView *)videoView;

/**
 * 视频暂停播放
 */
- (void)ubixNativeAdVideoViewPausePlay:(UBiXNativeAdVideoView *)videoView;

/**
 * 视频继续播放
 */
- (void)ubixNativeAdVideoViewResumePlay:(UBiXNativeAdVideoView *)videoView;

/**
 * 视频播放进度(秒)
 */
- (void)ubixNativeAdVideoView:(UBiXNativeAdVideoView *)videoView playedTime:(float)time;

/**
 * 视频播放结束
 * @param error 错误信息
 */
- (void)ubixNativeAdVideoViewDidPlayFinish:(UBiXNativeAdVideoView *)videoView withError:(NSError *)error;
@end

/**
 * 视频播放器view
 */
@interface UBiXNativeAdVideoView : UIView
/// 视频回调代理
@property (nonatomic, weak) id <UBiXNativeAdVideoViewDelegate> videoDelegate;

/// 静音设置 默认YES-静音
@property (nonatomic, assign, getter=isMuted) BOOL muted;

/// 视频时长(秒s)
@property (nonatomic, assign, readonly) float duration;

/// 播放
- (void)play __attribute__((deprecated("Do nothing now, it will work in a future version")));

/// 暂停
- (void)pause __attribute__((deprecated("Do nothing now, it will work in a future version")));

/// 停止播放
- (void)stop __attribute__((deprecated("Do nothing now, it will work in a future version")));

/// 重播
- (void)replay __attribute__((deprecated("Do nothing now, it will work in a future version")));
@end

NS_ASSUME_NONNULL_END
