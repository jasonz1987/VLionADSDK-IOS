//
//  VLNInterstitialAd.h
//  VLionADSDKDemo
//
//  Created by 1 on 2019/6/3.
//  Copyright © 2019 zhulin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VLNInterstitialAdDelegate;

@interface VLNInterstitialAd : NSObject

/**
 *  广告位 ID
 */
@property (nonatomic, copy, readonly) NSString * tagId;

/**
 *  插屏广告预加载是否完成
 */
@property (nonatomic, assign, readonly) BOOL isReady;

/**
 *  拉取广告时显示的占位图片
 *  详解：拉取广告过程中会用此图片占位。 通常设置为应用启动时的启动图即可。
 */
@property (nonatomic, strong) UIImage *placeholderImage;


@property (nonatomic, weak) id<VLNInterstitialAdDelegate> delegate;

/**
 *  构造方法
 @param tagId - 广告位 ID
 */
- (instancetype)initWithTagId:(NSString *)tagId;

/**
 *  广告发起请求并展示在viewController中
 *  发起拉取广告请求,并将获取的广告以全屏形式展示在传入的viewController参数中
 *  提示: Splash广告只支持竖屏
 @param viewController 展示插屏广告容器容器
 */
- (void)loadAdData;

- (void)presentFromRootViewController:(UIViewController *)viewController;

@end

@protocol VLNInterstitialAdDelegate <NSObject>

@optional
/**
 插屏广告成功展示.
 */
- (void)interstitialAdDidLoad:(VLNInterstitialAd *)interstitialAd;

/**
 插屏广告展示失败.
 @param error :失败error
 */
- (void)interstitialAd:(VLNInterstitialAd *)interstitialAd didFailWithError:(NSError *)error;

/**
 插屏广告曝光回调
 */
- (void)interstitialAdExposured:(VLNInterstitialAd *)interstitialAd;

/**
 插屏广告点击回调
 */
- (void)interstitialAdDidClick:(VLNInterstitialAd *)interstitialAd;

/**
 插屏广告关闭回调
 */
- (void)interstitialAdDidClose:(VLNInterstitialAd *)interstitialAd;

/**
 插屏广告将要关闭回调
 */
- (void)interstitialAdWillClose:(VLNInterstitialAd *)interstitialAd;

@end

NS_ASSUME_NONNULL_END
