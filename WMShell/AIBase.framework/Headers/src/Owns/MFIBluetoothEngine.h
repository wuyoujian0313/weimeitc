//
//  MFIBluetoothEngine.h
//  CommonProject
//
//  Created by wuyoujian on 16/5/24.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>
#import "AICommonDef.h"


@interface MFIBluetoothEngine : NSObject

// Notification object 是BluetoothEngine
extern NSString * _Nonnull EADSessionDataReceivedNotification;

AISINGLETON_DEF(MFIBluetoothEngine,sharedBluetoothEngine)

@property (nonatomic, readonly) EAAccessory                     * _Nonnull accessory;
@property (nonatomic, readonly) NSString                        * _Nonnull protocolString;
@property (nonatomic, readonly) NSArray<EAAccessory*>           * _Nonnull accessoryList;

- (void)registerBluetoothEngine;
- (void)unregisterBluetoothEngine;

- (BOOL)isConnectReady;

- (BOOL)openBlutoothSessionWithAccessory:(EAAccessory*_Nonnull)accessory forProtocol:(NSString *_Nonnull)protocolString;
- (void)closeBlutoothSessionWithAccessory;

- (void)writeData:(NSData *_Nonnull)data;
- (void)writeHexString:(NSString *_Nonnull)hexString;

- (NSUInteger)readBytesAvailable;
- (NSData *_Nullable)readData:(NSUInteger)bytesToRead;

@end
