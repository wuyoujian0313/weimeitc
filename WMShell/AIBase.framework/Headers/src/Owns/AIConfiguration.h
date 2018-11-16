//
//  AIConfiguration.h
//  CRMMobile_TJ
//
//  Created by wuyoujian on 16/8/2.
//  Copyright © 2016年 Asiainfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AICommonDef.h"

/*
 专用于读取在mainBoundle里的properties的配置
 */
@interface AIConfiguration : NSObject
AISINGLETON_DEF(AIConfiguration, sharedConfiguration)

// @param name 配置文件名
- (NSDictionary *_Nullable)configurationName:(NSString*_Nonnull)name;

// @param configData 配置文件数据
- (NSDictionary *_Nullable)configurationData:(NSData*_Nonnull)configData;

// @param configString 配置文件数据
- (NSDictionary *_Nullable)configurationString:(NSString*_Nonnull)configString;

@end
