//
//  UbiXAdSDKManager.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/5/24.
//

#import <Foundation/Foundation.h>

@interface UBiXAdSDKManager : NSObject

#pragma mark - SDK Initialization

/**
 * SDK 初始化接口，请在 app 初始化时调用。
 * @param appId - UbiX开发者后台创建的appId
 */
+ (void)initWithAppId:(NSString *)appId;

/**
 * 获取 SDK 版本
 */
+ (NSString *)SDKVersion;


@end

