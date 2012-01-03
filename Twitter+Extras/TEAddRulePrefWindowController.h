//
//  TEAddRulePrefWindowController.h
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 29/12/11.
//  Copyright (c) 2011 !cHoco Code. All rights reserved.
//

/*
 This file is a complete mess will refactor everything sometime soon
 Take this as an example of what not to do
 */

#import <Cocoa/Cocoa.h>
#import "TEMuteRule.h"
#import "TwitterAccount.h"
#import "TEPreferecesViewController.h"
#import <objc/message.h>

@interface TEAddRulePrefWindowController : NSWindowController <NSTextDelegate>
{
    IBOutlet NSWindow *window;
    IBOutlet NSButton *doneButton;
    
    IBOutlet NSTextField *ruleTextTooltip;
    IBOutlet NSTextField *ruleName;
    IBOutlet NSTextField *ruleText;
    IBOutlet NSPopUpButton *ruleType;
    IBOutlet NSMenu *accountsMenu;
    IBOutlet NSMenuItem *placeHolderItem;
        
    NSMutableArray *selectedAccounts;
    id parentController;
    BOOL isEditRuleSheet;
    TEMuteRule *editRule;
}

@property (nonatomic, assign) BOOL isEditRuleSheet;
@property (nonatomic,retain) id parentController;
@property (nonatomic,retain) NSTextField *ruleName;
@property (nonatomic,retain) NSTextField *ruleText;
@property (nonatomic,retain) NSPopUpButton *ruleType;
@property (nonatomic,retain) NSMenu *accountsMenu;
@property (nonatomic,retain) NSMenuItem *placeHolderItem;
@property (nonatomic,retain) NSMutableArray *selectedAccounts;

- (IBAction)accountMenuItemSelected:(id)sender;
- (IBAction)confirmAddRuleButtonPressed:(id)sender;
- (IBAction)cancelAddRulleButtonPressed:(id)sender;
- (IBAction)changeTooltipText:(id)sender;

- (id)initWithRule:(TEMuteRule *)rule;


@end
