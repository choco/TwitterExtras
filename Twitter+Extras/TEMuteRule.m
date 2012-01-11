//
//  TEMuteRule.m
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 28/12/11.
//  Copyright (c) 2011 Just a Dream All rights reserved.
//

#import "TEMuteRule.h"

@implementation TEMuteRule

@synthesize ruleName, ruleAccounts, ruleText, ruleType, ruleEnabled;

- (void) encodeWithCoder: (NSCoder *)coder
{
    [coder encodeObject:ruleName forKey:@"ruleName"];
    [coder encodeObject:ruleAccounts forKey:@"ruleAccounts"];
    [coder encodeObject:ruleText forKey:@"ruleText"];
    [coder encodeInt:ruleType forKey:@"ruleType"];
    [coder encodeBool:ruleEnabled forKey:@"ruleEnabled"];
}

- (id)initWithCoder:(NSCoder *)coder
{
    if (self = [super init])
    {
        self.ruleName = [coder decodeObjectForKey:@"ruleName"];
        self.ruleAccounts = [coder decodeObjectForKey:@"ruleAccounts"];
        self.ruleText = [coder decodeObjectForKey:@"ruleText"];
        self.ruleType = [coder decodeIntForKey:@"ruleType"];
        self.ruleEnabled = [coder decodeBoolForKey:@"ruleEnabled"];
    }
    return self;
}

+ (id)ruleWithName:(NSString *)name forAccouts:(NSArray *)accounts withType:(int)type andText:(NSString *)text
{
    TEMuteRule *newRule = [[TEMuteRule alloc] init];
    newRule.ruleName = name;
    newRule.ruleAccounts = accounts;
    newRule.ruleType = type;
    newRule.ruleText = text;
    newRule.ruleEnabled = YES;
    return [newRule autorelease];
}

- (BOOL)isEnabled
{
    return self.ruleEnabled;
}

- (BOOL)isHashtagRule
{
    if (ruleType == 1) {
        return YES;
    }
    return  NO;
}

- (BOOL)isFromUserRule
{
    if (ruleType == 2) {
        return YES;
    }
    return  NO; 
}

- (BOOL)isMentionUserRule
{
    if (ruleType == 3) {
        return YES;
    }
    return  NO;
}

- (BOOL)isTweetTextRule
{
    if (ruleType == 4) {
        return YES;
    }
    return  NO;
}
- (BOOL)isTwitterClientRule
{
    if (ruleType == 5) {
        return YES; 
    }
    return NO;
}

@end
