//
//  JADInterstitialAd.h
//  JADYun
//
//  Created by wangshuai331 on 2021/1/20.
//

#import <Foundation/Foundation.h>

#if __has_include(<JADYunCore/JADYunConstant.h>)
#import <JADYunCore/JADYunConstant.h>
#else
#import "JADYunConstant.h"
#endif

#import "JADInterstitialAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
  插屏广告
 
  插屏广告是一种全屏展现的广告类型，通常用于 App 中自然的场景切换过程。
 
  A customized Ad to represent a JADYun ad (interstitial ad).
   
  注意！接入时请对照京媒平台比例传入宽高值，且高度值不可传入0。
 
    代码示例：
    
        @property (strong, nonatomic) JADInterstitialAd *interstitialAd;
        
        //初始化一个插屏广告对象
        - (JADInterstitialAd *)interstitialAd {
            if(!_interstitialAd){
                _interstitialAd = [[JADInterstitialAd alloc] initWithSlotID:@"YOUR_SLOT_ID" adSize:CGSizeMake(interstitialWidth, interstitialHeight)];
                _interstitialAd.delegate = self;
            }
            return _interstitialAd;
        }
 
        //加载广告
        [self.interstitialAd loadAdData];
 */
@interface JADInterstitialAd : NSObject

/**
 * @brief 代码位ID
 * @discussion 属性：代码位ID
 *
 * The interstitialView's ad slot slotID.
 */
@property (nonatomic, copy, readonly, nullable) NSString *slotID;

/**
 * @brief 关闭按钮隐藏属性
 * @discussion 通过该字段设置关闭按钮隐藏属性 设置为YES，关闭按钮隐藏，为NO,关闭按钮不隐藏
 * hide close button
 */
@property (nonatomic, assign) BOOL hideCloseButton;

/**
 * @brief 广告视图代理
 * @discussion 插屏视图 delegate. 设置视图代理后，才可以正常收到相关回调
 *
 * The interstitialView's ad delegate.
 */
@property (nonatomic, weak) id <JADInterstitialAdDelegate> delegate;

/**
 * @brief 广告价格
 * @discussion 广告价格 Ad price
 * 该字段含义为广告价格，单位为 分
 */
@property (nonatomic, assign, readonly) NSInteger price;

/**
 * @brief 手势类型
 * @discussion 手势类型 Event Trigger Type
 *
 * 触发点击事件的手势类型 ，详细枚举可查看JADYunConstant.h定义
 */
@property (nonatomic, assign) JADClickEventTriggerType triggerType DEPRECATED_ATTRIBUTE;

/**
 * @brief 初始化插屏广告view
 * @param slotID 代码位ID
 * @param adSize 代码位的大小，请确保：size 的 width : height = 1:1 or 2:3 or 3:2
 * @discussion 广告对象初始化 Ad  init
 */
- (instancetype)initWithSlotID:(NSString *)slotID
                        adSize:(CGSize)adSize;

/**
 * @brief 预缓存广告
 * @discussion 预缓该广告位广告数据
 * Preload interstitial view ad data.
 */
- (void)preloadAdData;

/**
 * @brief 加载广告
 * @discussion 加载插屏广告
 * Load interstitial view ad data.
 * 使用该方法加载横幅广告
 */
- (void)loadAdData;

/**
 * @brief 控制器
 * @param rootViewController 插屏广告显示所需的控制器   root view controller for displaying ad.
 * @discussion 插屏广告显示在控制器window上，可以在素材渲染成功回调中调用该方法
 *
 * Display interstitial view ad.
 *
 * 代码示例：
 *
 *   - (void)jadInterstitialAdDidRenderSuccess:(JADInterstitialAd *)interstitialAd {
 *       [self.interstitialAd showAdFromRootViewController:self];
 *   }
 */
- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

/**
 * @brief 删除插屏视图。
 * @discussion 如果您自定义跳过按钮，则需要调用此方法来关闭开屏广告。
 */
- (void)removeInterstitialView;

@end

NS_ASSUME_NONNULL_END
