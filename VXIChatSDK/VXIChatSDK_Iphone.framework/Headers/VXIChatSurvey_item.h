//
//  VXIChatSurvey_item.h
//  VXIChatSDK
//
//  Created by harton on 2019/7/9.
//  Copyright © 2019 VXI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


///满意度调查  评分列表  [{value=非常不满意, key=f1}, {value=不满意, key=f2}, {value=一般, key=f3}, {value=满意, key=f4}, {value=非常满意, key=f5}]
@interface VXIChatSurvey_item : NSObject


@property (nonatomic, copy) NSString *value;

@property (nonatomic, copy) NSString *key;

@end


NS_ASSUME_NONNULL_END
