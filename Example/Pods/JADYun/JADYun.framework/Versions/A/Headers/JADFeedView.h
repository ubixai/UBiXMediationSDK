//
//  JADFeedView.h
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

#import "JADFeedViewDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
  信息流广告

  A customized UIView to represent a JADYun ad (feed ad).

  代码示例：
 
    @property (strong, nonatomic) JADFeedView *feedView;

    -(JADFeedView *)feedView {
    if(!_feedView){
        _feedView = [[JADFeedView alloc] initWithSlotID:@"YOUR_SLOT_ID" adSize:CGSizeMake(feedWidth, feedHeight)];
        _feedView.delegate = self;
    }
    return _feedView;
    }
 
    //加载广告
    [self.feedView loadAdData];
 */
@interface JADFeedView : UIView

/**
 * @brief 代码位ID
 * @discussion 属性：代码位ID
 *  The feedView's ad slot slotID.
 */
@property (nonatomic, copy, readonly, nullable) NSString *slotID;

/**
 * @brief 关闭按钮隐藏属性
 * @discussion 通过该字段设置关闭按钮隐藏属性 设置为YES，关闭按钮隐藏，为NO,关闭按钮不隐藏
 * hide close button
 */
@property (nonatomic, assign) BOOL hideCloseButton;

/**
 * @brief 信息流视图 delegate
 * @discussion 信息流视图 The feedView's ad delegate.
 * 设置视图代理后，才可以正常收到相关回调
 */
@property (nonatomic, weak, nullable) id <JADFeedViewDelegate> delegate;

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
 * @brief 广告对象初始化
 * @param slotID 代码位ID
 * @param adSize 代码位大小
 * @discussion 广告对象初始化 Ad  init
 */
- (instancetype)initWithSlotID:(NSString *)slotID
                        adSize:(CGSize)adSize;

/**
 * @brief 预缓存广告
 * @discussion 预缓该广告位广告数据
 * Preload feed view ad data.
 */
- (void)preloadAdData;

/**
 * @brief 加载广告
 * @discussion 加载广告 Load feed view ad data.
 * 使用该方法加载信息流广告
 */
- (void)loadAdData;

/**
 * @brief 删除信息流视图。
 * @discussion 如果您自定义跳过按钮，则需要调用此方法来关闭开屏广告。
 */
- (void)removeFeedView;

@end

NS_ASSUME_NONNULL_END
