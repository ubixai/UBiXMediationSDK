//
//  UbiXMMediaBidResult.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/7.
//

#import "UbiXMInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    /// 其他
    UbiXMBidLossTypeOther = 0,
    /// 广告出价低于最高价
    UbiXMBidLossTypeNormal = 1,
    /// 底价过滤
    UbiXMBidLossTypePriceFilter = 2,
    
} UbiXMBidLossType;


@interface UbiXMMediaBidResult : UbiXMInterfaceBaseObject
@property (nonatomic, assign) BOOL win;

@property (nonatomic, assign, readonly) NSInteger winnerPrice;

@property (nonatomic, assign, readonly) NSInteger secondPrice;

@property (nonatomic, copy, readonly) NSString *lossDescription;

@property (nonatomic, assign, readonly) UbiXMBidLossType lossType;

@property (nonatomic, copy, readonly) NSString *winnerAdnID;

@property (nonatomic, copy, readonly) NSDictionary *ext;

@property (nonatomic, strong, readonly) id originNativeAdData;
@end

NS_ASSUME_NONNULL_END
