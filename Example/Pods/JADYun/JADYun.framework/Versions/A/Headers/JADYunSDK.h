//
//  JADYun.h
//  JADYun
//
//  Created by wangshuai331 on 2020/7/31.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class JADLocation, JADPollux;

/**
 JADYun SDK 京东广告SDK
 
 JADYun 支持多种广告格式，包括开屏广告、插屏广告、横幅广告和信息流广告。
  
 (1)初始化前配置
 
 * 设置日志开关，可选配置
 
 代码示例：
 
            [JADYunSDK enableLog:YOUR_LOG_STATUS];
 
 * 是否允许JADYunSDK使用地理位置权限，可选配置
  
 代码示例：
 
            [JADYunSDK canUseLocation:YES];
 
 其他可选配置接口可查看详细方法列表。
 
 (2)初始化SDK
 
 代码示例：
 
            [JADYun initWithAppID:@"YOUR_JADYun_APP_ID"];
 */
@interface JADYunSDK : NSObject

/**
 * @brief 初始化 JADYun  SDK 方法
 * @param appID 京东广告应用标识
 * @discussion 使用SDK时需进行初始化，使用京媒平台appid进行初始化
*/
+ (void)initWithAppID:(NSString *_Nullable)appID;

/**
 * @brief 初始化状态
 * @discussion 检查 JADYun SDK 是否已经初始化成功
 */
+ (BOOL)isInitialized;

/**
 * @brief 版本号
 * @discussion SDK Version 版本号
 */
+ (NSString *)sdkVersion;

/**
 * @brief 日志开关
 * @param enableLog Debug模式 默认为 NO
 * @discussion 是否开启log 日志，可选
 */
+ (void)enableLog:(BOOL)enableLog;

/**
 * @brief 地理位置开关
 * @param isCanUseLocation 默认为YES
 * @discussion 是否允许JADYun SDK 使用地理位置权限 ，可选
 */
+ (void)canUseLocation:(BOOL)isCanUseLocation;

/**
 * @brief 设置地理位置
 * @param location 传入的地理位置
 * @discussion 当isCanUseLocation = NO时，可传入地理位置信息，京东 SDK 使用您传入的地理位置信息，可选
 */
+ (void)setUserLocation:(JADLocation *)location;

/**
 * @brief 设置pollux值
 * @param polluxs 传入Pollux数组，可选配置，原CAID
 * @discussion 传入您的pollux值，可为多组
 */
+ (void)setPolluxArray:(NSArray<JADPollux *> *)polluxs;

/**
 * @brief 设置idfa值
 * @param idfa 传入idfa值，可选配置
 * @discussion 当您不允许SDK使用IDFA权限时，则可通过该方法传入您的IDFA值
 */
+ (void)setCustomIDFA:(NSString *)idfa;

/**
 * @brief IDFA开关
 * @param isCanUseIDFA 是否允许
 * @discussion 是否允许使用IDFA， 不设置则默认为YES；设置为NO时，IDFA权限不可用，可通过setCustomIDFA传入有效的IDFA值
 */
+ (void)canUseIDFA:(BOOL)isCanUseIDFA;

/**
 * @brief IP开关
 * @param isCanUseIP 是否允许
 * @discussion 是否允许使用IP地址，不设置则默认为YES
*/
+ (void)canUseIPAddress:(BOOL)isCanUseIP;

@end

NS_ASSUME_NONNULL_END
