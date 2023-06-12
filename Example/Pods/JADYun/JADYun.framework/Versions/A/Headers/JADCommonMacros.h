//
//  JADCommonMacros.h
//  JADYun
//
//  Created by wangshuai331 on 2020/9/8.
//  Copyright © 2020 JD.COM. All rights reserved.
//

#ifndef JADCommonMacros_h
#define JADCommonMacros_h

/*********************************************************************************************************/
//强弱引用转换，用于解决代码块（block）与强引用对象之间的循环引用问题
#ifndef jad_weakify
#if __has_feature(objc_arc)
#define jad_weakify(object) __weak __typeof__(object) weak##object = object;
#else
#define jad_weakify(object) __block __typeof__(object) block##object = object;
#endif
#endif
#ifndef jad_strongify
#if __has_feature(objc_arc)
#define jad_strongify(object) __typeof__(object) object = weak##object;
#else
#define jad_strongify(object) __typeof__(object) object = block##object;
#endif
#endif

/*********************************************************************************************************/

#define JADScreenWidth      ([UIScreen mainScreen].bounds.size.width)
#define JADScreenHeight     ([UIScreen mainScreen].bounds.size.height)

#ifndef JADMAXScreenSide
#define JADMAXScreenSide    MAX([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height)
#endif

#define JADIsNotchScreen                jad_is_notch_screen()
#define JADiPhoneX                      JADIsNotchScreen
#define kJADDefaultNavigationBarHeight  jad_default_navigationBarHeight() // 状态栏+导航栏的高度
#define kJADSafeTopMargin               jad_safeTopMargin()               // 顶部安全区高度
#define kJADDefaultStautsBarHeight      jad_default_statusBarHeight()     // 状态栏高度

#define JAD_IS_NULL(obj)             (obj == nil || obj == (id)[NSNull null])
#define JAD_IS_NOT_NULL(obj)         (obj != nil && obj != (id)[NSNull null])
#define JAD_STR_EMPTY(obj)           ((JAD_IS_NULL(obj)) || (![obj isKindOfClass:[NSString class]]) || [obj length] == 0 )
#define JAD_DATA_EMPTY(obj)          ((JAD_IS_NULL(obj)) || (![obj isKindOfClass:[NSData class]]) || [obj length] == 0 )
#define JAD_SAFE_STRING(obj)         ((JAD_IS_NOT_NULL(obj))?obj:@"")

FOUNDATION_EXPORT BOOL jad_is_notch_screen(void);
FOUNDATION_EXPORT CGFloat jad_safeTopMargin(void);
FOUNDATION_EXPORT CGFloat jad_default_statusBarHeight(void);
FOUNDATION_EXPORT CGFloat jad_default_navigationBarHeight(void);

#endif /* JADCommonMacros_h */
