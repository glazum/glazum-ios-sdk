//
//  Glazum.h
//  Glazum
//
//  Created by Mikhail Shkutkov on 4/17/13.
//  Copyright (c) 2013 Mikhail Shkutkov. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^GlazumQuestionBeforeCodeBlock)(BOOL willShowQuestion);
typedef void (^GlazumQuestionAfterCodeBlock)(BOOL questionWasShown);

typedef NS_ENUM(NSInteger, GlazumQuestionType) {
    kQuestionWithSingleLineTextAnswer,
    kQuestionWithMultiLineTextAnswer,
    kQuestionWithSingleAnswerSelection,
    kQuestionWithMultipleAnswerSelection,
    kQuestionWithNetPromoterScore
};

extern NSString *const GlazumOptionDebug; // Default value is @NO. Prints debug logs using NSLog
extern NSString *const GlazumOptionDebugLogHandler;

@interface Glazum : NSObject

+ (void)startUp:(NSString *)applicationID;

+ (void)setUserIdentifier:(NSString *)userIdentifier;
+ (void)setCustomVariable:(NSString *)variableValue named:(NSString *)variableName;

+ (void)setOptions:(NSDictionary*)options;

+ (void)setMarker:(NSString *)markerName;
+ (void)setMarker:(NSString *)markerName
         doBefore:(GlazumQuestionBeforeCodeBlock)beforeQuestionBlock
          doAfter:(GlazumQuestionAfterCodeBlock)afterQuestionBlock;

+ (void)testQuestionWithType:(GlazumQuestionType)type;
+ (void)testQuestionWithType:(GlazumQuestionType)type
                    doBefore:(GlazumQuestionBeforeCodeBlock)beforeQuestionBlock
                     doAfter:(GlazumQuestionAfterCodeBlock)afterQuestionBlock;
@end
