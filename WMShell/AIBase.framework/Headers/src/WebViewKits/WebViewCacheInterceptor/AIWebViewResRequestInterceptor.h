//
//  AIWebViewResRequestInterceptor.h
//  CommonProject
//
//  Created by Wu YouJian on 2018/12/10.
//

#import <Foundation/Foundation.h>

// 本质上他不是构造器，因为NSURLProtocol使用系统框架去构造的
@interface AIInterceptorBuilder: NSObject
@property(nonatomic,strong)NSArray      *cacheExtensions;
@property(nonatomic,assign)BOOL         forceCache;
@property(nonatomic,assign)NSInteger    connectTimeout;
@property(nonatomic,strong)NSString     *cachePath;
@property(nonatomic,strong)NSString     *aesEncryptKey;
@property(nonatomic,strong)NSString     *aesEncryptIV;
@property(nonatomic,assign)BOOL         isDebug;
// 过滤一些不需要拦截的URL，可以支持URL前缀形式，可以实现过滤一个域名的或者一个ip的
// 也可以精准匹配某一个url
@property(nonatomic,strong)NSArray      *ignoreUrls;
@end

@interface AIWebViewResRequestInterceptor : NSURLProtocol
+ (void)registerInterceptor:(AIInterceptorBuilder *)builder;
+ (void)unregisterInterceptor;
+ (BOOL)clearCache;
@end




