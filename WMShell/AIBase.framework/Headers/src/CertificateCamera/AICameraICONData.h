//
//  AICameraICONData.h
//  CommonProject
//
//  Created by Wu YouJian on 2018/10/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AICameraICONData : NSObject

// 关闭按钮图片
+ (NSData *)closeByteData;
//闪光灯关闭状态按钮图片
+ (NSData *)flashoffByteData;
//闪光灯打开状态按钮图片
+ (NSData *)flashonByteData;
// 拍照按钮图片
+ (NSData *)takeByteData;

@end

NS_ASSUME_NONNULL_END
