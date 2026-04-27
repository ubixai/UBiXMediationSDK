//
//  UBiXMAdProfNativeAdHelper.h
//  UBiXMAdProfAdapter
//
//  Created by guoqiang on 2026/4/21.
//

#import <Foundation/Foundation.h>
#import <UbiXMediation/UbiXMediation-umbrella.h>

@class UbiXMAPNativeAdObject;
@class UbiXMAPVideoPlayerView;
NS_ASSUME_NONNULL_BEGIN

@interface UBiXMAdProfNativeAdHelper : NSObject <UbiXMediationNativeAdData, UbiXMediationNativeAdViewCreator>

@property (nonatomic, strong) UbiXMAPVideoPlayerView *videoPlayerView;

- (instancetype)initWithAdObject:(UbiXMAPNativeAdObject *)adObject;

@end

NS_ASSUME_NONNULL_END
