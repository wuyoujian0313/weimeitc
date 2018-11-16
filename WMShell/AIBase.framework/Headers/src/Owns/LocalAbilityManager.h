//
//  LocalAbilityManager.h
//  CommonProject
//
//  Created by wuyoujian on 16/5/12.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ImagePickerController.h"
#import "MailSMSController.h"
#import "AICommonDef.h"

typedef NS_ENUM(NSInteger, LocalAbilityType) {
    //发邮件
    LocalAbilityTypeMail = 0,
    //发短信
    LocalAbilityTypeSMS,
    //拨打电话
    LocalAbilityTypeDail,
    //选择图片，可编辑
    LocalAbilityTypePickerImage_AllowsEditing,
    //拍照，可编辑
    LocalAbilityTypePickerPhotograph_AllowsEditing,
    //选择图片，不可编辑
    LocalAbilityTypePickerImage_ForbidEditing,
    //拍照，不可编辑
    LocalAbilityTypePickerPhotograph_ForbidEditing,
    //扫二维码
    LocalAbilityTypePickerScanQRCode,
    //生成二维码图片
    LocalAbilityTypePickerGenerateQRCode,
    //录像
    LocalAbilityTypePickerVideotape,
};

typedef void(^touchIDFinish)(NSError * _Nonnull error);

@interface LocalAbilityManager : NSObject

// 建议不用单例，建议把LocalAbilityManager作为类一个strong成员变量
// 可以跟随使用的页面对象释放而释放
AISINGLETON_DEF(LocalAbilityManager, sharedLocalAbilityManager)

- (void)pickerCameraController:(UIViewController*_Nonnull)picker type:(LocalAbilityType)type finish:(ImagePickerFinishBlock _Nonnull )finishBlock;

// 对于短信，subject可以为空
- (void)pickerMailSMSController:(UIViewController*_Nonnull)picker type:(LocalAbilityType)type andRecipients:(NSArray*_Nonnull)receivers andSubject:(NSString*_Nullable)subject andContent:(NSString*_Nonnull)content finish:(SendFinishBlock _Nonnull )finishBlock;

// 生成二维码
+ (UIImage *_Nonnull)generateQRCode:(NSString *_Nonnull)code width:(CGFloat)width height:(CGFloat)height;

// 生成条形码
+ (UIImage *_Nonnull)generateBarCode:(NSString *_Nonnull)code width:(CGFloat)width height:(CGFloat)height;


+ (NSArray *_Nonnull)recognitionQRCodeFromImage:(UIImage*_Nonnull)image;

// 拨打电话可以返回当前页面
+ (void)telephoneToNumber:(NSString*_Nonnull)phoneNumber;

// 指纹验证
+ (void)touchIDPolicy:(touchIDFinish _Nonnull )finish;

@end
