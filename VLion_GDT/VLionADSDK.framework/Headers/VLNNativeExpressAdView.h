//
//  VLionFeedView.h
//  VLionADSDKDemo
//
//  Created by 1 on 2019/5/21.
//  Copyright © 2019 zhulin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VLNNativeAdModel.h"

@interface VLNNativeExpressAdView : UIView


@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIColor *descColor;
@property (nonatomic, strong) UIColor *buttonColor;
@property (nonatomic, strong) UIColor *vdColor;
/*
 宽为屏幕宽度，高根据model内容变换。render成功后即为曝光
 */
- (void)renderWithAdModel:(VLNNativeAdModel *)adModel;

+ (CGFloat)heightForAdModel:(VLNNativeAdModel *)adModel;

@end

