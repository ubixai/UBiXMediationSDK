//
//  UbiXMMediaBidResult.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/7.
//

#import "UbiXMInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMMediaBidResult : UbiXMInterfaceBaseObject
@property (nonatomic, assign) BOOL win;

@property (nonatomic, assign, readonly) NSInteger winnerPrice;

@property (nonatomic, copy, readonly) NSString *lossDescription;

@property (nonatomic, copy, readonly) NSString *winnerAdnID;

@property (nonatomic, copy, readonly) NSDictionary *ext;

@property (nonatomic, strong, readonly) id originNativeAdData;
@end

NS_ASSUME_NONNULL_END
