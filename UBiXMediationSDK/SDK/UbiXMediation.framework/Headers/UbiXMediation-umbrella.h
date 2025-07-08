#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "UbiXMAdapterRewardAdInfo.h"
#import "UbiXMCustomAdapter.h"
#import "UbiXMCustomBannerAdapter.h"
#import "UbiXMCustomBannerAdapterBridge.h"
#import "UbiXMCustomConfigAdapter.h"
#import "UbiXMCustomInterstitialAdapter.h"
#import "UbiXMCustomInterstitialAdapterBridge.h"
#import "UbiXMCustomNativeAdapter.h"
#import "UbiXMCustomNativeAdapterBridge.h"
#import "UbiXMCustomRewardedVideoAdapter.h"
#import "UbiXMCustomRewardedVideoAdapterBridge.h"
#import "UbiXMCustomSplashAdapter.h"
#import "UbiXMCustomSplashAdapterBridge.h"
#import "UbiXMDislikeReason.h"
#import "UbiXMediationNativeAd.h"
#import "UbiXMediationNativeAdData.h"
#import "UbiXMediationNativeAdViewCreator.h"
#import "UbiXMImage.h"
#import "UbiXMMediaBidResult.h"
#import "UbiXMedationFeedAdModel.h"
#import "UbiXMediationFeed.h"
#import "UbiXMediationFeedAdView.h"
#import "UbiXMediationMaterialData.h"
#import "UbiXMediationMediaView.h"
#import "UBiXMFeedbackIconView.h"
#import "UbiXMVideoPlayerView.h"
#import "UbiXMediation.h"
#import "UbiXMediationAdView.h"
#import "UbiXMediationBanner.h"
#import "UbiXMediationEnum.h"
#import "UbiXMediationInterstitial.h"
#import "UbiXMediationObject.h"
#import "UbiXMediationRewardedVideo.h"
#import "UbiXMediationSDK.h"
#import "UbiXMediationSDKErrorCode.h"
#import "UbiXMediationSplash.h"
#import "UbiXMInterfaceBaseObject.h"
#import "UbiXMSdkInitConfig.h"
#import "UbiXMUserConfig.h"

FOUNDATION_EXPORT double UbiXMediationVersionNumber;
FOUNDATION_EXPORT const unsigned char UbiXMediationVersionString[];

