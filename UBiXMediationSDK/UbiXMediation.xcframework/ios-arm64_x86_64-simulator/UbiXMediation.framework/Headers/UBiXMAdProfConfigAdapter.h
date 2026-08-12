//
//  UBiXMAdProfConfigAdapter.h
//  UBiXMAdProfAdapter
//
//  Created by guoqiang on 2025/6/24.
//

#import <Foundation/Foundation.h>
#import <UbiXMediation/UbiXMediation-umbrella.h>


NS_ASSUME_NONNULL_BEGIN

@interface UBiXMAdProfConfigAdapter : NSObject <UbiXMCustomConfigAdapter>
@property (nonatomic, copy) NSString *appToken;
/// 是否开启摇一摇，默认是YES。
@property (nonatomic, assign) BOOL shakable;
@end

NS_ASSUME_NONNULL_END
