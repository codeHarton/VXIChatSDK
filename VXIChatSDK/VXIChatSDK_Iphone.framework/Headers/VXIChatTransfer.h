//
//  VXIChatTransferModel.h
//  VXIChat
//
//  Created by harton on 2019/6/21.
//  Copyright © 2019 VXI.ESBU. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 客户端接收坐席转移会话后的消息（ws/wss）

 */
@interface VXIChatTransfer : NSObject


/**
 转移者坐席ID
 */
@property (nonatomic, copy) NSString *trans;



/**
 转移者坐席ID
 */
@property (nonatomic, copy) NSString *toUserId;



/**
 转移结果
 */
@property (nonatomic, copy) NSString *result;



/**
 国际化标识
 */
@property (nonatomic, copy) NSString *guestLocale;



/**
 登录请求返回的UUID
 */
@property (nonatomic, copy) NSString *uuid;


/**
 会话ID（开启会话返回的会话ID）
 */
@property (nonatomic, copy) NSString *sid;



/**
 固定默认值（事件代码）
 */
@property (nonatomic, assign) NSInteger event;


/**
 客户ID（登录请求返回的userId）
 */
@property (nonatomic, copy) NSString *userId;


- (BOOL)success;
@end

NS_ASSUME_NONNULL_END
