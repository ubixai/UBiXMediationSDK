//
//  UbiXMediationPasterReporter.h
//  UbiXMediation
//
//  Created by stefan.qi on 2022/12/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMediationPasterReporter : NSObject

/// 视频播放开始 单位：秒
- (void)startPlayVideoView:(float)duration;
/// 视频播放暂停
- (void)didPauseVideoView:(float)currentTime;
/// 视频播放恢复
- (void)didResumeVideoView:(float)currentTime;
/// 视频播放结束
- (void)didFinishVideoView;
/// 视频播放终止
- (void)didBreakVideoView:(float)currentTime andError:(NSError *)error;


@end

NS_ASSUME_NONNULL_END
