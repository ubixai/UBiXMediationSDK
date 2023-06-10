//
//  UbiXMediationSplash.h
//  UbiXMediation
//
//  Created by UbiX on 2021/8/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol UbiXMediationSplashDelegate;

typedef NS_ENUM(NSUInteger, UbiXMSkipButtonShowType) {
    UbiXMSkipButtonShowTypeDefault = 0, // 椭圆样式，默认样式
    UbiXMSkipButtonShowTypeCircle,  // 圆环样式
};

@interface UbiXMediationSplash : NSObject

// 开屏广告的回调代理
@property (nonatomic, weak)id<UbiXMediationSplashDelegate> delegate;

// 广告位Id
@property (nonatomic, copy)NSString *slotId;

// 底部视图, 如有需要确定宽高, 开发者自定义（可选）
@property (nonatomic, strong)UIView *bottomView;

// 展示落地页的controller, 如果不传默认使用keyWindow.rootVC
@property (nonatomic, weak)UIViewController *rootViewController;

@property (nonatomic, assign)UbiXMSkipButtonShowType skipViewShowtype;

// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;


/// 根据slotModel信息初始化开屏对象
- (instancetype) initWithSlotId:(NSString *)slotId;

// load前需要设置好所有参数
- (void)loadAd;

- (void)showAd:(UIWindow *)window;

- (BOOL)isReady;

/// 广告是否有效
- (BOOL)isAvaliable;

/// 移除广告
- (void)removeAd;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

@end


@protocol UbiXMediationSplashDelegate <NSObject>

@optional
// 开屏广告加载成功
- (void)mediationSplashDidLoad:(UbiXMediationSplash *)splash;

// 开屏广告展示成功
- (void)mediationSplashDidShow:(UbiXMediationSplash *)splash;

// 开屏广告加载失败回调
- (void)mediationSplashDidFailToLoad:(UbiXMediationSplash *)splash error:(NSError *)error;

// 开屏广告展示失败回调
- (void)mediationSplashDidFailToShow:(UbiXMediationSplash *)splash error:(NSError *)error;

// 开屏广告点击回调
- (void)mediationSplashDidClick:(UbiXMediationSplash *)splash;

// 开屏广告即将关闭回调
- (void)mediationSplashWillClosed:(UbiXMediationSplash *)splash skip:(BOOL)isSkip;

// 开屏广告关闭完成回调
- (void)mediationSplashDidClosed:(UbiXMediationSplash *)splash skip:(BOOL)isSkip;

// 开屏广告转化完成(调起类+落地页)
- (void)mediationSplashDidFinishConversion:(UbiXMediationSplash *)splash;

@end


NS_ASSUME_NONNULL_END
