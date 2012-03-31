//
//  TEAddRulePrefWindowController.m
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 29/12/11.
//  Copyright (c) 2011 Just a Dream All rights reserved.
//

#import "TEAddRulePrefWindowController.h"

@implementation TEAddRulePrefWindowController

@synthesize parentController, ruleName, ruleText, ruleType, accountsMenu, selectedAccounts, placeHolderItem, isEditRuleSheet;

- (id)initWithRule:(TEMuteRule *)rule
{
    self = [super initWithWindowNibName:@"TEAddRulePrefWindowController"];
    if (self) {
        selectedAccounts = [[NSMutableArray alloc] init];
        if (rule) {
            isEditRuleSheet = YES;
            editRule = rule;
        }
        else
        {
            isEditRuleSheet = NO;
        }
        // Initialization code here.
    }
    
    return self;
}

- (void)awakeFromNib
{
    //Brace yourself, here comes the magic!
    Class twitterMetaClass = objc_getClass("Twitter");
	id sharedTwitter = objc_msgSend(twitterMetaClass, @selector(sharedTwitter));
    NSMutableArray *accounts = objc_msgSend(sharedTwitter, @selector(accounts));
    NSMutableArray *accountsUsernames = [NSMutableArray array];
    for (TwitterAccount *account in accounts) {
        [accountsUsernames addObject:account.username];
    }
    for (NSString *username in accountsUsernames) {
        [accountsMenu addItemWithTitle:username action:@selector(accountMenuItemSelected:) keyEquivalent:username];
    }
    
    //setup a part if we have a rule to modify
    //probably should have come up with better solution, didn't spend to much time on design :P
    if ([self isEditRuleSheet]) {
        [doneButton setTitle:@"Done"];
        selectedAccounts = [editRule.ruleAccounts mutableCopy];
        placeHolderItem.title = [selectedAccounts componentsJoinedByString:@", "];
        for (NSMenuItem *item in ruleType.itemArray)
        {
            if (item.tag == editRule.ruleType) {
                [ruleType selectItemWithTag:item.tag];
            }
        }
        ruleName.stringValue = editRule.ruleName;
        ruleText.stringValue = editRule.ruleText;
        for (NSMenuItem *item in accountsMenu.itemArray) {
            for (NSString *title in selectedAccounts) {
                if ([item.title isEqualToString:title]) {
                    [item setState:1];
                }
            }
        }
        [self changeTooltipText:nil];
        
    }
    else{
        //select hashtag as default
        [ruleType selectItemWithTag:1];

    }
}

- (IBAction)accountMenuItemSelected:(id)sender
{
    //who needs bindings ?!?!
    if (((NSMenuItem *)sender).state == 0) {
        [((NSMenuItem *)sender) setState:1];
        [selectedAccounts addObject:((NSMenuItem *)sender).title];
    }
    else
    {
        [((NSMenuItem *)sender) setState:0];
        [selectedAccounts removeObject:((NSMenuItem *)sender).title];
    }
    placeHolderItem.title = [selectedAccounts componentsJoinedByString:@", "];
}

- (IBAction)changeTooltipText:(id)sender
{
    switch (ruleType.selectedTag) {
        case 1:
            ruleTextTooltip.stringValue = @"#";
            break;
        case 2:
        case 3:
            ruleTextTooltip.stringValue = @"@";
            break;
        case 4:
        case 5:
            ruleTextTooltip.stringValue = @"";
            break;
            
        default:
            ruleTextTooltip.stringValue = @"";
            break;
    }
}

- (IBAction)confirmAddRuleButtonPressed:(id)sender
{
    //Cant's get NSTextDelegate to work ?!?!?! Need to check field here...
    if ([ruleName.stringValue length]>0) {
        if ([ruleText.stringValue length]>0) {
            if ([selectedAccounts count]>0) {
                if ([self isEditRuleSheet]) {
                    //probably should update but who cares <- shitty code
                    //should use datasource
                    TEMuteRule *rule = [TEMuteRule ruleWithName:ruleName.stringValue forAccouts:selectedAccounts withType:(int)ruleType.selectedItem.tag andText:ruleText.stringValue];
                    [((TEPreferecesViewController *)parentController).tableContents removeObject:editRule];
                    [((TEPreferecesViewController *)parentController).tableContents addObject:rule];
                    
                }
                else
                {
                    TEMuteRule *rule = [TEMuteRule ruleWithName:ruleName.stringValue forAccouts:selectedAccounts withType:(int)ruleType.selectedItem.tag andText:ruleText.stringValue];
                    [((TEPreferecesViewController *)parentController).tableContents addObject:rule];
                }
                [NSApp endSheet:self.window returnCode:NSOKButton];
                [self.window orderOut:nil];
            }
        }
    }
}

- (IBAction)cancelAddRulleButtonPressed:(id)sender
{
    [NSApp endSheet:self.window returnCode:NSCancelButton];
    [self.window orderOut:nil];
}

- (void)windowDidLoad
{
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}

@end
