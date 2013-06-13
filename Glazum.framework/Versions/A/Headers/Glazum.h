//
//  Glazum.h
//  Glazum
//
//  Created by Mikhail Shkutkov on 4/17/13.
//  Copyright (c) 2013 Mikhail Shkutkov. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^QuestionBeforeCodeBlock)(BOOL willShowQuestion);
typedef void (^QuestionAfterCodeBlock)(BOOL questionWasShown);

typedef enum {
    kQuestionWithSingleLineTextAnswer,
    kQuestionWithMultiLineTextAnswer,
    kQuestionWithSingleAnswerSelection,
    kQuestionWithMultipleAnswerSelection,
    kQuestionWithNetPromoterScore
} QuestionType;

extern NSString *const GlazumOptionDebug; // Default value is @NO. Prints debug logs using NSLog
extern NSString *const GlazumOptionDebugLogHandler;

@interface Glazum : NSObject

+ (void)startUp:(NSString *)applicationID;

+ (void)setUserIdentifier:(NSString *)userIdentifier;
+ (void)setCustomVariable:(NSString *)variableValue named:(NSString *)variableName;

+ (void)setOptions:(NSDictionary*)options;

+ (void)setMarker:(NSString *)markerName;
+ (void)setMarker:(NSString *)markerName
         doBefore:(QuestionBeforeCodeBlock)beforeQuestionBlock
          doAfter:(QuestionAfterCodeBlock)afterQuestionBlock;

+ (void)testQuestionWithType:(QuestionType)type;
+ (void)testQuestionWithType:(QuestionType)type
                    doBefore:(QuestionBeforeCodeBlock)beforeQuestionBlock
                     doAfter:(QuestionAfterCodeBlock)afterQuestionBlock;
@end
