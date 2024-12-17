//
//  UbiXMediationObject.h
//  UbiXMediation
//
//  Created by guoqiang on 2023/7/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMediationObject : NSObject

// 广告位Id
@property (nonatomic, copy) NSString *slotId;
// 广告requestId
@property (nonatomic, copy) NSString *requestId;

/**
 初始化
 @param slotId 广告位id
 */
- (instancetype)initWithSlotId:(NSString *)slotId;

@end

NS_ASSUME_NONNULL_END
