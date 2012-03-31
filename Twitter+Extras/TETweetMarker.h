//
//  TETweetMarker.h
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 03/03/12.
//  Copyright (c) 2011 Just a Dream All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/objc-runtime.h>
#import "TwitPicCompatibleImageService.h"
#import "TwitterAccount.h"

@interface TETweetMarker : NSObject

+ (NSString *)getLastStatusIDForTwitterAccount:(TwitterAccount *)account forCollection:(NSString *)collection;
+ (BOOL)setLastStatusID:(NSString *)statusID forTwitterAccount:(TwitterAccount *)account forCollection:(NSString *)collection;

@end
