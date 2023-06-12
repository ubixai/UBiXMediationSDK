//
//  JADPollux.h
//  JADYun
//
//  Created by wangshuai331 on 2021/3/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Pollux类
 
  当您需要设置Pollux时，可使用JADYunSDK的setPolluxArray进行设置
 
  代码示例：
 
        JADPollux *currentPollux = [[JADPollux alloc] init];
        currentPollux.polluxValue = @"YOUR_POLLUX_ID";
        currentPollux.polluxVersion = @"YOUR_POLLUX_VERSION";
        [JADYunSDK setPolluxArray:@[currentPollux]];
 */
@interface JADPollux : NSObject<NSCoding>

/// Pollux 值，原CAID 值
@property (nonatomic, copy) NSString *polluxValue;

/// Pollux 算法版本，原CAID 算法版本
@property (nonatomic, copy) NSString *polluxVersion;


@end

NS_ASSUME_NONNULL_END
