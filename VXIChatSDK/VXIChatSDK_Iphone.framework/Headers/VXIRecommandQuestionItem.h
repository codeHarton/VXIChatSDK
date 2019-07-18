//
//  VXIRecommandQuestionItem.h
//  VXIChatSDK
//
//  Created by harton on 2019/7/10.
//  Copyright © 2019 VXI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VXIRecommandQuestionItem : NSObject
/**
 推荐问题的id
 */
@property (nonatomic, copy) NSString *_id;

/**
 是推荐问题的title
 */
@property (nonatomic, copy) NSString *contents;

/**
 仅用来测试
 */
+ (instancetype)test_createWithContent:(NSString *)contents;
@end

NS_ASSUME_NONNULL_END
