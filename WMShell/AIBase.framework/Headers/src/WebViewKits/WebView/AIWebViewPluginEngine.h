//
//  AIWebViewPluginEngine.h
//  AIBase
//
//  Created by wuyoujian on 2017/6/13.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "../../Owns/AICommonDef.h"
#import "../../Owns/BaseVC.h"

@interface AIWebViewPluginEngine : NSObject

AISINGLETON_DEF(AIWebViewPluginEngine,SharedObj);

// 根据传入的配置文件，注册插件,配置文件从mainBundle里加载
- (void)registerPluginsInVC:(BaseVC*_Nonnull)vc webView:(UIWebView *_Nonnull)webView configFile:(NSString*_Nonnull)configFile;

// 根据传入的配置文件，注册插件,配置文件数据
- (void)registerPluginsInVC:(BaseVC*_Nonnull)vc webView:(UIWebView *_Nonnull)webView configData:(NSData*_Nonnull)configData;


- (void)unregisterPlugins;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script;

// 参数js格式化
+ (NSString *_Nullable)paramEncodeForJs:(NSString *_Nonnull)string;

/*
 回调插件的匿名回调接口
 @param:pluginAPIName,插件方法名称：构成结构：className_functionName,例如：AIWebViewBasePlugin_JN_Test
 */

- (void)excutePluginCallback:(NSString *_Nonnull)pluginAPIName param:(NSString *_Nonnull)param;

@end
