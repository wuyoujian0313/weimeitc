//
//  AIBase.h
//  AIBase
//
//  Created by wuyoujian on 16/7/18.
//  Copyright © 2016年 Asiainfo. All rights reserved.
//

#import <UIKit/UIKit.h>

// 用引号应用头文件，目的是为了源码工程配套使用，不要定义两套.h文件；

#ifndef AIBase_h
#define AIBase_h

// AFNetworking
#import "src/AFNetworking/AFNetworking.h"

// NJWebViewProgress
#import "src/NJKWebViewProgress/NJKWebViewProgress.h"
#import "src/NJKWebViewProgress/NJKWebViewProgressView.h"

// SDWebImage
#import "src/SDWebImage/MKAnnotationView+WebCache.h"
#import "src/SDWebImage/NSData+ImageContentType.h"
#import "src/SDWebImage/SDImageCache.h"
#import "src/SDWebImage/SDWebImageCompat.h"
#import "src/SDWebImage/SDWebImageDecoder.h"
#import "src/SDWebImage/SDWebImageDownloader.h"
#import "src/SDWebImage/SDWebImageDownloaderOperation.h"
#import "src/SDWebImage/SDWebImageManager.h"
#import "src/SDWebImage/SDWebImageOperation.h"
#import "src/SDWebImage/SDWebImagePrefetcher.h"
#import "src/SDWebImage/UIButton+WebCache.h"
#import "src/SDWebImage/UIImage+GIF.h"
#import "src/SDWebImage/UIImage+MultiFormat.h"
#import "src/SDWebImage/UIImage+WebP.h"
#import "src/SDWebImage/UIImageView+HighlightedWebCache.h"
#import "src/SDWebImage/UIImageView+WebCache.h"
#import "src/SDWebImage/UIView+WebCacheOperation.h"

// minzip
#import "src/minzip/ZipArchive.h"
#import "src/minzip/ZipArchiveEx.h"

// 自定义
#import "src/Category/Category.h"
#import "src/WebViewKits/WebViewKit.h"
#import "src/Owns/Owns.h"
#import "src/DynamicLoad/AIDynamicLoadKit.h"


// 网络通信引擎
#import "src/NetworkTask/NetworkTask.h"
#import "src/NetworkTask/NetResultBase.h"

// 证件相机
#import "src/CertificateCamera/AICameraICONData.h"
#import "src/CertificateCamera/AICaptureView.h"
#import "src/CertificateCamera/AICertificateCameraViewController.h"

// 扫码
#import "src/QRCodeScan/LineImageByteData.h"
#import "src/QRCodeScan/PickBGImageByteData.h"
#import "src/QRCodeScan/QRViewController.h"


#endif



