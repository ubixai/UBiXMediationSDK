//
//  UBiXMAdProfAdBaseAdapter.h
//  UbiXMediation
//
//  Created by guoqiang on 2025/3/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UBiXMAdProfAdBaseAdapter : NSObject
+ (NSInteger)priceWithMeidaExt:(NSDictionary *)extra;

- (NSString *)appId;
/// 是否开启摇一摇，默认是YES。
- (BOOL)shakable;

@end

NS_ASSUME_NONNULL_END
