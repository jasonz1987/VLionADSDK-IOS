//
//  VLNRewardedVideoAd.h
//  VLionADSDKDemo
//
//  Created by 1 on 2019/6/10.
//  Copyright © 2019 zhulin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VLNRewardedVideoAdDelegate;

@interface VLNRewardedVideoAd : NSObject

@property (nonatomic, weak) id <VLNRewardedVideoAdDelegate> delegate;
/**
 *  广告位 ID
 */
@property (nonatomic, copy, readonly) NSString * tagId;

/**
 构造方法
 
 @param tagId - 广告位 ID
 @return 实例
 */
- (instancetype)initWithTagId:(NSString *)tagId;

/**
 加载广告方法 支持 iOS8.1 及以上系统
 */
- (void)loadAd;

/**
 展示广告方法
 
 @param rootViewController 用于 present 激励视频 VC
 @return 是否展示成功
 */
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController;

@end

@protocol VLNRewardedVideoAdDelegate <NSObject>

@optional

/**
 广告数据加载成功回调
 */
- (void)rewardVideoAdDidLoad:(VLNRewardedVideoAd *)rewardedVideoAd;

/**
 视频数据下载成功回调，已经下载过的视频会直接回调
 */
- (void)rewardVideoAdVideoDidLoad:(VLNRewardedVideoAd *)rewardedVideoAd;

/**
 视频播放页即将展示回调
 */
- (void)rewardVideoAdWillVisible:(VLNRewardedVideoAd *)rewardedVideoAd;

/**
 视频广告曝光回调
 */
- (void)rewardVideoAdDidExposed:(VLNRewardedVideoAd *)rewardedVideoAd;

/**
 视频播放页关闭回调
 */
- (void)rewardVideoAdDidClose:(VLNRewardedVideoAd *)rewardedVideoAd;

/**
 视频广告信息点击回调
 */
- (void)rewardVideoAdDidClicked:(VLNRewardedVideoAd *)rewardedVideoAd;

/**
 视频广告各种错误信息回调
 */
- (void)rewardVideoAd:(VLNRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;

/**
 视频广告播放达到激励条件回调
 */
- (void)rewardVideoAdDidRewardEffective:(VLNRewardedVideoAd *)rewardedVideoAd;

/**
 视频广告视频播放完成
 */
- (void)rewardVideoAdDidPlayFinish:(VLNRewardedVideoAd *)rewardedVideoAd;

@end

NS_ASSUME_NONNULL_END
