//
//  UbiXDaqRecord.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/7/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UbiXDaqRecord : NSObject

@property (nonatomic, assign)NSString *recordId;

@property (nonatomic, copy)NSString *requestId;

@property (nonatomic, strong)NSData *eventData;

- (instancetype)initWithRequestId:(NSString *)requestId data:(NSData *)eventData;

@end

NS_ASSUME_NONNULL_END
