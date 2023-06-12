//
//  JADSplashView.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/18.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <UIKit/UIKit.h>

#if __has_include(<JADYunCore/JADYunConstant.h>)
#import <JADYunCore/JADYunConstant.h>
#else
#import "JADYunConstant.h"
#endif

#import "JADSplashViewDelegate.h"

NS_ASSUME_NONNULL_BEGIN
/**
  开屏广告
   
  A customized UIView to represent a JADYun ad (splash ad).
 
 
    代码示例：

    @property (strong, nonatomic) JADSplashView *splashView;

    -(JADSplashView *)splashView {
        if(!_splashView) {
         _splashView = [[JADSplashView alloc] initWithSlotID:@"YOUR_SLOT_ID" adSize:CGSizeMake(splashWidth, splashHeight)];
         
         // Required  回调代理
         _splashView.delegate = self;

         // Required  开屏落地页控制器设置
         _splashView.rootViewController = self.window.rootViewController;

         // Optional  加载广告最大容忍时长，默认5s
         _splashView.tolerateTime = 5;
    
         // Optional  开屏广告跳过时长，默认5s
         _splashView.skipTime = 5;
       }
       return _splashView;
    }
    
    //加载开屏广告
    [self.splashView loadAdData];
 
    注意：新版本开启动态化渲染后，splashStyle配置不生效。
 */
@interface JADSplashView : UIView

/**
 * @brief 代码位ID
 * @discussion 属性：代码位ID
 * The splashView's ad slot slotID.
 */
@property (nonatomic, copy, readonly, nullable) NSString *slotID;

/**
 * @brief 开屏视图代理
 * @discussion 开屏视图 delegate
 * The splashView's ad delegate.
 *
 */
@property (nonatomic, weak) id <JADSplashViewDelegate> delegate;

/**
 *  @brief 容忍时长
 *  @discussion 加载广告最大容忍时长，默认5s
 * Maximum allowable load timeout, default 5s, unit s.
 *
 */
@property (nonatomic, assign) NSTimeInterval tolerateTime;

/**
 * @brief 跳过时长
 * @discussion 开屏广告跳过时长，默认5s
 * Splash allowable skip timeout, default 5s, unit s.
 *
 */
@property (nonatomic, assign) NSInteger skipTime;

/**
 * @brief 广告价格
 * @discussion 该字段含义为广告价格，单位为 分
 * Ad price
 */
@property (nonatomic, assign, readonly) NSInteger price;

/**
 * @brief 开屏样式
 * @discussion 开屏广告样式，具体样式类型可查看JADYunConstant.h中声明。
 * 注意：如果您开启了动态化渲染，该属性配置则不生效
 */
@property (nonatomic, assign) JADSplashStyle splashStyle;

/**
 * @brief 手势类型
 * @discussion 触发点击事件的手势类型
 */
@property (nonatomic, assign) JADClickEventTriggerType triggerType DEPRECATED_ATTRIBUTE;

/**
 * @brief 控制器
 * @discussion 落地页跳转所需控制器
 * 该方法为必选
 * required.
 */
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 * @brief 隐藏跳过按钮，默认为NO
 * @discussion 如果隐藏跳过按钮，则需要自定义倒计时
 */
@property (nonatomic, assign) BOOL hideSkipButton;

/**
 * @brief 初始化开屏广告
 * @param slotID 代码位ID
 * @param size 开屏广告尺寸
 * @discussion 开屏广告初始化方法
 *
 * 代码示例：
 *
 *       self.splashView = [[JADSplashView alloc] initWithSlotID:@"YOUR_SLOT_ID" adSize:CGSizeMake(YOUR_SPLASH_WIDTH, YOUR_SPLASH_HEIGHT)];
 */
- (instancetype)initWithSlotID:(NSString *)slotID adSize:(CGSize)size;

/**
 * @brief 预缓存广告
 * @discussion 预缓该广告位广告数据
 * Preload splash view ad data.
 */
- (void)preloadAdData;

/**
 * @brief 加载广告
 * @discussion 加载开屏广告
 * Load splash ad data.
 *
 *   代码示例：
 *
 *   [self.splashView loadAdData];
 */
- (void)loadAdData;

/**
 * @brief 删除开屏视图。调用此方法后立即停止倒计时。
 * @discussion 如果您自定义跳过按钮，则需要调用此方法来关闭开屏广告。
 */
- (void)removeSplashView;

@end

NS_ASSUME_NONNULL_END
