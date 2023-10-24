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

/**
 根据slotId初始化 adView
 */
- (instancetype)initWithSlotId:(NSString *)slotId;

@end

NS_ASSUME_NONNULL_END
