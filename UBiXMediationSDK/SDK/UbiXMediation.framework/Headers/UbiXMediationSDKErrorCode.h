//
//  UbiXError.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/7/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UbiXErrorCode) {
    UbiXMErrorCodeInitializeFailed       =   10000,
    UbiXMErrorCodePlacementIDError       =   10001,
    UbiXMErrorCodeInternalError          =   10002,
    UbiXMErrorCodeNetWorkError           =   10003,
    UbiXMErrorCodeMaterialError          =   10004,
    UbiXMErrorCodeMaterialDownloadError  =   10005,
    UbiXMErrorCodeNoFill                 =   10006,
    UbiXMErrorCodeNotReady               =   10007,
    UbiXMErrorCodeSplashTimeout          =   20001

};


NS_ASSUME_NONNULL_END
