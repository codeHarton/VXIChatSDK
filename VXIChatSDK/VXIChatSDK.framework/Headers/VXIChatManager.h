//
//  VXIChatManager.h
//  VXIChat
//
//  Created by harton on 2019/7/1.
//  Copyright © 2019 VXI.ESBU. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VXIChatDelegate.h"
#import "VXIChatConfig.h"
#import "VXIChatInterface.h"
NS_ASSUME_NONNULL_BEGIN


/**
 聊天控制管理类
 */
@interface VXIChatManager : NSObject

//设备Id，用来发送离线消息做判断用
+ (NSString *)vxi_deviceId;

/**
 单利
 
 @return sharedManager
 */
+ (instancetype)sharedManager;

///连接
+ (void)connect;

+ (void)connectWithSocketUrl:(NSString *)url;

+ (void)connectWithSocketUrl:(NSString *)url config:(VXIChatConfig *)config;

///重连
+ (void)reconnect;

///断开连接
+ (void)disconnect;

///当前是否连接
+ (BOOL)isConnected;

///是否已经登录
+ (BOOL)isLogin;

///是否正在回话
+ (BOOL)isOnConversationing;

+ (SocketIOStatus)status;

/**
 事件管理工具 用于发送各种事件 登录开启会话等...

 @return VXIEventDelegate
 */
+ (id<VXIEventInterface>)event;

/**
 聊天管理工具
向坐席发送图片文字 等...
 @return VXIChatInterface
 */
+ (id<VXIChatInterface>)chat;


/**
 开启会话后的 会话模型
 */
@property (nonatomic, strong,nullable,readonly) VXIConversation *conversation;

/**
 登录成功后的用户模型
 */
@property (nonatomic, strong,readonly) VXIUser *user;



/**
 添加代理
 */
+ (void)addDelegate:(id<VXIChatDelegate>)delegate;
    
/**
 移除代理
 */
+ (void)removeDelegate:(id<VXIChatDelegate>)delegate;

/**
 sdk版本号
 */
+ (NSString *)sdkVersion;


/**
 socket 发送事件
 
 @param chatEvent 事件名称
 @param params 参数
 */
+ (void)emit:(NSString *)chatEvent params:(id )params;


/**
 发送 ack消息  用于发送图片和文字消息
 
 @param chatEvent 事件名称
 @param params 参数
 */
+ (void)emitWithAck:(NSString *)chatEvent params:(NSDictionary *)params;
    
@end

NS_ASSUME_NONNULL_END
