//
//  UBiXPrivacyConfig.h
//  UbiXAdSDK
//
//  Created by fei.li on 2022/10/17.
//
/**
 隐私设置
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, UBiXUserGender) {
    UBiXUserGenderUnknown = 0,  // 未知
    UBiXUserGenderMale    = 1,  // 男
    UBiXUserGenderFemale  = 2,  // 女
};

@interface UBiXPrivacyConfig : NSObject
/// 是否允许查询指定schema。(默认YES)
@property (nonatomic, assign, getter = isCanQueryScheme) BOOL canQueryScheme;
/// 是否允许使用位置信息。(默认YES)
@property (nonatomic, assign, getter = isCanUseLocation) BOOL canUseLocation;
/// 是否允许使用IDFA。(默认YES)
@property (nonatomic, assign, getter = isCanUseDeviceId) BOOL canUseDeviceId;

// 当location不允许获取时，可设置自定义的值
@property (nonatomic, assign) double customLatitude;  // 纬度
@property (nonatomic, assign) double customLongitude; // 经度
// 当deviceId不允许获取时，可设置自定义idfa
@property (nonatomic, copy) NSString *customIDFA;     // idfa

/// 媒体侧的用户id
@property (nonatomic, copy)   NSString *userId;
/// 用户性别
@property (nonatomic, assign) UBiXUserGender userGender;
/// 用年龄
@property (nonatomic, assign) int userAge;
/// 用户兴趣标签
@property (nonatomic, strong) NSArray<NSString *> *userInterests;
/// 用户搜索词/关键词
@property (nonatomic, strong) NSArray<NSString *> *userKeywords;

// 实例化
+ (instancetype)sharedInstance;
+ (instancetype)config;
@end

NS_ASSUME_NONNULL_END
