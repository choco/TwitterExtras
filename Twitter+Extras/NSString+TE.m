//
//  NSString+TE.m
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 30/12/11.
//  Copyright (c) 2011 Just a Dream All rights reserved.
//

#import "NSString+TE.h"

@implementation NSString (TE)

- (BOOL)containsString:(NSString *)string options:(NSStringCompareOptions)options
{
    NSRange rng = [self rangeOfString:string options:options];
    return rng.location != NSNotFound;
}

- (BOOL)containsString:(NSString *)string
{
    return [self containsString:string options:NSCaseInsensitiveSearch];
}

@end
