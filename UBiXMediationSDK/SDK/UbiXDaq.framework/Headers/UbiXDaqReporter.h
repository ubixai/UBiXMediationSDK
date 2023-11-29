//
//  UbiXDaqReporter.h
//  UbiXDaq
//
//  Created by UbiX on 2021/9/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
extern NSString *const kAdSlotID;
extern NSString *const kAdType;
extern NSString *const kAdRequestId;
extern NSString *const kAdBidType;
extern NSString *const kAdsId;
extern NSString *const kAdsSlotID;
extern NSString *const kAdsBidCpm;
extern NSString *const kAdsFloorCpm;
extern NSString *const kAdsErrorCode;
extern NSString *const kAdsErrorMsg;
extern NSString *const kAdsVersion;
extern NSString *const kClickTrigger;
extern NSString *const kStatusCode;
extern NSString *const kStatusMsg;
extern NSString *const kDuration;
extern NSString *const kAdTrafficId;
extern NSString *const kAttrs;
extern NSString *const kAdErrorCode;
extern NSString *const kAdErrorMsg;
extern NSString *const kIsFromCache;
extern NSString *const kAdMarginRate;
extern NSString *const kAdContracType;
extern NSString *const kAdModel;
extern NSString *const kAdBidPrice;
extern NSString *const kAdsBidSettleCpm;
extern NSString *const kAdStrategyLimitTime;
extern NSString *const kAdUseLimitTime;
extern NSString *const kAdRenderMethod;
extern NSString *const kAdWaterfallIndex;
extern NSString *const kUseStrategyCache;
extern NSString *const kAdAuditType;
extern NSString *const kCtrConfig;
extern NSString *const kIsTriggerCtr;
extern NSString *const kExtra;
extern NSString *const kUbixmUsr_Uid;
extern NSString *const kUbixmUsr_Channel;
extern NSString *const kUbixmUsr_SubChannel;
extern NSString *const kUbixmUsr_Age;
extern NSString *const kUbixmUsr_Gender;
extern NSString *const kUbixmUsr_IsSubscriber;
extern NSString *const kUbixmUsr_PubSegmentId;
extern NSString *const kUbixmUsr_Ext;

@interface UbiXDaqEventParam : NSObject

@end

@interface UbiXDaqReporter : NSObject

/** daq不再主动获取idfa，由调用者上传idfa */
@property (nonatomic, copy) NSString *idfa;
/** daq不再主动获取idfv，由调用者上传idfv */
@property (nonatomic, copy) NSString *idfv;
/** 用户信息 字典 */
@property (nonatomic, strong) NSDictionary *userInfoDic;
/** 埋点上报的环境变量 */
@property (nonatomic, assign) int32_t env;

- (instancetype)initWithAppId:(NSString *)appId sdkVersion:(NSString *)version reportUrl:(NSString *)url uploadCount:(int)uploadCount uploadPeriod:(int)uploadPeriod isMediation:(BOOL)isMediation;

- (void)uploadEventCode:(NSString *)eventCode attribute:(NSDictionary *_Nullable)attribute immediately:(BOOL)isImmediately;

/// 将本地的所有数据都进行上报
- (void)tryUploadAllRecord;

@end

NS_ASSUME_NONNULL_END
