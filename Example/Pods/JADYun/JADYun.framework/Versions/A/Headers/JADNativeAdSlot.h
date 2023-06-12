//
//  JADNativeAdSlot.h
//  JADYun
//
//  Created by wangshuai331 on 2020/11/2.
//

#import <Foundation/Foundation.h>

#import "JADNativeSize.h"

#if __has_include(<JADYunCore/JADYunConstant.h>)
#import <JADYunCore/JADYunConstant.h>
#else

#import "JADYunConstant.h"

#endif

NS_ASSUME_NONNULL_BEGIN

/// 广告位类
/// 当前类用于初始化自渲染广告
@interface JADNativeAdSlot : NSObject

/// required. 代码位ID The unique identifier of a native ad.
@property (copy, nonatomic) NSString *slotID;

/// required. 广告类型 Ad type.
@property (assign, nonatomic) JADSlotType type;

/// required. 广告尺寸 Image size.
@property (strong, nonatomic) JADNativeSize *imgSize;

/// 开屏广告跳过时间 Splash allowable skipTime , default 5s
@property (assign, nonatomic) CGFloat skipTime;

/// 触发点击事件的手势类型
@property (assign, nonatomic) JADClickEventTriggerType triggerType DEPRECATED_ATTRIBUTE;

/// 事件交互类型，注意：只针对开屏场景生效
@property (assign, nonatomic) JADEventInteractionType eventInteractionType DEPRECATED_ATTRIBUTE;

@end

NS_ASSUME_NONNULL_END
