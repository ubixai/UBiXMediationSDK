//
//  UbiXMVideoPlayerView.h
//  UbiXMediation
//
//  Created by stefan.qi on 2022/12/22.
//

#import <UIKit/UIKit.h>
#import <UbiXMediation/UbiXMediationMediaView.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UbiXMVideoViewContentMode) {
    UbiXMVideoViewContentModeScaleToFill,     // 比例改变，内部填满，发生形变
    UbiXMVideoViewContentModeScaleAspectFit,  // 比例不变，内部填充，会有留白, default
    UbiXMVideoViewContentModeScaleAspectFill, // 比例不变，内部填满，会有裁剪
};

@class UbiXMVideoPlayerView;
@protocol UbiXMVideoPlayerViewDelegate <NSObject>
// 已经准备好，可以播放
- (void)ubixMVideoPlayerViewDidReady:(UbiXMVideoPlayerView *)playerView;
// 加载失败
- (void)ubixMVideoPlayerView:(UbiXMVideoPlayerView *)playerView loadFailedWithError:(NSError *)error;
// 播放完成
- (void)ubixMVideoPlayerViewDidFinished:(UbiXMVideoPlayerView *)playerView;
// 播放失败
- (void)ubixMVideoPlayerView:(UbiXMVideoPlayerView *)playerView playFailedWithError:(NSError *)error;
// 播放时间变化:秒
- (void)ubixMVideoPlayerView:(UbiXMVideoPlayerView *)playerView didPlayedTime:(NSTimeInterval)time;
@end

@interface UbiXMVideoPlayerView : UIView<UbiXMCustomerVideoPlayerStatusDelegate>

@property (nonatomic, weak) id<UbiXMVideoPlayerViewDelegate> delegate;
// 静音
@property (nonatomic, assign, getter=isMuted) BOOL muted;
// 总时长:s
@property (nonatomic, assign, readonly) NSTimeInterval duration;
// 类似imageViewContentMode
@property (nonatomic, assign) UbiXMVideoViewContentMode videoContentMode;
// 初始化
- (instancetype)initWithRemoteUrl:(NSString *)remoteUrl;
- (instancetype)initWithLocalUrl:(NSString *)localUrl;
// 或单独设置url
- (void)setupLocalUrl:(NSString *)localUrl;
- (void)setupRemoteUrl:(NSString *)remoteUrl;
// 准备播放，触发加载资源
- (void)prepareToPlay;
// 播放
- (void)play;
// 暂停
- (void)pause;
// 恢复
- (void)resume;
// 停止
- (void)stop;

- (id)customerVideoPlayerStatusDelegate;


- (NSTimeInterval)currentVideoPlayingTime;

- (void)setCustomerVideoPlayerStatusDelegate:(id)customerVideoPlayerStatusDelegate1;

@end

@class AVPlayer;
@interface UbiXMVideoView : UIView
@property (nonatomic, assign) UbiXMVideoViewContentMode contentMode;
- (instancetype)initWithFrame:(CGRect)frame player:(AVPlayer *)player;
- (void)replacePlayer:(AVPlayer *)player;
@end

NS_ASSUME_NONNULL_END
