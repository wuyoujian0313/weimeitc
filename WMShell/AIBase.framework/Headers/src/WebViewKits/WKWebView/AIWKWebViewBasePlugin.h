//
//  AIWKWebViewBasePlugin.h
//  CommonProject
//
//  Created by wuyoujian on 2018/5/12.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "../../Owns/BaseVC.h"

@interface AIWKWebViewBasePlugin : NSObject
@property(nonatomic,weak) BaseVC                        * _Nullable vc;
@property(nonatomic,strong,nonnull) WKWebView           *wkWebView;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

// js匿名回调, actionName 即配置modular-plugin-ios.xml中，action的name
- (void)callback:(NSString *_Nonnull)actionName param:(NSString *_Nonnull)param;

// 扩展原生能力接口
- (void)JN_Test:(NSDictionary *_Nullable)params;

// 传递JSONObj
- (void)JN_JSONObj:(NSDictionary*_Nonnull)obj;

// 退出程序
- (void)JN_Quit:(NSString *_Nullable)params;

// 分享程序
- (void)JN_Sharing:(NSString *_Nullable)params;

// 打开文件
- (void)JN_OpenDocument:(NSString *_Nullable)params;

// 自动更新
- (void)JN_CheckVersion:(NSString *_Nonnull)versionConfigUrl;

// 获取版本号
- (void)JN_VersionNumber;

// 启动loading
- (void)JN_ShowLoading:(NSString*_Nonnull)text;

// 退出loading
- (void)JN_DismissLoading;

// 自消失提示语
- (void)JN_ShowMessage:(NSString*_Nonnull)message;

// 保存数据
- (void)JN_SetValueWithKey:(NSArray *_Nonnull)params;

// 获取已存储的数据
- (void)JN_GetValueWithKey:(NSString*_Nonnull)key;

// 指纹验证
- (void)JN_Fingerprint;

// 调动系统短信应用发送短信
- (void)JN_SMS:(NSArray *_Nonnull)array;

// 调动系统打电话应用，拨打电话
- (void)JN_Telephone:(NSString*_Nonnull)phoneNumber;

// 调动系统里的邮箱应用
- (void)JN_Email:(NSArray *_Nonnull)array;

// 打开系统的浏览器应用
- (void)JN_Brower:(NSString*_Nonnull)urlString;

// 打开系统的相册选择图片
- (void)JN_SelectPhoto;

// 打开系统相机拍照
- (void)JN_Photograph;

// 打开证件相机拍照
- (void)JN_TakeCertificate;

// 扫码
- (void)JN_QRcode;

//
- (void)JN_ClearAllResCache;

@end
