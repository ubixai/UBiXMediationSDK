//
//  UbiXMAdsMaterialInfo.h
//  UbiXMediation
//
//  Created by guoqiang on 2025/6/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, UBiXMMaterialType) {
    UBiXMMaterialType_Unknown = 0,    // 未知
    UBiXMMaterialType_Video = 1,      // 视频
    UBiXMMaterialType_Image = 2,      // 图片
};

@interface UbiXMMaterialFea : NSObject
@property (nonatomic, assign) UBiXMMaterialType type;
@property (nonatomic, copy) NSString *materialUrl;
@property (nonatomic, copy) NSString *materialId;
@property (nonatomic, copy) NSString *coverUrl;

- (id)initWithMaterialDic:(NSDictionary *)dic;
@end

@interface UbiXMAdsMaterialInfo : NSObject

@property (nonatomic, copy) NSString *title;

@property (nonatomic, copy) NSString *adDescription;

@property (nonatomic, copy) NSString *creativeId;

@property (nonatomic, copy) NSString *deeplinkUrl;

@property (nonatomic, copy) NSString *landingPageUrl;

@property (nonatomic, copy) NSString *appPackageName;

@property (nonatomic, assign) UBiXMMaterialType materialType;

@property (nonatomic, strong) NSArray<UbiXMMaterialFea *> *materialList;

- (id)initWithMaterialDic:(NSDictionary *)dic;

@end

NS_ASSUME_NONNULL_END
