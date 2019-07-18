//
//  VXIUserModel.h
//  VXIChat
//
//  Created by apple on 2019/6/12.
//  Copyright © 2019 VXI.ESBU. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 登录请求（ws/wss）：结果
 
 
 */
@interface VXIUser : NSObject

///登录是否成功  result == ok
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
 用户ID
 */
@property (nonatomic, copy) NSString *userId;


/**
 会话UUID
 */
@property (nonatomic, copy) NSString *uuid;


/**
 Server消息发出的时间戳
 */
@property(nonatomic, assign) long msgTime;
@end

NS_ASSUME_NONNULL_END
