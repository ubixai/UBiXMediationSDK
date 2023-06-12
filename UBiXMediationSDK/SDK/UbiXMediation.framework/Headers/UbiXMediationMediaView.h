//
//  UbiXMediationMediaView.h
//  UbiXMediation
//
//  Created by stefan.qi on 2022/8/11.
//

#import <UIKit/UIKit.h>
#import "UbiXMediationMaterialData.h"
#import "UbiXMediationPasterReporter.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, UbiXMMediaPlayerStatus) {
    UbiXMMediaPlayerStatusInitial = 0,         // 初始状态
    UbiXMMediaPlayerStatusLoading = 1,         // 加载中
    UbiXMMediaPlayerStatusStarted = 2,         // 开始播放
    UbiXMMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    UbiXMMediaPlayerStatusError = 4,           // 播放出错
    UbiXMMediaPlayerStatusStoped = 5,          // 播放停止
};

@class UbiXMediationMediaView;

/// 播放器状态回调协议
@protocol UbiXMediationMediaViewDelegate <NSObject>

// paster广告展示成功
- (void)mediationMediaViewDidShow:(UbiXMediationMediaView *)mediaView;

// paster点击广告回调
- (void)mediationMediaViewDidClick:(UbiXMediationMediaView *)mediaView;

// paster播放状态切换
- (void)mediationMediaView:(UbiXMediationMediaView *)mediaView videoStatusDidChange:(UbiXMMediaPlayerStatus)currentStatus;

// paster播放完毕
- (void)mediationMediaViewDidPlayFinished:(UbiXMediationMediaView *)mediaView;

// paster的播放进度
- (void)mediationMediaViewPlayTime:(UbiXMediationMediaView *)mediaView timeInterval:(NSTimeInterval)timeInterval;

@end

@class UbiXMediationPasterAdModel;

/// 自定义播放器的状态回调代理
@protocol UbiXMCustomerVideoPlayerStatusDelegate <NSObject>

/// 视频播放开始
- (void)ubixm_customer_startPlayVideoView:(UbiXMediationPasterAdModel *)adModel;
/// 视频播放暂停
- (void)ubixm_customer_didPauseVideoView:(UbiXMediationPasterAdModel *)adModel;
/// 视频播放恢复
- (void)ubixm_customer_didResumeVideoView:(UbiXMediationPasterAdModel *)adModel;
/// 视频播放结束
- (void)ubixm_customer_didFinishVideoView:(UbiXMediationPasterAdModel *)adModel;
/// 视频播放终止
- (void)ubixm_customer_didBreakVideoView:(UbiXMediationPasterAdModel *)adModel;

@end


@protocol UbiXMediationCustomeVideoPlayerDelegate <NSObject>

@required
@property(nonatomic, weak) id<UbiXMCustomerVideoPlayerStatusDelegate> customerVideoPlayerStatusDelegate;

/// 开始播放视频
- (void)play;
/// 暂停播放视频
- (void)pause;
/// 恢复播放视频
- (void)resume;

/// 获取播放播放器的当前播放进度， 单位ms
- (NSTimeInterval)currentVideoPlayingTime;
/// 设置视频是否静音
- (void)setVideoIsMute:(BOOL)isMute;

@end

@interface UbiXMediationMediaView : UIView

/// 用户自定义的视频播放器
@property (nonatomic, strong) UIView<UbiXMediationCustomeVideoPlayerDelegate> *customeVideoPlayer;
/// 广告状态上报对象
@property (nonatomic, strong) UbiXMediationPasterReporter *reporter;

/// 聚合播放器View的回调代理对象
@property (nonatomic, weak) id<UbiXMediationMediaViewDelegate> delegate;

/** 将广告数据绑定到View播放器上 */
- (void)bindViewWithAdData:(UbiXMediationMaterialData *)adData;

/**  播放视频  **/
- (void)playVideo;

/**  暂停视频  **/
- (void)pauseVideo;

/// 获取播放播放器的当前播放进度， 单位ms
- (NSTimeInterval)currentVideoPlayingTime;


/// 设置视频是否静音
- (void)setVideoIsMute:(BOOL)isMute;

@end

NS_ASSUME_NONNULL_END
