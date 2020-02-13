//
//  VLNNativeAd.h
//  VLionADSDKDemo
//
//  Created by 1 on 2019/6/5.
//  Copyright © 2019 zhulin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VLNNativeAdModel.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VLNNativeAdDelegate;

@interface VLNNativeAd : NSObject

/**
 *  广告位 ID
 */
@property (nonatomic, copy, readonly) NSString * tagId;

- (instancetype)initWithTagId:(NSString *)tagId;

- (void)loadAdData;

/*
 *  viewControllerForPresentingModalView
 *  详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *viewController;

/**
 *  委托对象
 */
@property (nonatomic, weak) id<VLNNativeAdDelegate> delegate;


/**
 *  广告数据渲染完毕即将展示时调用方法（设置后即曝光）。
 *  详解：[必选]广告数据渲染完毕，即将展示时需调用本方法。
 *      @param nativeAdModel 广告渲染的数据实体
 *      @param view         渲染出的广告结果页面
 */
+ (void)registerAdModel:(VLNNativeAdModel *)nativeAdModel toView:(UIView *)view;

/**
 卸载点击事件
 */
+ (void)unregisterAdModel:(VLNNativeAdModel *)nativeAdModel;

@end

@protocol VLNNativeAdDelegate <NSObject>

/**
 *  原生广告加载广告数据成功回调，返回为VLionNativeAdModel对象
 */
- (void)nativeAd:(VLNNativeAd *)nativeAd successToLoad:(VLNNativeAdModel *)nativeAdModel;

/**
 *  原生广告加载广告数据失败回调
 */
- (void)nativeAd:(VLNNativeAd *)nativeAd didFailWithError:(NSError *)error;

@optional

/**
 广告曝光回调
 */
- (void)nativeAdExposured:(VLNNativeAd *)nativeAd;

/**
 广告点击回调
 */
- (void)nativeAdDidClick:(VLNNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
