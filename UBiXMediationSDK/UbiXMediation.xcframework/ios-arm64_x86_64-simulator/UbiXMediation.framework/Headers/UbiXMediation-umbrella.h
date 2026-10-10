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

#import "UbiXMCustomAdapter.h"
#import "UbiXMCustomConfigAdapter.h"
#import "UbiXMCustomNativeAdapter.h"
#import "UbiXMCustomNativeAdapterBridge.h"
#import "UbiXMCustomSplashAdapter.h"
#import "UbiXMCustomSplashAdapterBridge.h"
#import "UbiXMDislikeReason.h"
#import "UbiXMediationNativeAd.h"
#import "UbiXMediationNativeAdData.h"
#import "UbiXMediationNativeAdViewCreator.h"
#import "UbiXMImage.h"
#import "UbiXMAdsMaterialInfo.h"
#import "UbiXMediation.h"
#import "UbiXMediationEnum.h"
#import "UbiXMediationObject.h"
#import "UbiXMediationSDK.h"
#import "UbiXMediationSDKErrorCode.h"
#import "UbiXMediationSplash.h"
#import "UbiXMInterfaceBaseObject.h"
#import "UbiXMSdkInitConfig.h"
#import "UbiXMUserConfig.h"
#import "MediationAppApi.pbobjc.h"
#import "MediationCofingApiV200.pbobjc.h"
#import "MediationInitApi.pbobjc.h"

FOUNDATION_EXPORT double UbiXMediationVersionNumber;
FOUNDATION_EXPORT const unsigned char UbiXMediationVersionString[];

