//
//  AIDynamicLoadLib.h
//  CommonProject
//
//  Created by wuyoujian on 2017/6/16.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "../Owns/AICommonDef.h"
#import "AIPluginProtocol.h"

/*
 * 动态加载.framework文件，必须是动态库
 */
@interface AIDynamicLoadLib : NSObject
AISINGLETON_CLASS_DEF(AIDynamicLoadLib,SharedObj);

// 加载framework ，返回入口VC
- (UIViewController<AIPluginProtocol> *_Nonnull)loadFrameworkPath:(NSString*_Nonnull)frameworkPath
                                                    frameworkName:(NSString*_Nonnull)frameworkName
                                                 enterVCClassName:(NSString*_Nonnull)className;

// 卸载framework
- (BOOL)unloadLib;

@end
