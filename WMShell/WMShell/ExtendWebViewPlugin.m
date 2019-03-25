//
//  ExtendWebViewPlugin.m
//  WMShell
//
//  Created by Wu YouJian on 2019/3/25.
//  Copyright © 2019 AI. All rights reserved.
//

#import "ExtendWebViewPlugin.h"
#import "VideoPlayVC.h"


@implementation ExtendWebViewPlugin

- (void)JN_Play:(NSString *_Nullable)url {
    VideoPlayVC* vc = [[VideoPlayVC alloc] init];
    vc.urlString = url;
    [self.vc presentViewController:vc animated:YES completion:^{
        //
    }];
}

@end
