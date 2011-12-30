//
//  NSString+TE.h
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 30/12/11.
//  Copyright (c) 2011 Just a Dream All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TE) 

- (BOOL)containsString:(NSString *)string;
- (BOOL)containsString:(NSString *)string options:(NSStringCompareOptions)options;

@end