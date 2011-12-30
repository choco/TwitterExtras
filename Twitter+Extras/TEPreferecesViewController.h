//
//  TEPreferecesViewController.h
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 28/12/11.
//  Copyright (c) 2011 Just a Dream All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "TEAddRulePrefWindowController.h"
#import "TEMuteRule.h"

@interface TEPreferecesViewController : NSViewController <NSTableViewDelegate, NSTableViewDataSource>
{
    IBOutlet NSTableView *_tableView;
    IBOutlet NSButton *checkBox;
    NSMutableArray *tableContents;
}

@property (nonatomic, retain) NSMutableArray *tableContents;

- (IBAction)addRuleButtonPressed:(id)sender;
- (IBAction)removeRuleButtonPressed:(id)sender;
- (IBAction)checkBoxSelected:(id)sender;
- (IBAction)editRuleButtonPressed:(id)sender;

- (void)saveDataToDisk;

@end
