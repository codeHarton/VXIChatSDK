//
//  VXIMessageModel.h
//  Texture
//
//  Created by apple on 2019/6/5.
//  Copyright © 2019 VXI.ESBU. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VXIRecommandQuestionItem.h"

///客户端接收坐席发送的消息
NS_ASSUME_NONNULL_BEGIN



/**
 消息类型
 */
typedef NS_ENUM(NSInteger,VXIMessageType) {
    VXIMessageTypeText = 0, ///<文字
    VXIMessageTypeImage ,  ///<图片消息
};



typedef NS_ENUM(NSInteger, VXIMessageSendState) {
//    VXIMessageSendStateDefault = 0,
    VXIMessageSendStateOning = 0, ///<消息正在发送
    VXIMessageSendStateSuccess,   ///<消息发送成功
    VXIMessageSendStateHasRead,   ///<消息已读
    VXIMessageSendStateFail,      ///<消息发送失败  --- 一般是超时、断网等...
};


@class VXIMEssage_DateModel;




@class VXIMessage_SelectItem;
@interface VXIMessage : NSObject

+ (instancetype)message;

/**
 当条消息状态  发送成功/ 已读 等等...
 */
@property (nonatomic, assign) VXIMessageSendState messageSendState;
///基于 messageSendState 的文字描述
@property (nonatomic, copy) NSString *readStatus;


/**
 固定值   消息类型 图片或文字  text image
 */
@property (nonatomic, copy) NSString *msgType;

/**
 固定默认值（事件代码）
 */
@property(nonatomic, assign) NSInteger event;


@property (nonatomic, copy) NSString *_id;

/**
 Server IP地址
 */
@property (nonatomic, copy) NSString *ip;

/**
 是否是组长
 */
@property (nonatomic, copy) NSString *leader;

/**
 消息 ID随机字符串，保证唯一性
 */
@property (nonatomic, copy) NSString *msgId;

/**
 消息发送时间戳
 */
@property (nonatomic, copy) NSString *msgTime;

/**
 （人工会话不会返回）自动应答返回的推荐问题列表，在提交客户问题时，请把消息封装成{“id”:”2624”,”contents”:”test”}形式，其中，id是推荐问题的id，contents是推荐问题的title。如果是客户自己输入的问题或者是人工应答会话，id就传””
 */
@property(nonatomic, strong) NSArray <VXIRecommandQuestionItem *>*selectItems;

/**
 A、文本消息:内容Base64编码，需要decode解码；
 B、表情消息：表情代码（详见附录2-emoji对照表）Base64编码，需要decode解码；
 C、截图消息：格式：[IMG上传截图后的文件名] 的Base64编码格式，需要decode解码；
 D、图片文件消息：上传图片文件信息的Base64编码，需要decode解码；
 E、一般文件消息：上传文件信息的Base64编码，需要decode解码；
 
 注意：上述消息内容信息格式规范见附录1-消息内容解析
 */
@property (nonatomic, copy) NSString *content;

/**
 Server标识
 */
@property (nonatomic, copy) NSString *nsp;

/**
 固定值
 */
@property(nonatomic, assign) NSInteger senderType;

/**
 会话ID （开启会话返回的会话ID）
 */
@property (nonatomic, copy) NSString *sid;

/**
 固定值
 */
@property(nonatomic, assign) NSInteger stype;

/**
 固定值
 */
@property(nonatomic, assign) NSInteger subId;

/**
 系统时间戳
 */
@property (nonatomic, strong) VXIMEssage_DateModel *sysDate;

/**
 接收者ID（当前客户ID）
 */
@property (nonatomic, copy) NSString *toUserId;

/**
 坐席ID
 */
@property (nonatomic, copy) NSString *userId;

/**
 坐席名称
 */
@property (nonatomic, copy) NSString *userName;

/**
 固定值
 */
@property(nonatomic, assign) NSInteger userType;


/**
 登录请求返回的UUID
 */
@property (nonatomic, copy) NSString *uuid;



/**
 是否是图片消息

 @return  is image
 */
- (BOOL)isImageMessage;


///是否有推荐问题
- (BOOL)hasSelecteItme;




#pragma mark - 计算属性


/**
 消息内容 经过base64解码的content
 */
@property (nonatomic, copy) NSString *msg_content;



/**
 消息类型 图片或文字
 */
@property (nonatomic, assign) VXIMessageType messageType;


@end

@interface VXIMEssage_DateModel : NSObject 

@property (nonatomic, assign) NSInteger date;
@property (nonatomic, assign) NSInteger day;
@property (nonatomic, assign) NSInteger hours;
@property (nonatomic, assign) NSInteger minutes;
@property (nonatomic, assign) NSInteger month;
@property (nonatomic, assign) NSInteger seconds;
@property (nonatomic, assign) long time;
@property (nonatomic, assign) NSInteger year;
@property (nonatomic, copy) NSString *timezoneOffset;



- (NSString *)showTime;
@end




NS_ASSUME_NONNULL_END
