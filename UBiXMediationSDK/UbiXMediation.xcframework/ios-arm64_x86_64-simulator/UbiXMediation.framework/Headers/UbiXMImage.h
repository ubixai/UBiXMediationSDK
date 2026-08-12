//
//  UbiXMImage.h
//  UbiXMediation
//
//  Created by guoqiang on 2024/6/7.
//

#import "UbiXMInterfaceBaseObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface UbiXMImage : UbiXMInterfaceBaseObject
// image.If is nil,Please use imageURL as the standard to display image.
@property (nonatomic, copy) UIImage *image;

// image address URL
@property (nonatomic, copy) NSString *imageURLStr;

// image width
@property (nonatomic, assign) float width;

// image height
@property (nonatomic, assign) float height;

// image scale
@property (nonatomic, assign) float scale;
@end

NS_ASSUME_NONNULL_END
