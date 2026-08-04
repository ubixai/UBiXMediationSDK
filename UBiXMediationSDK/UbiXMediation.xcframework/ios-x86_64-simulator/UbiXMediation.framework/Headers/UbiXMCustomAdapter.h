//
//  UbiXMCustomAdapter.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/5/30.
//

#ifndef UbiXMCustomAdapter_h
#define UbiXMCustomAdapter_h

@protocol UbiXMCustomConfigAdapter;

typedef NS_ENUM(NSInteger, UbiXMMediatedAdStatusValue) {
    UbiXMMediatedAdStatusValueDeny = -1,
    UbiXMMediatedAdStatusValueUnknown = 0,
    UbiXMMediatedAdStatusValueSure = 1,
};

/// adn广告状态
typedef struct {
    UbiXMMediatedAdStatusValue isReady;
    UbiXMMediatedAdStatusValue unexpired;
    UbiXMMediatedAdStatusValue valid;
} UbiXMMediatedAdStatus;

extern const UbiXMMediatedAdStatus UbiXMMediatedAdStatusUnknown;

extern const UbiXMMediatedAdStatus UbiXMMediatedAdStatusNormal;

static inline
BOOL UbiXMMediatedAdStatusEqualsTo(UbiXMMediatedAdStatus aStatus, UbiXMMediatedAdStatus anotherStatus) {
    return aStatus.isReady == anotherStatus.isReady &&
        aStatus.unexpired == anotherStatus.unexpired &&
        aStatus.valid == anotherStatus.valid;
}

static inline
UbiXMMediatedAdStatus UbiXMMediatedAdStatusMake(UbiXMMediatedAdStatusValue isReady, UbiXMMediatedAdStatusValue unexpired, UbiXMMediatedAdStatusValue valid) {
    UbiXMMediatedAdStatus status = {UbiXMMediatedAdStatusValueUnknown, UbiXMMediatedAdStatusValueUnknown , UbiXMMediatedAdStatusValueUnknown};
    status.isReady = isReady;
    status.unexpired = unexpired;
    status.valid = valid;
    return status;
}
void UBiXMLogDebug(NSString * _Nonnull fmt, ...);

/// 自定义adapter广告类型基本协议
@protocol UbiXMCustomAdapter <NSObject>
@optional

- (NSString *)serverBiddingTokenWithParams:(NSDictionary *)params error:(NSError **)error;

/// 需要传递token以外值时,使用此方法
- (NSString *)serverBiddingTokenWithParams:(NSDictionary *)params otherInfo:(NSMutableDictionary *)otherInfo error:(NSError **)error;

/// 当前广告有广告正在展示时是否允许进行预加载广告，未实现则为NO。
- (BOOL)enablePreloadWhenCurrentIsDisplay;

- (void)didReceiveAdConfig:(NSDictionary *)config;

/// 开发者无需实现，系统自动生成
@property (nonatomic, assign) BOOL isCustomAdapter;

/// 开发者无需实现，系统自动生成
@property (nonatomic, strong) id<UbiXMCustomConfigAdapter> configAdapter;

@end

#endif /* UbiXMCustomAdapter_h */
