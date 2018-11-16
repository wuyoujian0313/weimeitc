//
//  ApkPluginCfg.h
//  AIBase
//
//  Created by wuyoujian on 2017/6/22.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import "AbstractCfg.h"
#import "../../Owns/AICommonDef.h"


@interface ApkPluginCfg : AbstractCfg

@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_FIND_PATH;
@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_ATTR_NAME;
@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_ATTR_CLASS;
@property(nonatomic,copy,readonly) NSString* _Nullable  CONFIG_ATTR_PACKAGENAME;
@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_ATTR_APKURL;

AISINGLETON_CLASS_DEF(ApkPluginCfg,SharedObj);

- (NSDictionary *_Nullable)get:(NSString *_Nonnull)name;
- (NSString *_Nullable)attr:(NSString *_Nonnull)name attrName:(NSString*_Nonnull)attr;

@end
