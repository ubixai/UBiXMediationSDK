//
//  UbiXMCustomInterstitialAdapter.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/18.
//

#ifndef UbiXMCustomInterstitialAdapter_h
#define UbiXMCustomInterstitialAdapter_h

#import <Foundation/Foundation.h>
#import "UbiXMCustomAdapter.h"
#import "UbiXMCustomInterstitialAdapterBridge.h"

/// 自定义插屏广告的adapter广告协议
@protocol UbiXMCustomInterstitialAdapter <UbiXMCustomAdapter>

/// 加载广告的方法
/// @param slotID adn的广告位ID
/// @param size 广告展示尺寸
/// @param parameter 广告加载的参数
- (void)loadInterstitialAdWithSlotID:(NSString *)slotID andSize:(CGSize)size parameter:(NSDictionary *)parameter;

/// 展示广告的方法
/// @param viewController 控制器对象
/// @param parameter 展示广告的参数，由UbiXM接入媒体配置
- (BOOL)showAdFromRootViewController:(UIViewController *_Nonnull)viewController parameter:(NSDictionary *)parameter;

/// 当前加载的广告的状态
- (UbiXMMediatedAdStatus)mediatedAdStatus;

@optional
/// 代理，开发者需使用该对象回调事件，Objective-C下自动生成无需设置，Swift需声明
@property (nonatomic, weak, nullable) id<UbiXMCustomInterstitialAdapterBridge> bridge;
@end

#endif /* UbiXMCustomInterstitialAdapter_h */
