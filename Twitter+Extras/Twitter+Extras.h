//
//  Twitter+Extras.h
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 27/12/11.
//  Copyright (c) 2011 Just a Dream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import "JRSwizzle.h"
#import "TwitterStatus.h"
#import "TwitterAccount.h"
#import "TEMuteRule.h"
#import "TEPreferecesViewController.h"
#import "NSString+TE.h"

@interface TwitterExtras : NSObject
{
    TEPreferecesViewController *extrasViewController;
    NSMutableArray *rules;
}

@property (nonatomic, readonly) NSString *pluginVersion;
@property (nonatomic, retain) TEPreferecesViewController *extrasViewController;
@property (nonatomic, retain) NSMutableArray *rules;


+ (TwitterExtras *)sharedInstance;
- (BOOL)shouldDiscardStatus:(TwitterStatus *)status forAccount:(NSString *)username;
- (void)loadDataFromDisk;

@end
