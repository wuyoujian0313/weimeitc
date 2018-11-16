//
//  AICertificateCameraViewController.h
//  CommonProject
//
//  Created by Wu YouJian on 2018/10/24.
//

#import "../Owns/BaseVC.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^AITakeFinishCallback)(UIImage *croppedImage);

@interface AICertificateCameraViewController : BaseVC
- (void)setTakeCallback:(AITakeFinishCallback)callback;
@end

NS_ASSUME_NONNULL_END
