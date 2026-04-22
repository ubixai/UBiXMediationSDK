//
//  UbiXMDislikeReason.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/7.
//

#import "UbiXMInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMDislikeReason : UbiXMInterfaceBaseObject
//- (instancetype)initWithID:(NSString *)ID name:(NSString *)name subReasons:(NSArray<BUMDislikeReason *> *)reasons;

@property (nonatomic, copy, readonly) NSString *ID;

@property (nonatomic, copy, readonly) NSString *name;

@property (nonatomic, copy, readonly) NSArray<UbiXMDislikeReason *> *subReasons;

@property (nonatomic, assign) BOOL isSelected;
@end

NS_ASSUME_NONNULL_END
