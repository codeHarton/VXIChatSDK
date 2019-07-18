//
//  VXITool.h
//  SocketTest
//
//  Created by harton on 2019/7/4.
//  Copyright © 2019 VXI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <pthread.h>

NS_ASSUME_NONNULL_BEGIN



/**
 主线程执行任务
 */
static inline void dispatch_async_on_main_queue(void (^block)(void)) {
    if (pthread_main_np()) {
        block();
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

@interface VXITool : NSObject

+ (NSDateFormatter *)vxi_commonTimeFormat;

////去掉杠的  uuid
+ (NSString *)vxi_uuidStringTirmLine;



////是否是空   nil  NSNull @"" 返回YES
+ (BOOL)vxi_isBlankString:(NSString *)string;


/**
 base64编码
YES
 @param string 要编码的字符串
 @return 编码后的字符串
 */
+ (NSString *)vxi_base64EncodeString:(NSString *)string;

/**
 base64解码

 @param string 要解码的字符串     这里对&号进行了=号替换处理
 @return 解码后的字符串
 */
+ (NSString *)vxi_base64DecodeString:(NSString *)string;

/// format @"yyyyMMddHHmmss"   当前时间戳
+ (NSString *)vxi_currentTimeStimp;
///format   @"HH:mm:ss"         当前事件
+ (NSString *)vxi_currentHMSTime;


@end





NS_ASSUME_NONNULL_END
