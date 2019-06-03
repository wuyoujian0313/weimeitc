//
//  VideoPlayVC.m
//  WMShell
//
//  Created by Wu YouJian on 2019/3/25.
//  Copyright © 2019 AI. All rights reserved.
//

#import "VideoPlayVC.h"
#import <AliyunVodPlayerSDK/AliyunVodPlayer.h>

@interface VideoPlayVC ()<AliyunVodPlayerDelegate>
@property(nonatomic,strong)AliyunVodPlayer *vodPlayer;
@end

@interface VideoPlayVC ()

@end

@implementation VideoPlayVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self initPlayer];
    [self playerVideo];
    
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn setFrame:CGRectMake(20, 30, 40, 30)];
    [btn setTitle:@"关闭" forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(closePage) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
}

- (void)closePage {
    if ([_vodPlayer isPlaying]) {
        [_vodPlayer stop];
    }
    [self dismissViewControllerAnimated:YES completion:^{
        //
    }];
}


- (void)initPlayer {
    //创建播放器对象，可以创建多个示例
    AliyunVodPlayer *aliPlayer = [[AliyunVodPlayer alloc] init];
    //设置播放器代理
    aliPlayer.delegate = self;
    //获取播放器视图
    UIView *playerView = aliPlayer.playerView;
    playerView.frame = self.view.bounds;
    //添加播放器视图到需要展示的界面上
    [self.view addSubview:playerView];
    self.vodPlayer = aliPlayer;
}

-(void)playerVideo {
    //播放方式二：使用URL播放(直播用户推荐使用)
    NSURL *strUrl = [NSURL URLWithString:_urlString];//网络视频，填写网络url地址
    NSURL *url = strUrl;
    [self.vodPlayer prepareWithURL:url];
    
    //开始播放
    [self.vodPlayer start];
}


#pragma mark - AliyunVodPlayerDelegate
/**
 * 功能：播放事件协议方法,主要内容 AliyunVodPlayerEventPrepareDone状态下，此时获取到播放视频数据（时长、当前播放数据、视频宽高等）
 * 参数：event 视频事件
 */
- (void)vodPlayer:(AliyunVodPlayer *)vodPlayer onEventCallback:(AliyunVodPlayerEvent)event {
    
}

/**
 * 功能：播放器播放时发生错误时，回调信息
 * 参数：errorModel 播放器报错时提供的错误信息对象
 */
- (void)vodPlayer:(AliyunVodPlayer *)vodPlayer playBackErrorModel:(AliyunPlayerVideoErrorModel *)errorModel {
    
}




@end
