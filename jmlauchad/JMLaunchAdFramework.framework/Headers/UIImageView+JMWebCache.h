//
//  UIImageView+JMWebCache.h
//  JMLaunchAdFramework
//
//  Created by JM on 2020/6/17.
//  Copyright © 2020 JM. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, JMWebImageOptions) {
    JMWebImageDefault = 1 << 0,  //有缓存,读取缓存,不重新加载,没缓存先加载,并缓存
    JMWebImageOnlyLoad = 1 << 1, //只加载，不缓存
    JMWebImageRefreshCached = 1 << 2 //先读缓存,再加载刷新图片和缓存
};

/*
 * image 图片
 * url 地址
 */
typedef void(^JMWebImageCompletionBlock)(UIImage *image, NSURL *url);

/*
*  image 图片
*  url 地址
*  data 数据
*/
typedef void(^JMDispatch_asyncBlock)(UIImage *image, NSURL *url, NSData *data);


@interface JMWebImageDownloader : NSObject

/**
 *  缓冲路径
 *  @return 路径
 */
+ (NSString *)cacheImagePath;

/**
 *  检查目录
 *  @param path 路径
 */
+(void)checkDirectory:(NSString *)path;

@end


@interface UIImage(GIF)

/**
 *  NSData -> UIImage
 *  @param data Data
 *  @return UIImage
 */
+ (UIImage *)jm_gifWithData:(NSData *)data;

@end

@interface UIImageView (JMWebCache)

/**
 *  获取当前图像的URL
 */
- (NSURL *)jm_imageURL;

/**
 *  异步加载网络图片+缓存
 *  @param url    图片url
 *  @param placeholderImage    默认图片
 *  @param completedBlock 加载完成回调
 */
- (void)jm_setImageWithURL:(NSURL *)url
          placeholderImage:(UIImage *)placeholderImage
                 completed:(JMWebImageCompletionBlock)completedBlock;

/**
 *  异步加载网络图片+缓存
 *  @param url     图片url
 *  @param placeholderImage    默认图片
 *  @param options        缓存机制
 *  @param completedBlock 加载完成回调
 */
-(void)jm_setImageWithURL:(NSURL *)url
         placeholderImage:(UIImage *)placeholderImage
                  options:(JMWebImageOptions)options
                completed:(JMWebImageCompletionBlock)completedBlock;

@end

NS_ASSUME_NONNULL_END
