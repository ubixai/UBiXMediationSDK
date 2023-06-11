//
//  UBiXNativeAdObject.h
//  UbiXAdSDK
//
//  Created by fei.li on 2023/1/4.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UBiXAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class UBiXNativeAdObject;
@protocol UBiXNativeAdObjectDelegate <NSObject>
/**
 * 广告展示: container展示时调用
 */
- (void)ubixNativeAdObjectDidShow:(UBiXNativeAdObject *)nativeAdObject;

/**
 * 广告点击
 */
- (void)ubixNativeAdObjectDidClick:(UBiXNativeAdObject *)nativeAdObject;

/**
 *  广告转化完成
 */
- (void)ubixNativeAdObjectDidFinishConversion:(UBiXNativeAdObject *)nativeAdObject interactionType:(UBiXAdInteractionType)interactionType;
@end

/**
 * 广告返回对象，需被强引用
 */
@class UBiXNativeAdData;
@interface UBiXNativeAdObject : NSObject
/// 广告素材数据
@property (nonatomic, strong, readonly) UBiXNativeAdData *adData;

/// 交互回调
@property (nullable, nonatomic, weak) id <UBiXNativeAdObjectDelegate> delegate;

/// @required 展示落地页的ViewController(present方式)
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 * 注册曝光容器和点击view
 */
- (void)registerContainer:(__kindof UIView *)container clickableViews:(NSArray <__kindof UIView *> *)clickableViews;

/**
 * 注销view绑定
 */
- (void)unregisterView;

/**
 * 获取广告价格，单位(分)
 */
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
