//
//  VLNBannerView.h
//  VLionADSDKDemo
//
//  Created by 1 on 2019/5/31.
//  Copyright © 2019 zhulin. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VLNBannerViewDelegate;

@interface VLNBannerView : UIView

/**
 *  构造方法
 @param tagId - 广告位 ID
 */
- (instancetype)initWithTagId:(NSString *)tagId;

/**
 *  广告位 ID
 */
@property (nonatomic, copy, readonly) NSString * tagId;

/**
 *  父视图
 *  详解：[必选]需设置为显示广告的UIViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;


@property (nonatomic, weak) id<VLNBannerViewDelegate> delegate;

- (void)loadAdAndShow;

@end

@protocol VLNBannerViewDelegate <NSObject>

/**
 Banner广告数据加载成功. 告知banner图片的大小。
 必须实现，size计算bannerView的大小
 */
- (CGRect)bannerView:(VLNBannerView *)bannerView didLoadBannerImageSize:(CGSize)size;

@optional

/**
 Banner广告加载成功. 加载成功后会frame即为图片的标准大小。
 */
- (void)bannerViewDidLoad:(VLNBannerView *)bannerView;

/**
 Banner广告展示失败.
 @param error :失败error
 */
- (void)bannerView:(VLNBannerView *)bannerView didFailWithError:(NSError *)error;

/**
 Banner广告曝光回调
 */
- (void)bannerViewExposured:(VLNBannerView *)bannerView;

/**
 Banner广告点击回调
 */
- (void)bannerViewDidClick:(VLNBannerView *)bannerView;

/**
 Banner广告将点敲关闭回调
 */
- (void)bannerViewWillClose:(VLNBannerView *)bannerView;

@end

NS_ASSUME_NONNULL_END
