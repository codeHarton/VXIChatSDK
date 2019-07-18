//
//  VXIConversationModel.h
//  Texture
//
//  Created by apple on 2019/6/5.
//  Copyright © 2019 VXI.ESBU. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VXIRecommandQuestionItem.h"
NS_ASSUME_NONNULL_BEGIN


/// 开启会话结果回调  也是会话模型 保存在 VXIClientManager里面
@interface VXIConversation : NSObject
- (BOOL)success;

/**
 固定默认值（事件代码）  772
 */
@property(nonatomic, assign) NSInteger event;



/**
 登录结果：ok:成功，fail:失败
 */
@property (nonatomic, copy) NSString *result;


/**
 数据表ID
 */
@property (nonatomic, copy) NSString *Id;


/**
 Server IP
 */
@property (nonatomic, copy) NSString *ip;

/**
 Server消息发出的时间戳
 */
@property(nonatomic, assign) long msgTime;


/**
 固定值，server标识
 */
@property (nonatomic, copy) NSString *nsp;


/**
 分配的坐席ID
 */
@property (nonatomic, copy) NSString *toUserId;


/**
 会话ID
 */
@property (nonatomic, copy) NSString *sid;


/**
 请求失败（result=fail）时返回的等待人数
 */
@property(nonatomic, assign) NSInteger queuePos;


/**
 会话类型（1：自动应答会话，2：人工会话）
 */
@property(nonatomic, assign) NSInteger sessionType;


/**
 会话开启失败 , 返回的推荐问题列表
 recommendQuestion
 */
@property (nonatomic, copy) NSArray <VXIRecommandQuestionItem *>*recommendQuestion;
@end


NS_ASSUME_NONNULL_END
