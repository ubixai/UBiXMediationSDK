//
//  JADBannerView.h
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

#import "JADBannerViewDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
 该类为模板横幅广告
 
 横幅广告（Banner）提供一个长方形的横幅广告，一般在应用指定的区域提供展现。
 
 代码示例：

    @property (strong, nonatomic) JADBannerView *bannerView;

    -(JADBannerView *)bannerView {
       if(!_bannerView){
           //初始化横幅广告
           _bannerView = [[JADBannerView alloc] initWithSlotID:@"YOUR_SLOT_ID" adSize:YOUR_SIZE rootViewController:self];
           //设置代理
           _bannerView.delegate = self;
       }
       return _bannerView;
    }
       
    //加载广告
    [self.bannerView loadAdData];
       
 */
@interface JADBannerView : UIView

/**
 * @brief 代码位ID
 * @discussion 属性：代码位ID
 * The bannerView's ad slot slotID.
 */
@property (nonatomic, copy, readonly, nullable) NSString *slotID;

/**
 * @brief 关闭按钮隐藏属性
 * @discussion 通过该字段设置关闭按钮隐藏属性 设置为YES，关闭按钮隐藏，为NO,关闭按钮不隐藏
 * hide close button
 */
@property (nonatomic, assign) BOOL hideCloseButton;

/**
 * @brief 广告视图代理
 * @discussion banner视图 delegate
 * The bannerView's ad delegate.
 * 设置视图代理后，才可以正常收到相关回调
 */
@property (nonatomic, weak) id <JADBannerViewDelegate> delegate;

/**
 * @brief 广告价格
 * @discussion Ad price
 * 该字段含义为广告价格，单位为 分
 */
@property (nonatomic, assign, readonly) NSInteger price;

/**
 * @brief 手势类型
 * @discussion 手势类型 Event Trigger Type
 * 触发点击事件的手势类型 ，详细枚举可查看JADYunConstant.h定义
 */
@property (nonatomic, assign) JADClickEventTriggerType triggerType DEPRECATED_ATTRIBUTE;

/**
  @brief 初始化横幅广告view
  @param slotID 代码位ID
  @param adSize 代码位大小，注意：与管理平台的配置保持一致
  @param rootViewController 代码位所在的UIViewController
  @discussion 广告对象初始化 Ad  init
 
  代码示例：
 
    @property (strong, nonatomic) JADBannerView *bannerView;

    -(JADBannerView *)bannerView {
        if(!_bannerView){
            _bannerView = [[JADBannerView alloc] initWithSlotID:@"YOUR_SLOT_ID" adSize:YOUR_SIZE rootViewController:self];
            _bannerView.delegate = self;
        }
        return _bannerView;
    }
 */
- (instancetype)initWithSlotID:(NSString *)slotID
                        adSize:(CGSize)adSize
            rootViewController:(UIViewController *)rootViewController;

/**
 * @brief 预缓存广告
 * @discussion 预缓该广告位广告数据
 * Preload banner view ad data.
 */
- (void)preloadAdData;

/**
 * @brief 加载广告
 * @discussion 加载banner广告
 * Load banner view ad data.
 * 使用该方法加载横幅广告
 *
 * 代码示例：
 *
 *     [self.bannerView loadAdData];
 */
- (void)loadAdData;

/**
 * @brief 删除Banner视图。
 * @discussion 如果您自定义跳过按钮，则需要调用此方法来关闭开屏广告。
 */
- (void)removeBannerView;

@end

NS_ASSUME_NONNULL_END
