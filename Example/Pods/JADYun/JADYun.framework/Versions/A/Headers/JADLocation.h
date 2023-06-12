//
//  JADLocation.h
//  JADYun
//
//  Created by zhangdi208 on 2021/2/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 地理位置类
 
  若您不允许地理位置权限，则需要通过JADYunSDK的seUserLoaction:传入一个地理位置。
 
  代码示例：
 
        JADLocation *location =  [[JADLocation alloc]init];
        location.latitude = @123.22343;
        location.longitude = @43.491123;
        [JADYunSDK setUserLocation:location];
 */
@interface JADLocation : NSObject

/// 经度
@property (nonatomic, strong) NSNumber *longitude;

/// 纬度
@property (nonatomic, strong) NSNumber *latitude;

@end

NS_ASSUME_NONNULL_END
