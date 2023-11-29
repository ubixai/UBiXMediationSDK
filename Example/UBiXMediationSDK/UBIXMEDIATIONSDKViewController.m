//
//  UBIXMEDIATIONSDKViewController.m
//  UBiXMediationSDK
//
//  Created by stefan.qi on 06/10/2023.
//  Copyright (c) 2023 stefan.qi. All rights reserved.
//

#import "UBIXMEDIATIONSDKViewController.h"
#import <UbiXMediation/UbiXMediation.h>

@interface UBIXMEDIATIONSDKViewController ()

@end

@implementation UBIXMEDIATIONSDKViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor = [UIColor lightGrayColor];
    self.title = [NSString stringWithFormat:@"N.O.W,V%@", [UbiXMediationSDK sdkVersion]];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
