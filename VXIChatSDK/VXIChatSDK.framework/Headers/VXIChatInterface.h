//
//  VXIChatInterface.h
//  SocketTest
//
//  Created by harton on 2019/7/4.
//  Copyright © 2019 VXI. All rights reserved.
//

#ifndef VXIChatInterface_h
#define VXIChatInterface_h


#import "UIKit/UIKit.h"
@class VXIMessage;

NS_ASSUME_NONNULL_BEGIN
@protocol VXIEventInterface <NSObject>

@required

/**
 登录事件
 
 @param userName 用户昵称
 */
- (void)event_loginWithUserName:(NSString *)userName;

/**
 开启会话
 */
- (void)event_beginConversation;


/**
 关闭会话
 */
- (void)event_closeConversation;


/**
 输入状态的发送
 
 @param state 1 正在输入  2 停止输入
 */
- (void)event_sendInputState:(NSInteger)state;


/**
 告诉坐席 已经收到消息
 
 @param msgId 消息id
 */
- (void)event_sendRecemessageACKWithMessageId:(NSString *)msgId;


/**
 客户端满意度调查消息的提交

 @param key 上述满意度列表获取接口中返回值中的key   VXIChatSurvey_item的key至不能为空
 @param suggestion 用户输入内容
 @param complete 满意度提交 回调结果
 */
- (void)event_commitSurveyWithKey:(NSString *)key suggestion:(nullable NSString *)suggestion complete:(void(^)(BOOL success,NSString *msg))complete;

@end


@protocol VXIChatInterface <NSObject>
@required

/**
 发送文字消息
 
 @param text 文字内容
 @param msgId 消息id
 */
- (void)chat_sendText:(NSString *)text msgId:(NSString *)msgId;


/**
 发送图片消息
 
 @param content 图片内容
 @param msgId 消息id
 */
- (void)chat_sendImage:(NSString *)content msgId:(NSString *)msgId;



/**
 发送消息
 
 @param params 消息内容
 */
- (void)chat_sendMessgeWithParams:(id)params;



/**
 初始化发送模型
 */
- (void)chat_initSendMessageModel;

///发送图片
- (void)chat_uploadImage:(UIImage *)image
      progressBlock:(void(^)(CGFloat progress))progressBlock
            success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success
            failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError * _Nullable error))failure;

///下载图片
- (void)chat_downloadImageWithUrl:(NSString *)url
                     success:(nullable void (^)(NSURLRequest *request, NSHTTPURLResponse  * _Nullable response, UIImage *responseObject))success
                     failure:(nullable void (^)(NSURLRequest * _Nullable request, NSHTTPURLResponse * _Nullable response, NSError * _Nullable error))failure;



@end
NS_ASSUME_NONNULL_END
#endif /* VXIChatInterface_h */

