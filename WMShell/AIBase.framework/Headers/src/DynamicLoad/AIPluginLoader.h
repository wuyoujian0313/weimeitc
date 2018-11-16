//
//  AIPluginLoader.h
//  CommonProject
//
//  Created by wuyoujian on 2017/6/19.
//
//

#import <Foundation/Foundation.h>
#import "../Owns/AINavigationController.h"
#import "../Owns/AICommonDef.h"
#import "AIPluginProtocol.h"


typedef NS_ENUM(NSInteger,PluginLoadStatus) {
    
    PluginLoadStatusNone = 0,
    PluginLoadStatusUnDownload = 1,     // 没有下载
    PluginLoadStatusDownloading = 2,    // 下载中
    PluginLoadStatusDownloaded = 3,     // 下载完毕
    PluginLoadStatusException = 4,      // 加载异常
    
};

@interface AIPluginLoader : NSObject

AISINGLETON_DEF(AIPluginLoader,SharedObj);

// 获取插件的状态
- (PluginLoadStatus)pluginloadStatus:(NSString*_Nonnull)pluginURL;

// 下载插件
- (void)downloadPlugin:(NSString*_Nonnull)pluginURL;

// 加载插件
- (void)loadPluginName:(NSString*_Nonnull)frameworkName
                   nav:(AINavigationController*_Nonnull)navVC
      enterVCClassName:(NSString*_Nonnull)className;

// 加载插件
- (UIViewController<AIPluginProtocol> *_Nullable)loadPluginName:(NSString*_Nonnull)frameworkName enterVCClassName:(NSString*_Nonnull)className;

@end
