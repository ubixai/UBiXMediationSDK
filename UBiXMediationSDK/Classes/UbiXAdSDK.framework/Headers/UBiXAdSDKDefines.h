//
//  Header.h
//  UbiXAdSDK
//
//  Created by UbiX on 2021/10/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 交互类型
typedef NS_ENUM(NSInteger, UBiXAdInteractionType) {
    UBiXAdInteractionTypeUnknown,        //unknown type
    UBiXAdInteractionTypeApp,            //open download page in-app
    UBiXAdInteractionTypeWeb,            //open webpage in-app
    UBiXAdInteractionTypeDeepLink,       //open deeplink
    UBiXAdInteractionTypeAppStore,       //open appstore
    UBiXAdInteractionTypeSafari,         //open safari
    UBiXAdInteractionTypeError           //can`t open landing page
};

/// 素材类型
typedef NS_ENUM(NSInteger, UBiXAdMaterialType) {
    UBiXAdMaterialTypeUnknown        = 0, /// 未知
    UBiXAdMaterialTypeSingleImage    = 1, /// 单图
    UBiXAdMaterialTypeMultipleImages = 2, /// 多图
    UBiXAdMaterialTypeVideo          = 3, /// 视频
};
NS_ASSUME_NONNULL_END
