//
//  JMLaunchAdView.h
//  JMLaunchAdFramework
//
//  Created by JM on 2020/6/17.
//  Copyright © 2020 JM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIImageView+JMWebCache.h"

@class JMLaunchAdView;

typedef void (^JMLaunchAdClickBlock)(void);

typedef void (^JMSetLaunchAdBlock)(JMLaunchAdView * _Nullable launchAdView);

typedef NS_ENUM(NSUInteger, JMSkipShowType)
{
    JMSkipShowTypeNone = 0,       /** 无跳过 */
    JMSkipShowTypeDefault,        /** 跳过 + 倒计时*/
    JMSkipShowTypeAnimation,      /** 跳过 + 动画 */
};


NS_ASSUME_NONNULL_BEGIN

@interface JMLaunchAdView : UIView

/**
 *  广告图
 */
@property(nonatomic, strong) UIImageView *launchAdImgView;

/**
 *  广告frame
 */
@property (nonatomic, assign) CGRect launchAdViewFrame;

/**
 *  清理缓冲
 */
+ (void)clearDiskCache;

/**
 *  初始化启动页广告
 *  @param adDuration  停留时间
 *  @param showskiptype    是否隐藏跳过
 *  @param setLaunchAd launchAdView
 *  @return self
 */
+ (instancetype)initImageWithAttribute:(NSInteger)adDuration
                          showSkipType:(JMSkipShowType)showSkipType
                           setLaunchAd:(JMSetLaunchAdBlock)setLaunchAd;

/**
 *  设置图片
 *  @param strURL       URL
 *  @param options      图片缓冲模式
 *  @param result       UIImage *image, NSURL *url
 *  @param adClickBlock 点击图片回调
 */
- (void)setWebImageWithURL:(NSString *)strURL
                   options:(JMWebImageOptions)options
                    result:(JMWebImageCompletionBlock)result
              adClickBlock:(JMLaunchAdClickBlock)adClickBlock;

/**
 *  设置动画跳过属性
 *  @param strokeColor     转动颜色
 *  @param lineWidth       宽度
 *  @param backgroundColor 背景色
 *  @param textColor       字体颜色
 */
- (void)setAnimationSkipWithAttribute:(UIColor *)strokeColor
                            lineWidth:(NSInteger)lineWidth
                      backgroundColor:(UIColor *)backgroundColor
                            textColor:(UIColor *)textColor;

@end

NS_ASSUME_NONNULL_END
