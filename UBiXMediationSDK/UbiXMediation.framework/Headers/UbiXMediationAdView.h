//
//  UbiXMediationAdView.h
//  UbiXMediation
//
//  Created by guoqiang on 2023/7/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMediationAdView : UIView

@property (nonatomic, copy) NSString *slotId;
// 广告requestId
@property (nonatomic, copy) NSString *requestId;

// 展示落地页的controller, 如果不传默认使用keyWindow.rootVC
@property (nonatomic, weak)UIViewController *rootViewController;

/**
 根据slotId初始化 adView
 */
- (instancetype)initWithSlotId:(NSString *)slotId;

- (id)extraInfoForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
