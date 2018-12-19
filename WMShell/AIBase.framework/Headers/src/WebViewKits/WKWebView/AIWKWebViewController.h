//
//  AIWKWebViewController.h
//  WebViewTest-iOS
//
//  Created by wuyoujian on 2018/5/12.
//  Copyright © 2018年 AI. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "../../Owns/BaseVC.h"
#import <WebKit/WebKit.h>

@interface AIWKWebViewController : BaseVC
@property (nonatomic,weak, nullable) id <WKNavigationDelegate,WKUIDelegate> delegate;
@property (nonatomic,readonly, strong) WKWebView * _Nonnull wkWebView;

// 注册资源本地化插件
- (void)registerCacheInterceptor;
// 反注册资源本地化插件
- (void)unregisterCacheInterceptor;
// 刷新当前页面
- (void)reload;
// 后退
- (void)goBack;
// 前进
- (void)goForward;

@end
