//
//  UBiXMFeedbackIconView.h
//  UbiXMediation
//
//  Created by stefan.qi on 2023/7/19.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UBiXMFeedbackIconViewDelegate <NSObject>

/// 负反馈按钮被点击
- (void)feedbackIconDidClicked;

/// 负反馈流程结束
- (void)feedbackViewDidClosed;

/// 负反馈结束
- (void)feedbackViewDidFinishedWithTypeIndex:(NSString * _Nullable)typeIndexString andOtherInfoText:(NSString * _Nullable)adviceInfo;

///

@end


@interface UBiXMFeedbackIconView : UILabel

@property (nonatomic, weak)id<UBiXMFeedbackIconViewDelegate> delegate;

// 根据宽高比例还有容器的frame创建View
- (instancetype)initWithFrame:(CGRect)frame contentViewSize:(CGSize)contentViewSize width:(NSInteger)widthPercent height:(NSInteger)heightPercent;

@end

NS_ASSUME_NONNULL_END
