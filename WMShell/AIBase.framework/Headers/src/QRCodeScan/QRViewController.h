//
//  QRViewController.h
//  CommonProject
//
//  Created by wuyoujian on 16/5/13.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "../Owns/BaseVC.h"

typedef NS_ENUM(NSInteger, QRCodeScanStatus) {
    QRCodeScanStatusSuccess,
    QRCodeScanStatusFail,
    QRCodeScanStatusCancel,
};

typedef void(^QRCodeFinishBlock)(NSString *result, QRCodeScanStatus status);

@interface QRViewController : BaseVC

- (void)setScanCallback:(QRCodeFinishBlock)callback;


@end
