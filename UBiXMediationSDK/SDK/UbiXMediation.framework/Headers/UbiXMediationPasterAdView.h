//
//  UbiXMediationPasterAdView.h
//  UbiXMediation
//
//  Created by stefan.qi on 2023/1/4.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UbiXMediationPasterAdViewDelegate;
@class UbiXMediationPasterAdModel;

@interface UbiXMediationPasterAdView : UIView

/**
 * 接口即将废弃，不再进行使用
 */
@property (nonatomic, weak) id<UbiXMediationPasterAdViewDelegate> delegate;

// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;

@end



@protocol UbiXMediationPasterAdViewDelegate <NSObject>

@optional
// 贴片广告展示成功
- (void)mediationFeedAdViewDidShow:(UbiXMediationPasterAdModel *)pasterModel;

// 贴片广告点击回调
- (void)mediationFeedAdViewDidClick:(UbiXMediationPasterAdModel *)pasterModel;

// 贴片广告移除回调
- (void)mediationFeedAdViewDidClosed:(UbiXMediationPasterAdModel *)pasterModel;

// 贴片广告移除回调
- (void)mediationFeedAdViewDidStartPlay:(UbiXMediationPasterAdModel *)pasterModel;

// 贴片广告移除回调
- (void)mediationFeedAdViewDidFinishPlay:(UbiXMediationPasterAdModel *)pasterModel;

// 贴片广告移除回调
- (void)mediationFeedAdView:(UbiXMediationPasterAdModel *)pasterModel didPlayError:(NSError *)error;


@end

NS_ASSUME_NONNULL_END
