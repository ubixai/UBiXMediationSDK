//
//  JADNativeAdWidget.h
//  JADYun
//
//  Created by wangshuai331 on 2020/10/28.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class JADNativeShakeWidget;
@class JADNativeSwipeWidget;

/**
 自渲染广告控件
 
 用于获取相关控件，如跳过按钮、广告标识logo、关闭按钮等。
 
 代码示例：
 
            //获取广告logo
            self.logoAdView = self.nativeAdWidget.logoAdWidget;
 
            //获取关闭按钮
            self.closeButton = self.nativeAdWidget.closeWidget;
            [self.closeButton setFrame:YOUR_FRAME];
 */
@interface JADNativeAdWidget : NSObject

/**
 @brief 关闭按钮
 @discussion 自渲染广告关闭按钮
 close button widget
 */
@property (strong, nonatomic, readonly, nullable) UIButton *closeWidget;

/**
 @brief 跳过按钮
 @discussion 自渲染广告跳过按钮
 skip button widget
*/
@property (strong, nonatomic, readonly, nullable) UIButton *skipWidget;

/**
 @brief 广告标题
 @discussion 自渲染广告标题
 title label widget
*/
@property (strong, nonatomic, readonly, nullable) UILabel *adTitleWidget;

/**
 @brief 广告描述
 @discussion 自渲染广告描述
 description label widget
*/
@property (strong, nonatomic, readonly, nullable) UILabel *adDescriptionWidget;

/**
 @brief “京准通”logo
 @discussion 自渲染“京准通”logo
 logo imageView widget
*/
@property (strong, nonatomic, readonly, nullable) UIImageView *logoWidget;

/**
 @brief “京准通”logo文字
 @discussion 自渲染”京准通”logo文字
 logo text imageView widget
*/
@property (strong, nonatomic, readonly, nullable) UIImageView *logoTextWidget;

/**
 @brief 广告标识logo
 @discussion 自渲染广告标识logo
 logo ad imageView widget
*/
@property (strong, nonatomic, readonly, nullable) UIImageView *logoAdWidget;

/**
 @brief 摇一摇
 @discussion 自渲染摇一摇控件
 shake view widget
*/
@property (strong, nonatomic, readonly, nullable) JADNativeShakeWidget *shakeWidget;

/**
 @brief 上滑
 @discussion 自渲染上滑控件
 swipe view widget
*/
@property (strong, nonatomic, readonly, nullable) JADNativeSwipeWidget *swipeWidget;

@end

NS_ASSUME_NONNULL_END
