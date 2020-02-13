//
//  VLionNativeAdNativeModel.h
//  VLionADSDKDemo
//
//  Created by 张旭 on 2017/10/16.
//  Copyright © 2017年 zhulin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VLNNativeAdIconModel.h"

/**
 *  原生广告类型
 */
typedef NS_ENUM(NSInteger, VLNNativeADMode) {
    VLNNativeADModeUnknow = 0,
    VLNNativeADModeSmallImage = 2,
    VLNNativeADModeLargeImage = 3,
    VLNNativeADModeGroupImage = 4,
};

@interface VLNNativeAdNativeModel : NSObject
@property (nonatomic ,copy) NSString * _Nullable            ldp;//跳转url

@property (nonatomic ,strong) NSArray <VLNNativeAdIconModel *>* _Nullable            icon;//图标model
@property (nonatomic ,strong) NSArray <VLNNativeAdIconModel *> * _Nullable            img;//大图model
@property (nonatomic ,copy) NSString * _Nullable            title;//标题名称

@property (nonatomic ,copy) NSString * _Nullable            desc;//标题描述
@property (nonatomic ,assign) int             rating;//评定星级
@property (nonatomic ,copy) NSString * _Nullable            button;//按钮标题
@property (nonatomic ,assign) int            download_count;//下载次数
@property (nonatomic ,copy) NSString * _Nullable            app_download_url    ;//下载地址,和ldp二选一
@property (nonatomic ,copy) NSString * _Nullable      deeplink;//deeplink

@property (nonatomic, assign) VLNNativeADMode imageMode;

+ (VLNNativeAdNativeModel *_Nonnull)modelWithData:(NSDictionary *_Nullable)data;
@end
