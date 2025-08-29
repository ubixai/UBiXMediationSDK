//
//  UbiXMediationRewardedVideo.h
//  UbiXMediation
//
//  Created by fei.li on 2022/8/16.
//

#import <Foundation/Foundation.h>
#import <UbiXMediation/UbiXMediationObject.h>

NS_ASSUME_NONNULL_BEGIN

@class UbiXMediationRewardedVideo;
@protocol UbiXMediationRewardedVideoDelegate <NSObject>
@optional
// 激励视频广告加载成功回调
- (void)mediationRewardedVideoDidLoad:(UbiXMediationRewardedVideo *)rewardedVideo;

// 激励视频广告加载失败回调
- (void)mediationRewardedVideoDidFailToLoad:(UbiXMediationRewardedVideo *)rewardedVideo error:(NSError *)error;

// 激励视频广告展示成功回调
- (void)mediationRewardedVideoDidShow:(UbiXMediationRewardedVideo *)rewardedVideo;

// 激励视频广告播放开始回调
- (void)mediationRewardedVideoDidStarted:(UbiXMediationRewardedVideo *)rewardedVideo;

// 激励视频广告展示失败回调
- (void)mediationRewardedVideoDidFailToShow:(UbiXMediationRewardedVideo *)rewardedVideo error:(NSError *)error;

// 激励视频奖励回调
- (void)mediationRewardedVideoDidReward:(UbiXMediationRewardedVideo *)rewardedVideo;

// 激励视频点击广告回调
- (void)mediationRewardedVideoDidClick:(UbiXMediationRewardedVideo *)rewardedVideo;
//- (void)mediationRewardedVideoClick:(UbiXMediationRewardedVideo *)rewardedVideo; // removed

// 激励视频点击跳过视频回调
- (void)mediationRewardedVideoDidSkip:(UbiXMediationRewardedVideo *)rewardedVideo;

// 激励视频关闭广告回调
- (void)mediationRewardedVideoDidClosed:(UbiXMediationRewardedVideo *)rewardedVideo;
//- (void)mediationRewardedVideoClosed:(UbiXMediationRewardedVideo *)rewardedVideo; // removed

// 视频播放完成回调
- (void)mediationRewardedVideoDidPlayFinish:(UbiXMediationRewardedVideo *)rewardedVideo;
@end


@interface UbiXMediationRewardedVideo : UbiXMediationObject
/**
 接收回调
 */
@property (nonatomic, weak) id<UbiXMediationRewardedVideoDelegate> delegate;

// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;

/**
 请求广告
 */
- (void)loadAd;
/**
 展示广告
 */
- (void)showAdWithRootViewController:(UIViewController *)rootViewController;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

/// 广告是否有效
- (BOOL)isAvaliable;
@end

NS_ASSUME_NONNULL_END

