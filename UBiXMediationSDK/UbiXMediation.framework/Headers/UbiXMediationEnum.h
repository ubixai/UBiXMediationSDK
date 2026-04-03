//
//  UbiXMediationEnum.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/7.
//

#ifndef UbiXMediationEnum_h
#define UbiXMediationEnum_h

extern NSString *const kUBiXMExtraModel_SensorEnabled;

typedef NS_ENUM(NSInteger, UBiXMVideoMuteType) {
    UBiXMVideoMuteType_Unknown = 0,    // 未知
    UBiXMVideoMuteType_Mute = 1,       // 静音
    UBiXMVideoMuteType_NoMute = 2,     // 不静音
};

typedef NS_ENUM(NSInteger, UBiXMVideoPlayNetType) {
    UBiXMVideoPlayNetType_Unknown = 0,        // 未知
    UBiXMVideoPlayNetType_WifiAndMobile = 1,  // wifi+移动
    UBiXMVideoPlayNetType_OnlyWifi = 2,       // 仅wifi
    UBiXMVideoPlayNetType_Never = 3,          // 不播放
};

typedef NS_ENUM(NSInteger, UbiXMVideoPlayerStatus) {
    UbiXMVideoPlayerStatusFailed = -1, // 加载失败
    UbiXMVideoPlayerStatusInitialize,  // 初始
    UbiXMVideoPlayerStatusPrepared,    // 准备好，可以播放了
    UbiXMVideoPlayerStatusStarted,
    UbiXMVideoPlayerStatusPlaying,     // 播放中
    UbiXMVideoPlayerStatusBuffering,   // 加载中
    UbiXMVideoPlayerStatusPaused,      // 暂停
    UbiXMVideoPlayerStatusInterrupted, // 中断
    UbiXMVideoPlayerStatusStopped,     // 停止
    UbiXMVideoPlayerStatusFinished,    // 完成/结束
    UbiXMVideoPlayerStatusError = -2,  // 播放错误
};

#endif /* UbiXMediationEnum_h */
