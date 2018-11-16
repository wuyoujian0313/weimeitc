//
//  WebViewPluginCfg.h
//  CommonProject
//
//  Created by wuyoujian on 2017/6/13.
//
//

#import "AbstractCfg.h"
#import "../../Owns/AICommonDef.h"

@interface WebViewPluginCfg : AbstractCfg

@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_FIND_PATH;
@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_ATTR_NAME;
@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_ATTR_CLASS;

AISINGLETON_CLASS_DEF(WebViewPluginCfg,SharedObj);

- (NSDictionary *_Nullable)get:(NSString *_Nonnull)name;
- (NSString *_Nullable)attr:(NSString *_Nonnull)name attrName:(NSString*_Nonnull)attr;

@end
