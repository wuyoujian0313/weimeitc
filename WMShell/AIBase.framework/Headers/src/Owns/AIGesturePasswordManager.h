//
//  AIGesturePasswordManager.h
//  CommonProject
//
//  Created by wuyoujian on 16/9/25.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AICommonDef.h"

typedef NS_ENUM(NSInteger, GesturePasswordCheckType) {
    GesturePasswordCheckWrong,          // 验证失败
    GesturePasswordCheckRight,          // 验证成功
    GesturePasswordCheckReInput,        // 再次输入
    GesturePasswordCheckSetPassword,    // 设置密码成功
    GesturePasswordCheckInvalid,        // 无效密码,小于4位的密码
};

typedef void(^AIGesturePasswordBlock)(GesturePasswordCheckType checkType);

@class AIGesturePasswordView;
@interface AIGesturePasswordManager : NSObject
@property (nonatomic,readonly,strong) AIGesturePasswordView * _Nonnull passwordView;

// 单例方法
AISINGLETON_DEF(AIGesturePasswordManager, sharedGesturePassword)

// 设置一个独特的ID
+ (void)setKeychainIndentifier:(NSString*_Nonnull)indentifier;

// 注意accessGroup是需要跟证书配套的，含有TeamId，格式： TeamId.证书ID,例如：XXXX.com.ai.wuyj
// 同时请打开Keychain sharing能力
+ (void)setKeychainAccessGroup:(NSString*_Nonnull)accessGroup;

- (void)setBackgroundColor:(UIColor*_Nonnull)color;
- (void)setBackgroundView:(UIView*_Nonnull)view;

- (void)addPasswordViewToParentView:(UIView*_Nonnull)parentView block:(AIGesturePasswordBlock _Nonnull )block;
- (void)removeGesturePasswordView;
- (void)clearPassword;

// 支持非单例模式，请声明为strong的类成员
- (instancetype _Nonnull )initGesturePassworkInParentView:(UIView*_Nonnull)parentView block:(AIGesturePasswordBlock _Nonnull )block;
@end
