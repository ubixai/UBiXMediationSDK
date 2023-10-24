//
//  UbiXMediationPaster.h
//  UbiXMediation
//
//  Created by stefan.qi on 2022/12/6.
//

#import <UIKit/UIKit.h>
#import <UbiXMediation/UbiXMediationPasterAdModel.h>
#import <UbiXMediation/UbiXMediationMaterialData.h>
#import <UbiXMediation/UbiXMediationMediaView.h>
#import <UbiXMediation/UbiXMediationObject.h>

NS_ASSUME_NONNULL_BEGIN

@class UbiXMediationPaster;

@protocol UbiXMediationPasterDelegate <NSObject>

@optional
// paster广告加载成功
- (void)mediationPasterDidLoad:(NSArray<UbiXMediationPasterAdModel *> *)pasterAds;

// paster广告加载失败回调
- (void)mediationPasterDidFailToLoad:(UbiXMediationPaster *)paster error:(NSError *)error;

@end

@interface UbiXMediationPaster : UbiXMediationObject

@property (nonatomic, weak)id<UbiXMediationPasterDelegate> delegate;

@property (nonatomic, weak) UIViewController *rootViewController;

// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;

// 广告数组
@property (nonatomic, strong)NSArray *adViewArray;

/**
 根据广告尺寸加载广告
 load前确定好rootViewController, 用于present落地页
 @param count 一次取的广告数量，取值范围为 1-10
 */
- (void)loadAdWithAdSize:(CGSize)adSize Count:(NSInteger)count;

- (void)destroyAd;

/** 广告是否可用 */
- (BOOL)isReady;

/** 广告是否有效 */
- (BOOL)isAvaliable;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

@end

NS_ASSUME_NONNULL_END
