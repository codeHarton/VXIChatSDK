//
//  VXISocketManager.h
//  VXIChat
//
//  Created by harton on 2019/7/2.
//  Copyright © 2019 VXI.ESBU. All rights reserved.
//

#import <Foundation/Foundation.h>
@import SocketIO;
#import "VXIChatConfig.h"
NS_ASSUME_NONNULL_BEGIN


/**
 socket.io状态发生改变的 delegate
 */
@protocol VXISocketManagerDelegate <NSObject>


/**
 连接状态发生改变
 
 @param status 连接状态
 */
- (void)socketIOStatusChanged:(SocketIOStatus)status;

/**
 socket已连接
 */
- (void)socketDidConnected;

/**
 socket断开连接. -> 从 connected到disconnect
 */
- (void)socketDisConnect;

/**
 socket 发生错误
 */
- (void)socketErrorOccuredWithData:(NSData *)data;

/**
 收到信的socket消息

 @param data data
 */
- (void)socketOnCallbackWithData:(id)data;

@end
/**
 socket管理类
 */
@interface VXISocketManager : NSObject


@property (nonatomic, strong) SocketIOClient *socket;

@property (nonatomic, strong) SocketManager *manager;


@property (nonatomic, weak) id <VXISocketManagerDelegate>delegate;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;
/**
 初始化 采用默认配置
 @param url socket service
 */
- (instancetype)initWithSocketUrl:(NSString *)url;

/**
 初始化
 @param url socket service
 @param config socket 配置参数
 */
- (instancetype)initWithSocketUrl:(NSString *)url config:(VXIChatConfig *)config;

/**
 初始化 使用维音的 socket service和默认配置
 */
- (instancetype)initWithDefault;



///当前是否连接
- (BOOL)isConnected;

///连接
- (void)connect;

///断开连接
- (void)disconnect;

/**
 sdk版本号
 */
- (NSString *)sdkVersion;


@end

NS_ASSUME_NONNULL_END
