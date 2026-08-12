//
//  UbiXMediationFeedAdView.h
//  UbiXMediation
//
//  Created by stefan.qi on 2022/8/12.
//

#import <UIKit/UIKit.h>
#import <UbiXMediation/UbiXMediationEnum.h>


NS_ASSUME_NONNULL_BEGIN

@protocol UbiXMediationFeedAdViewDelegate;
@class UbiXMedationFeedAdModel;

@interface UbiXMediationFeedAdView : UIView

/**
 * 接口即将废弃，不再进行使用
 */
@property (nonatomic, weak) id<UbiXMediationFeedAdViewDelegate> delegate;

// 扩展参数
@property (nonatomic, strong)NSDictionary *extraParams;

@end


@protocol UbiXMediationFeedAdViewDelegate <NSObject>

@optional
// 信息流广告展示成功
- (void)mediationFeedAdViewDidShow:(UbiXMedationFeedAdModel *)feedAdModel;

// 信息流广告点击回调
- (void)mediationFeedAdViewDidClick:(UbiXMedationFeedAdModel *)feedAdModel;

// 信息流广告关闭回调
- (void)mediationFeedAdViewDidClosed:(UbiXMedationFeedAdModel *)feedAdModel;

// 信息流广告打开落地页回调 仅支持:天璇UBiX 自渲染
-(void)mediationFeedAdDidPresentDetail:(UbiXMedationFeedAdModel*)adModel landingType:(UbiXMAdLandingType)landingType;

// 信息流广告开始播放回调
- (void)mediationFeedAdViewDidStartPlay:(UbiXMedationFeedAdModel *)feedAdModel;

// 信息流广告结束播放回调
- (void)mediationFeedAdViewDidFinishPlay:(UbiXMedationFeedAdModel *)feedAdModel;

// 信息流广告播放出错
- (void)mediationFeedAdView:(UbiXMedationFeedAdModel *)feedAdModel didPlayError:(NSError *)error;

// 信息流广告消失, 仅支持: 天璇 UBiX 信息流模版
- (void)mediationFeedAdViewDidDisMiss:(UbiXMedationFeedAdModel *)feedAdModel;

// 信息流广告关闭落地页回调 仅支持:天璇UBiX 自渲染
-(void)mediationFeedAdDidDismissDetail:(UbiXMedationFeedAdModel*)adModel landingType:(UbiXMAdLandingType)landingType;

@end

NS_ASSUME_NONNULL_END
