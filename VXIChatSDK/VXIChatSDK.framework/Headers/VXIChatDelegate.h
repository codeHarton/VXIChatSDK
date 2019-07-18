//
//  VXIChatDelegate.h
//  VXIChat
//
//  Created by harton on 2019/7/1.
//  Copyright © 2019 VXI.ESBU. All rights reserved.
//

#ifndef VXIChatDelegate_h
#define VXIChatDelegate_h
#import "VXIMessage.h"
#import "VXIConversation.h"
#import "VXIChatTransfer.h"
#import "VXIUser.h"
#import "VXIChatSurvey_item.h"
@import SocketIO;


typedef NS_ENUM(NSInteger,VXIClientInputState) {
    VXIClientInputStateDefault = 0,///<默认
    
    VXIClientInputStateInputing,   ///<正在输入
    
    VXIClientInputStateStop,       ///<停止输入
};


@protocol VXISocketIOStatusDelegate;
@protocol VXIClientDelegate;
@protocol VXIChatDelegate <VXISocketIOStatusDelegate,VXIClientDelegate>



@end


/**
 与坐席交互的回调
 */
@protocol VXIClientDelegate <NSObject>

@optional
/**
 登录回调,

 @param user 用户信息
 */
- (void)clientLoginWithUserInfo:(VXIUser *)user;



/**
 收到坐席新消息的回调

 @param message 消息模型
 */
- (void)clientDidReceiveNewMessage:(VXIMessage *)message;


/**
 开启会话的回调

 @param conversation 会话模型
 */
- (void)clientDidOpenConversation:(VXIConversation *)conversation;

/**
 关闭会话的回调
  */
- (void)clientDidCloseConversation;


/**
 有空闲坐席可用
 */
- (void)clientServiceAvailable;


/**
 坐席输入状态改变

 @param inputState 输入状态
 */
- (void)clientInputStateChanged:(VXIClientInputState)inputState;


/**
 收到坐席发送的满意度调查
 */
- (void)clientDidReceiveSatisfaceSveryWithItems:(NSArray <VXIChatSurvey_item *>*)items;


/**
 客户端收到坐席 已读消息    发送的消息被坐席已读
 */
- (void)clientDidReceiveServeHasReadInfo;



/**
  收到坐席转移到 通知

 @param model 转移的模型
 */
- (void)clientDidReceiveTransfer:(VXIChatTransfer *)model;



/**
 某条消息发送 成功与否

 @param success 消息是否发送成功
 @param msgId 消息id
 */
- (void)clientMessageSendState:(BOOL)success messageID:(NSString *)msgId;

@end



/**
 socket.io状态发生改变的 delegate
 */
@protocol VXISocketIOStatusDelegate <NSObject>
@optional

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



@end




#endif /* VXIChatDelegate_h */
