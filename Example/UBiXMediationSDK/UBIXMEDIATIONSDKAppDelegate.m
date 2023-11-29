//
//  UBIXMEDIATIONSDKAppDelegate.m
//  UBiXMediationSDK
//
//  Created by stefan.qi on 06/10/2023.
//  Copyright (c) 2023 stefan.qi. All rights reserved.
//

#import "UBIXMEDIATIONSDKAppDelegate.h"
#import <UbiXMediation/UbiXMediationSDK.h>
#import <UbiXMediation/UbiXMediationSplash.h>
#import <UbiXDaq/UbiXDaq.h>
#import <UbiXAdSDK/UbiXAdSDK.h>
#import "UBIXMEDIATIONSDKViewController.h"
#import <BUAdSDK/BUAdSDK.h>

@interface AdWindow : UIWindow <UbiXMediationSplashDelegate>
@property (nonatomic, strong)UbiXMediationSplash *splash;
@property (nonatomic, assign)BOOL isClick;
@end
@implementation AdWindow
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        self.isClick = NO;
        
//        [self requestSplash];
    }
    return self;
}

- (void)requestSplash {
    self.splash = [[UbiXMediationSplash alloc] initWithSlotId:@"14072154"];
    self.splash.delegate = self;
    self.splash.rootViewController = self.rootViewController; // 此时还没有rootVC
    UILabel *bottom = [[UILabel alloc] init];
    bottom.backgroundColor = [UIColor orangeColor];
    bottom.text = @"开发者自定义view";
    bottom.frame = CGRectMake(0, [UIScreen mainScreen].bounds.size.height, [UIScreen mainScreen].bounds.size.width, 100);
    bottom.contentMode = UIViewContentModeCenter;
    bottom.textAlignment = NSTextAlignmentCenter;
    if (arc4random()%2==1) {
        self.splash.bottomView = bottom;
    }
    [self.splash loadAd];
}


- (void)dealloc {
    self.splash = nil;
//    DEMOLOG(@"____adwindow dealloc____");
}
// 开屏广告加载成功
- (void)mediationSplashDidLoad:(UbiXMediationSplash *)splash{
    NSLog(@"开屏广告加载成功 %s", __func__);
//    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    if ([self.splash isReady]) {
        [self.splash showAd:self];
    }
}

// 开屏广告展示成功
- (void)mediationSplashDidShow:(UbiXMediationSplash *)splash{
    NSLog(@"开屏广告展示成功 %s", __func__);
    self.backgroundColor = [UIColor clearColor];
    UBIXMEDIATIONSDKAppDelegate *app = [[UIApplication sharedApplication] delegate];
    if ([app respondsToSelector:@selector(adShow)]) {
        [app performSelector:@selector(adShow)];
    }
}

// 展示失败回调
- (void)mediationSplashDidFailToShow:(UbiXMediationSplash *)splash error:(NSError *)error {
    NSLog(@"开屏广告展示失败 %s", __func__);
    UBIXMEDIATIONSDKAppDelegate *app = [[UIApplication sharedApplication] delegate];
    if ([app respondsToSelector:@selector(adShowFail)]) {
        [app performSelector:@selector(adShowFail)];
    }
}

// 开屏广告加载失败回调
- (void)mediationSplashDidFailToLoad:(UbiXMediationSplash *)splash error:(NSError *)error{
    NSLog(@"开屏广告加载失败回调 %s : %@", __func__, error);
    UBIXMEDIATIONSDKAppDelegate *app = [[UIApplication sharedApplication] delegate];
    if ([app respondsToSelector:@selector(adFail)]) {
        [app performSelector:@selector(adFail)];
    }
    if ([app respondsToSelector:@selector(adClose)]) {
        [app performSelector:@selector(adClose) onThread:[NSThread mainThread] withObject:nil waitUntilDone:NO];
    }
}

// 开屏点击广告回调
- (void)mediationSplashDidClick:(UbiXMediationSplash *)splash{
    NSLog(@"开屏广告点击回调 %s", __func__);
    self.isClick = YES;
    UBIXMEDIATIONSDKAppDelegate *app = [[UIApplication sharedApplication] delegate];
    if ([app respondsToSelector:@selector(adClick)]) {
        [app performSelector:@selector(adClick)];
    }
}

// 开屏关闭广告回调
- (void)mediationSplashDidClosed:(UbiXMediationSplash *)splash skip:(BOOL)isSkip{
    NSLog(@"开屏广告关闭回调 %s", __func__);
    UBIXMEDIATIONSDKAppDelegate *app = [[UIApplication sharedApplication] delegate];
    if ([app respondsToSelector:@selector(adClose)]) {
        [app performSelector:@selector(adClose) onThread:[NSThread mainThread] withObject:nil waitUntilDone:NO];
    }
    
}
- (void)mediationSplashDidFinishConversion:(UbiXMediationSplash *)splash{
    NSLog(@"开屏广告转化完成 %s", __func__);
    UBIXMEDIATIONSDKAppDelegate *app = [[UIApplication sharedApplication] delegate];
    if ([app respondsToSelector:@selector(adShowClose)]) {
        [app performSelector:@selector(adShowClose)];
    }
}
@end

@interface UBIXMEDIATIONSDKAppDelegate ()

@property (nonatomic, strong) AdWindow *adWindow;
@property (nonatomic, strong) dispatch_source_t timer;

@end

@implementation UBIXMEDIATIONSDKAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    
    NSLog(@"N.O.W, v%@", UbiXMediationSDK.sdkVersion);
    NSLog(@"daq, v%@", UBIX_DAQ_VERSION);
    NSLog(@"UBIX, v%@", UBiXAdSDKManager.SDKVersion);
    NSLog(@"Pangle, v%@", BUAdSDKManager.SDKVersion);
    
    [self setupUBiXMediationSDK];
    
    UBIXMEDIATIONSDKViewController *vc = [[UBIXMEDIATIONSDKViewController alloc] init];
    UINavigationController *navi = [[UINavigationController alloc] initWithRootViewController:vc];
    
    _adWindow = [[AdWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    _adWindow.backgroundColor = [UIColor whiteColor];
    _adWindow.windowLevel = UIWindowLevelAlert + 1000000;
    _adWindow.rootViewController = [[UIViewController alloc] init];
    [_adWindow makeKeyAndVisible];
    [_adWindow requestSplash];

    _window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    _window.backgroundColor = [UIColor whiteColor];
    _window.rootViewController = navi;
    
    return YES;
}

- (void)setupUBiXMediationSDK {
    // sdk 配置
    UbiXMAdConfig *adConfig = [[UbiXMAdConfig alloc] init];
    // 隐私配置
    UbiXMConcealConfig *concealConfig = [[UbiXMConcealConfig alloc] init];
    concealConfig.isCanReadIDFA = NO;
    concealConfig.isOpenLog = YES;
    adConfig.concealConfig = concealConfig;
    // 用户配置
    UbiXMUserInfoConfig *usrConfig = [[UbiXMUserInfoConfig alloc] init];
    usrConfig.userId = @"Your_user_id";
    adConfig.userInfoConfig = usrConfig;
    // 初始化
    [UbiXMediationSDK initializeWithAppId:@"138820189206" adConfig:adConfig];
}

- (void)adClose {
    [_window makeKeyAndVisible];
    
    _adWindow = nil;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
