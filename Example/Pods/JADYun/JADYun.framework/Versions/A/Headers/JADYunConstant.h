//
//  JADYunConstant.h
//  JADYun
//
//  Created by wangshuai331 on 2021/7/12.
//

#ifndef JADYunConstant_h
#define JADYunConstant_h

typedef NS_ENUM(NSUInteger, JADClickEventTriggerType) {
    /// 支持点击、滑动手势触发的点击事件
    JADClickEventTriggerTypeNormal,
    /// 只支持点击手势触发的点击事件
    JADClickEventTriggerTypeClickOn,
};

/// 落地页打开方式
typedef NS_ENUM(NSInteger, JADInteractionType) {
    /// custom
    JADInteractionTypeCustom = 0,
    /// 原生落地页方式
    JADInteractionTypeURL = 1,
    /// App方式
    JADInteractionTypePage = 2,
};

/// 代码位类型
typedef NS_ENUM(NSUInteger, JADSlotType) {
    /// 未知类型 unknown
    JADSlotTypeUnknown = 0,
    /// 开屏广告 splash ads
    JADSlotTypeSplash = 1,
    /// 信息流图文广告 feed ads
    JADSlotTypeFeed = 2,
    /// 信息流视频广告 feed video ads
    JADSlotTypeFeedVideo = 3,
    /// 插屏广告 interstitial ads
    JADSlotTypeInterstitial = 4,
    /// 横幅广告 banner ads
    JADSlotTypeBanner = 5,
    /// 奖励视频广告 rewarded video ads
    JADSlotTypeRewardedVideo = 6,
};

/// 广告渲染方式
typedef NS_ENUM(NSUInteger, JADRenderModelType) {
    /// 模板渲染
    JADRenderModelTypeTemplatedAd = 1,
    /// 原生渲染
    JADRenderModelTypeNativeAd = 2,
    /// 动态化渲染
    JADRenderModelTypeDynamicAd = 3,
};

/// 开屏样式
typedef NS_ENUM(NSUInteger, JADSplashStyle) {
    /// 采用服务端配置
    JADSplashStyleServerConfig,
    /// 只显示文案，全屏可点击
    JADSplashStyleOnlyText,
    /// 只有文案部分可点击
    JADSplashStyleOnlyTextClick,
    /// 不处理，无文案，全屏可点击
    JADSplashStyleNormal,
    /// 不处理，有文案，全屏可点击
    JADSplashStyleTextNormal,
};

/// 落地页跳转触发来源
typedef NS_ENUM(NSUInteger, JADTriggerSourceType) {
    JADTriggerSourceTypeClick,   /// 点击
    JADTriggerSourceTypeShake,   /// 摇一摇
    JADTriggerSourceTypeSwipeUp, /// 向上滑动
};

/// 广告事件交互方式
typedef NS_ENUM(NSUInteger, JADEventInteractionType) {
    JADEventInteractionTypeNormal,   // 默认点击交互方式
    JADEventInteractionTypeShake,    // 摇一摇交互方式
    JADEventInteractionTypeSwipeUp,   // 上划交互方式
};

/// 点击区域类型
typedef NS_ENUM(NSUInteger, JADClickAreaType) {
    JADClickAreaTypeFullScreen = 1, // 全屏
    JADClickAreaTypeLimit,          // 限点
};

/// 规格集
typedef NS_ENUM(NSUInteger, JADMediaSpecSetType) {
    JADMediaSpecSetType_Normal            = 0,       // 无规格集
    JADMediaSpecSetType_Splash2_3_Single  = 10001,   // 2:3单图
    JADMediaSpecSetType_Splash9_16_Single = 10002,   // 9:16单图
    JADMediaSpecSetType_Feed16_9_Single   = 10003,   // 16:9单图
    JADMediaSpecSetType_Feed3_2_Single    = 10004,   // 3:2单图
    JADMediaSpecSetType_Feed3_2_Group     = 10005,   // 3:2组图
    JADMediaSpecSetType_Feed2_1_Group     = 10006,   // 2:1单图
};

/// 广告交互类型
typedef NS_ENUM(NSUInteger, JADAnimationType) {
    /// 静态可点区域
    JADAnimationTypeHotSpot,
    /// 静态全屏可点击
    JADAnimationTypeFullScreen,
    /// 摇一摇动效类型
    JADAnimationTypeShake,
    /// 向上滑动动效类型
    JADAnimationTypeSwipeUp,
};

#endif /* JADYunConstant_h */
