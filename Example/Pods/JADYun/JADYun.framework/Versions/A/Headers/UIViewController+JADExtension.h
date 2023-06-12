//
//  UIViewController+JADExtension.h
//  JADYun
//
//  Created by wangshuai331 on 2020/8/11.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (JADExtension)

+ (UIViewController *)jadRootViewController;

+ (UIWindow *)jadCurrentWindow;

@end

NS_ASSUME_NONNULL_END
