//
//  UbiXMediationNativeAd.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/7.
//

#import "UbiXMInterfaceBaseObject.h"
#import "UbiXMediationNativeAdData.h"
#import "UbiXMediationNativeAdViewCreator.h"

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMediationNativeAd : UbiXMInterfaceBaseObject
// 广告物料，包含有最全的广告数据
@property (nonatomic, strong, nonnull) id<UbiXMediationNativeAdData> data;

// 广告视图创建对象，对常用广告展示元素进行创建（存在意义：对部分adn创建特定视图的支持）
@property (nonatomic, strong, nonnull) id<UbiXMediationNativeAdViewCreator> viewCreator;

// 广告视图对象（存在意义：对部分adn创建特定视图的支持）
@property (nonatomic, strong, nonnull) UIView *view;

@property (nonatomic, assign) BOOL isVideoAd;

// adn获取到的原始广告数据
@property (nonatomic, strong, nonnull) id originMediatedNativeAd;
@end

NS_ASSUME_NONNULL_END
