//
//  AIResURLUtils.h
//  CommonProject
//
//  Created by Wu YouJian on 2018/12/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AIResURLUtils : NSObject
//key :@"filename",@"extension",@"url"
+ (NSDictionary *)getResURLFieldsFromUrl:(NSString *)url;
+ (NSString *)getFileNameFromUrl:(NSString *)url;
+ (NSString *)getFileExtensionFromUrl:(NSString *)url;
+ (NSString *)getMimeTypeFromUrl:(NSString *)url;
+ (NSString *)getMimeTypeFromExtension:(NSString *)extension;
@end

NS_ASSUME_NONNULL_END
