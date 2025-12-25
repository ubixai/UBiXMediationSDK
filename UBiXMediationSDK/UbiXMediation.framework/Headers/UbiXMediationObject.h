//
//  UbiXMediationObject.h
//  UbiXMediation
//
//  Created by guoqiang on 2023/7/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UbiXMediationAdProtocol <NSObject>

// 广告位Id
@property (nonatomic, copy) NSString *slotId;
// 广告requestId
@property (nonatomic, copy, readonly) NSString *requestId;

/**
 初始化
 @param slotId 广告位id
 */
- (instancetype)initWithSlotId:(NSString *)slotId;

- (id)extraInfoForKey:(NSString *)key;

@end

@interface UbiXMediationObject : NSObject <UbiXMediationAdProtocol>

@end

NS_ASSUME_NONNULL_END
