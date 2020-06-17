//
//  AppDelegate.m
//  jmlauchad
//
//  Created by JM on 2020/6/17.
//  Copyright © 2020 JM. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"
#import <JMLaunchAdFramework/JMLaunchAdFramework.h>

#define kScreen_Bounds  [UIScreen mainScreen].bounds
#define kScreen_Height  [UIScreen mainScreen].bounds.size.height
#define kScreen_Width   [UIScreen mainScreen].bounds.size.width


@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.window.rootViewController = [ViewController new];
    [self.window makeKeyAndVisible];
    //  1.设置启动页广告图片的url
    NSString *imgUrlString =@"http://seopic.699pic.com/photo/50162/6115.jpg_wh1200.jpg";
    //  GIF
    //  NSString *imgUrlString = @"http://img1.imgtn.bdimg.com/it/u=473895314,616407725&fm=206&gp=0.jpg";
       
    //  2.初始化启动页广告
    [JMLaunchAdView initImageWithAttribute:3.0 showSkipType:JMSkipShowTypeAnimation setLaunchAd:^(JMLaunchAdView *launchAd) {
           __block JMLaunchAdView *weakSelf = launchAd;
           
           //如果选择 SkipShowTypeAnimation 需要设置动画跳过按钮的属性
           [weakSelf setAnimationSkipWithAttribute:[UIColor yellowColor] lineWidth:3.0 backgroundColor:[UIColor grayColor] textColor:[UIColor blueColor]];
           [launchAd setWebImageWithURL:imgUrlString options:JMWebImageDefault result:^(UIImage *image, NSURL *url) {
               
               //  3.异步加载图片完成回调(设置图片尺寸)
               weakSelf.launchAdViewFrame = CGRectMake(0, 0, kScreen_Width, kScreen_Height);
           } adClickBlock:^{
               //  4.点击广告回调
               NSString *url = @"https://www.baidu.com";
               [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
           }];
       }];
       
    return YES;
}



@end
