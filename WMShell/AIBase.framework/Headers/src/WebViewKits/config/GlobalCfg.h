//
//  GlobalCfg.h
//  CommonProject
//
//  Created by wuyoujian on 2017/6/13.
//
//

#import "AbstractCfg.h"
#import "../../Owns/AICommonDef.h"

@interface GlobalCfg : AbstractCfg

@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_FIELD_ONLINEADDR;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_ENCRYPTKEY;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_ZHSTRING;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_IDMD5Key;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_PUBLICKEY;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_VERSION;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_VERSIONURL;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_USERAGENT;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_APPNAME;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_CACHE;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_DEBUG;


AISINGLETON_CLASS_DEF(GlobalCfg,SharedObj);
- (NSString *_Nullable)attr:(NSString*_Nonnull)attr;
@end
