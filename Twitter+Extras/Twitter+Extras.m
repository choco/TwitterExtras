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


//this one is used for every twitterstream :D
- (void)TwitterExtras_setStatuses:(id)statuses
{
    //NSLog(@"TwitterAccount: %@", ((TwitterTimelinetStream *)self).account.username);
    //NSLog(@"Statuses: %@", statuses);
    NSMutableArray *newStatuses = [NSMutableArray arrayWithArray:statuses];
    NSMutableArray *discardedStatuses = [NSMutableArray array];
    
    for (TwitterStatus *status in newStatuses) {
        if ([[TwitterExtras sharedInstance] shouldDiscardStatus:status forAccount:((TwitterTimelinetStream *)self).account.username]) {
            NSLog(@"Removing following status: %@", status);
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
        [NSClassFromString(@"TweetiePreferencesWindowController") jr_swizzleMethod:@selector(windowShouldClose:) withMethod:@selector(TwitterExtras_windowShouldClose:) error:nil];
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
    NSLog(@"Twitter Extras %@ Loaded", self.pluginVersion);
}


@end
