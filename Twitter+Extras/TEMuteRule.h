//
//  TEMuteRule.h
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 28/12/11.
//  Copyright (c) 2011 Just a Dream All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TEMuteRule : NSObject <NSCoding>
{
    NSString *ruleName;
    NSArray *ruleAccounts;
    int ruleType;
    NSString *ruleText;
    BOOL ruleEnabled;
}

/* 
 Used to distinguish different rules when shown to the user
 */

@property (nonatomic, copy) NSString *ruleName;

/*
 Accounts on which this rule is configured
 */

@property (nonatomic, copy) NSArray *ruleAccounts;

/*
 Different rules type:
 
 1- Hashtag 
 2- From Twitter username
 3- Mentions Twitter username
 4- Tweet text
 5- Twitter client
 */

@property (nonatomic, assign) int ruleType;


/*
 The text that'll be excluded by the rule, based on its type
 
 Example:
 
 ruleText = @"test"
 ruleType = 1;
 
 Tweet with #test will be excluded from your timeline
 */


@property (nonatomic, copy) NSString *ruleText;

@property (nonatomic, assign) BOOL ruleEnabled;

+ (id)ruleWithName:(NSString *)name forAccouts:(NSArray *)accounts withType:(int)type andText:(NSString *)text;

- (BOOL)isHashtagRule;
- (BOOL)isFromUserRule;
- (BOOL)isMentionUserRule;
- (BOOL)isTweetTextRule;
- (BOOL)isTwitterClientRule;
- (BOOL)isEnabled;

@end
