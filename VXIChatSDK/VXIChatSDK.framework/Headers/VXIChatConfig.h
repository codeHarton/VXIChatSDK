//
//  VXIChatConfig.h
//  VXIChat
//
//  Created by harton on 2019/7/1.
//  Copyright © 2019 VXI.ESBU. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface VXIChatConfig : NSObject


+ (instancetype)defautlConfig;


/**
 是否打印日志 
 */
@property (nonatomic, assign) BOOL log;



/**
 这个参数设为NO从后台恢复到前台时总是重连
 */
@property (nonatomic, assign) BOOL forceNew;


/**
 是否强制使用轮询
 */
@property (nonatomic, assign) BOOL forcePolling;


/**
 重连次数，-1表示一直重连
 */
@property (nonatomic, assign) NSInteger reconnectAttempts;


/**
  重连间隔时间
 */
@property (nonatomic, assign) NSInteger reconnectWait;


/**
 参数
 */
@property (nonatomic, strong) id connectParams;


///是否强制使用websocket, 解释The reason it uses polling first is because some firewalls/proxies block websockets. So polling lets socket.io work behind those. 默认为NO
@property (nonatomic, assign) BOOL forceWebsockets;


@end

NS_ASSUME_NONNULL_END
