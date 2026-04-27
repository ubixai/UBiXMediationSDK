//
//  UbiXMCustomBannerAdapter.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/20.
//

#ifndef UbiXMCustomBannerAdapter_h
#define UbiXMCustomBannerAdapter_h

#import "UbiXMCustomBannerAdapterBridge.h"


/// 自定义banner广告adapter协议
@protocol UbiXMCustomBannerAdapter <UbiXMCustomAdapter>

/// 必要，加载banner广告方法
/// @param slotID adn的广告位ID
/// @param adSize 广告展示尺寸
/// @param parameter 广告加载参数
- (void)loadBannerAdWithSlotID:(NSString *)slotID andSize:(CGSize)adSize parameter:(nullable NSDictionary *)parameter;

- (void)showBannerWithParameter:(nullable NSDictionary *)parameter;

/// 当前加载的广告的状态
- (UbiXMMediatedAdStatus)mediatedAdStatus;

@optional
/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<UbiXMCustomBannerAdapterBridge> bridge;

@end


#endif /* UbiXMCustomBannerAdapter_h */
