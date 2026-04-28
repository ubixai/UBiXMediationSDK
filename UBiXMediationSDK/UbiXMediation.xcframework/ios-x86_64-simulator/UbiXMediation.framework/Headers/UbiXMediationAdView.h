//
//  UbiXMediationAdView.h
//  UbiXMediation
//
//  Created by guoqiang on 2023/7/18.
//

#import <UIKit/UIKit.h>
#import "UbiXMediationObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMediationAdView : UIView <UbiXMediationAdProtocol>

// 展示落地页的controller, 如果不传默认使用keyWindow.rootVC
@property (nonatomic, weak)UIViewController *rootViewController;



@end

NS_ASSUME_NONNULL_END
