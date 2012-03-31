//
//  Twitter+Extras.m
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 27/12/11.
//  Copyright (c) 2011 Just a Dream. All rights reserved.
//

#import "Twitter+Extras.h"

@interface TwitterTimelinetStream : NSObject <NSCoding>
{
    TwitterAccount *account;	// 52 = 0x34
}

- (TwitterAccount *)account;	// IMP=0x0004fc86
- (void)setAccount:(id)arg1;	// IMP=0x0004fc91

@end

@implementation NSWindowController(TE)

//probably should choose a better place to save
//right now if user closes twitter when preferences window is open it won't save rules

//UPDATE: found a better place :)


- (BOOL)TwitterExtras_windowShouldClose:(id)arg
{
    BOOL shouldClose = [self TwitterExtras_windowShouldClose:arg];
    if(shouldClose)
    {
        if ([TwitterExtras sharedInstance].extrasViewController) {
            [[TwitterExtras sharedInstance].extrasViewController saveDataToDisk];
            [[TwitterExtras sharedInstance].extrasViewController release];
            [TwitterExtras sharedInstance].extrasViewController = nil;
        }
    }

    return shouldClose;
}

//hook on the identifiers to show up our extra preferences

- (id)TwitterExtras_toolbarIdentifiers
{
    NSMutableArray *newToolbarIdentifiers = [NSMutableArray arrayWithArray:[self TwitterExtras_toolbarIdentifiers]];
    [newToolbarIdentifiers addObject:@"Extras"];
    return newToolbarIdentifiers;
}

- (void)extras
{
    NSLog(@"Extras View");
    //need to specify different plugin bundle
    [TwitterExtras sharedInstance].extrasViewController = [[TEPreferecesViewController alloc] initWithNibName:@"TEPreferecesViewController" bundle:[NSBundle bundleForClass:NSClassFromString(@"TwitterExtras")]];
    //twitter method in preferences controller don't want to add the header 
    [self setPrefsView:[TwitterExtras sharedInstance].extrasViewController.view windowTitle:@"Extras"];
}

- (id)TwitterExtras_toolbar:(id)arg1 itemForItemIdentifier:(id)arg2 willBeInsertedIntoToolbar:(BOOL)arg3
{
    if ([arg2 isEqualToString:@"Extras"]) {
        NSToolbarItem *item;
        item = [[NSToolbarItem alloc] initWithItemIdentifier:@"Extras"];
        [item setPaletteLabel:@"Extras"];
        [item setLabel:@"Extras"];
        [item setToolTip:@"Extras for Twitter for Mac."];
        NSImage *prefImage = [[NSImage alloc] initWithContentsOfFile:[[NSBundle bundleForClass:NSClassFromString(@"TwitterExtras")] pathForResource:@"ExtrasPref" ofType:@"png"]];
        [item setImage:prefImage];
        [prefImage release];
        [item setTarget:self];
        [item setAction:@selector(extras)];
        return [item autorelease];
    }
    return [self TwitterExtras_toolbar:arg1 itemForItemIdentifier:arg2 willBeInsertedIntoToolbar:arg3];    
}

@end

@implementation NSObject(TE)

- (void)TwitterExtras_applicationWillTerminate:(NSNotification *)notification
{
    NSLog(@"[+] Cleaning my mess...");
    if ([TwitterExtras sharedInstance].extrasViewController) {
        [[TwitterExtras sharedInstance].extrasViewController saveDataToDisk];
        [[TwitterExtras sharedInstance].extrasViewController release];
        [TwitterExtras sharedInstance].extrasViewController = nil;
    }
    [self TwitterExtras_applicationWillTerminate:notification];
}

- (id)TwitterExtras_menuForEvent:(id)event
{
    NSMenu * originalMenu = [self TwitterExtras_menuForEvent:event];
    if (![(TMStatusCell *)self mine]) {
        NSMenuItem *tmMenuItem = [[NSMenuItem alloc] initWithTitle:@"Set as last read Tweet" action:@selector(setLastReadTweetOnTM:) keyEquivalent:@""];
        [tmMenuItem setTarget:self];
        [originalMenu addItem:tmMenuItem];
        [tmMenuItem release];
    }
    return originalMenu;
}

- (void)setLastReadTweetOnTM:(id)sender
{
    TMStatusListViewController* listViewController;
    object_getInstanceVariable([sender target], "listViewController", (void**)&listViewController);
    NSString *account = [(TwitterAccount *)[listViewController account] username];
    TwitterStatus *status = [(TMStatusCell *)[(NSMenuItem *)sender target] status];
    NSString *statusID = [status statusID];
    if ([[[[status text] componentsSeparatedByString:@" "] objectAtIndex:0] isEqualToString:[NSString stringWithFormat:@"@%@", account]] ) {
        /*NSImage *tm = [[NSImage alloc] initWithContentsOfFile:[[NSBundle bundleForClass:NSClassFromString(@"TwitterExtras")] pathForResource:@"tm" ofType:@"png"]];
        Class imageMetaClass = objc_getClass("ABUIImage");
        id tmImage = objc_msgSend(imageMetaClass, @selector(imageWithData:), [tm TIFFRepresentation]);
        Class imageViewMetaClass = objc_getClass("ABUIImageView");
        id tmView = objc_msgSend(imageViewMetaClass, @selector(alloc));
        tmView = objc_msgSend(tmView, @selector(initWithImage:), tmImage);
        //ABUIImageView *tmView = [[ABUIImageView alloc] initWithImage:[ABUIImage imageWithData:[tm TIFFRepresentation]]];
        NSLog(@"%@", tmView);
        [(TMStatusCell *)[(NSMenuItem *)sender target] addSubview:tmView];
        Class colorMetaClass = objc_getClass("ABUIColor");
        [(TMStatusCell *)[(NSMenuItem *)sender target] setBackgroundColor:objc_msgSend(colorMetaClass, @selector(redColor))];*/
        if([TETweetMarker setLastStatusID:statusID forTwitterAccount:(TwitterAccount *)[listViewController account] forCollection:@"mentions"])
        {
            NSLog(@"[+] Mentions status ID %@ setting succeded", statusID);
        }
        else {
            NSLog(@"[+] Mentions status ID %@ setting failed", statusID);
        }
    }
    else {
        if([TETweetMarker setLastStatusID:statusID forTwitterAccount:(TwitterAccount *)[listViewController account] forCollection:@"timeline"])
        {
            NSLog(@"[+] Timeline status ID %@ setting succeded", statusID);
        }
        else {
            NSLog(@"[+] Timeline status ID %@ setting failed", statusID);
        }
    }
}


- (void)TwitterExtras_refresh
{
    NSLog(@"That's a refresh!");
    [self TwitterExtras_refresh];
}

- (void)TwitterExtras_loadNewer
{
    NSLog(@"Load newer!");
    [self TwitterExtras_loadNewer];
}

- (void)TwitterExtras_refreshTimelines
{
    NSLog(@"[+] Refreshing for account %@", [(TwitterAccount *)self username]);
    [self TwitterExtras_refreshTimelines];
}

- (void)TwitterExtras_friendsTimelineSinceID:(id)minID maxID:(id)maxID count:(id)count page:(id)page
{
    NSLog(@"[+] Loading Tweets from ID:%@ to ID:%@ count:%@ and page:%@", minID, maxID, count, page);
    [self TwitterExtras_friendsTimelineSinceID:minID maxID:maxID count:count page:page];
}

//this one is used for every twitterstream :D
- (void)TwitterExtras_setStatuses:(id)statuses
{
    NSMutableArray *newStatuses = [NSMutableArray arrayWithArray:statuses];
    NSMutableArray *discardedStatuses = [NSMutableArray array];
    
    for (TwitterStatus *status in newStatuses) {
        if ([[TwitterExtras sharedInstance] shouldDiscardStatus:status forAccount:((TwitterTimelinetStream *)self).account.username]) {
            NSLog(@"[+] Removing following status: %@", status);
            [discardedStatuses addObject:status];
        }
    }
    
    [newStatuses removeObjectsInArray:discardedStatuses];
    [self TwitterExtras_setStatuses:newStatuses];
}

/*
 This is used only for the main timeline
- (void)TwitterExtras_addStatuses:(id)statuses
{
    NSLog(@"TwitterAccount: %@", ((TwitterTimelinetStream *)self).account.username);
    NSLog(@"Statuses: %@", statuses);
    NSMutableArray *newStatuses = [NSMutableArray arrayWithArray:statuses];
    NSMutableArray *discardedStatuses = [NSMutableArray array];
    
    for (TwitterStatus *status in newStatuses) {
        NSLog(@"%@", status.text);
        if ([[TwitterExtras sharedInstance] shouldDiscardStatus:status forAccount:((TwitterTimelinetStream *)self).account.username]) {
            NSLog(@"Removing following status: %@", status);
            [discardedStatuses addObject:status];
        }
    }
    
    [newStatuses removeObjectsInArray:discardedStatuses];
    [self TwitterExtras_addStatuses:newStatuses];
}
*/
@end


@implementation TwitterExtras

@synthesize extrasViewController;

@dynamic pluginVersion, rules;

// main function , i love swithces

- (BOOL)shouldDiscardStatus:(TwitterStatus *)status forAccount:(NSString *)username
{
    for (TEMuteRule *rule in rules) {
        if ([rule isEnabled]) {
            for (NSString* account in rule.ruleAccounts) {
                if ([username isEqualToString:account]) {
                    switch (rule.ruleType) {
                        case 1:
                        {
                            if ([status.text containsString:[NSString stringWithFormat:@"#%@", rule.ruleText]]) {
                                return YES;
                            }
                            break;
                        }
                        case 2:
                        {
                            if([rule.ruleText isEqualToString:status.fromUser.username])
                                return YES;
                            else if (status.isRetweet)
                            {
                                if ([rule.ruleText isEqualToString:status.retweetedStatus.fromUser.username]) {
                                    return YES;
                                }
                            }
                            break;
                        }
                        case 3:
                        {
                            if ([status.text containsString:[NSString stringWithFormat:@"@%@", rule.ruleText]]) {
                                return YES;
                            }
                            break;
                        }
                        case 4:
                        {
                            if ([status.text containsString:[NSString stringWithFormat:@"%@", rule.ruleText]]) {
                                return YES;
                            }
                            break;
                        }
                        case 5:
                        {
                            if([rule.ruleText isEqualToString:status.sourceName])
                                return YES;
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        }
    }
    return FALSE;
}

//here again, maybe should find a better place instead of copying same code everywhere

- (NSString *)pathForDataFile
{
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    NSString *path = @"~/Library/Application Support/Twitter/";
    path = [path stringByExpandingTildeInPath];
    
    if ([fileManager fileExistsAtPath:path] == NO)
    {
        [fileManager createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    
    NSString *fileName = @"Twitter+Extras.db";
    return [path stringByAppendingPathComponent:fileName];    
}

- (void)loadDataFromDisk
{
    rules = [[NSMutableArray alloc] init];
    NSString *path = [self pathForDataFile];
    NSDictionary *rootObject = [NSKeyedUnarchiver unarchiveObjectWithFile:path];    
    NSArray *tempRules = [rootObject valueForKey:@"muteRules"];
    if (tempRules) {
        for (TEMuteRule* rule in tempRules) {
            if ([rule isEnabled]) {
                [rules addObject:rule];
            }
        }
    }
    
}

- (id)init
{
    if ((self = [super init]))
    {
        //[NSClassFromString(@"TwitterTimelineStream") jr_swizzleMethod:@selector(addStatuses:)
          //                                                 withMethod:@selector(TwitterExtras_addStatuses:) error:NULL];
        [NSClassFromString(@"TwitterConcreteStatusesStream") jr_swizzleMethod:@selector(setStatuses:)
                                                           withMethod:@selector(TwitterExtras_setStatuses:) error:NULL];
        [NSClassFromString(@"TweetiePreferencesWindowController") jr_swizzleMethod:@selector(_toolbarIdentifiers)
                                                                        withMethod:@selector(TwitterExtras_toolbarIdentifiers) error:NULL];
        
        [NSClassFromString(@"TweetiePreferencesWindowController") jr_swizzleMethod:@selector(toolbar:itemForItemIdentifier:willBeInsertedIntoToolbar:)
                                                                        withMethod:@selector(TwitterExtras_toolbar:itemForItemIdentifier:willBeInsertedIntoToolbar:) error:NULL];
        //[NSClassFromString(@"TweetiePreferencesWindowController") jr_swizzleMethod:@selector(windowShouldClose:) withMethod:@selector(TwitterExtras_windowShouldClose:) error:nil];
        [NSClassFromString(@"TwitterAPI") jr_swizzleMethod:@selector(friendsTimelineSinceID:maxID:count:page:) withMethod:@selector(TwitterExtras_friendsTimelineSinceID:maxID:count:page:) error:nil];
        [NSClassFromString(@"TwitterAccount") jr_swizzleMethod:@selector(refreshTimelines) withMethod:@selector(TwitterExtras_refresh) error:nil];
        [NSClassFromString(@"TwitterAccount") jr_swizzleMethod:@selector(refresh) withMethod:@selector(TwitterExtras_refreshTimelines) error:nil];
        [NSClassFromString(@"NSObject") jr_swizzleMethod:@selector(performSelector:withObject:afterDelay:) withMethod:@selector(TwitterExtras_performSelector:withObject:afterDelay:) error:nil];
        [NSClassFromString(@"TwitterTimelineStream") jr_swizzleMethod:@selector(_loadNewer) withMethod:@selector(TwitterExtras_loadNewer) error:nil];

        [NSClassFromString(@"TMStatusCell") jr_swizzleMethod:@selector(menuForEvent:) withMethod:@selector(TwitterExtras_menuForEvent:) error:nil];
        [NSClassFromString(@"Tweetie2AppDelegate") jr_swizzleMethod:@selector(applicationWillTerminate:) withMethod:@selector(TwitterExtras_applicationWillTerminate:) error:nil];

        [self loadDataFromDisk];
    }
    return self;
}

+ (NSString *)pluginVersion
{
    return [[[NSBundle bundleForClass:self] infoDictionary] objectForKey:@"CFBundleVersion"];
}

+ (TwitterExtras *)sharedInstance
{
    static TwitterExtras *plugin = nil;
    
    if (plugin == nil)
        plugin = [[TwitterExtras alloc] init];
    
    return plugin;
}


+ (void)load
{
    [self sharedInstance];
    NSLog(@"[+] Twitter Extras %@ Loaded", self.pluginVersion);
}


@end
