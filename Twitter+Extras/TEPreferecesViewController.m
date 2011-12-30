//
//  TEPreferecesViewController.m
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 28/12/11.
//  Copyright (c) 2011 Just a Dream All rights reserved.
//

#import "TEPreferecesViewController.h"

@implementation TEPreferecesViewController

@synthesize tableContents;

- (IBAction)editRuleButtonPressed:(id)sender
{
    TEAddRulePrefWindowController *editRuleWindow = [[TEAddRulePrefWindowController alloc] initWithRule:[tableContents objectAtIndex:[_tableView selectedRow]]];
    editRuleWindow.parentController = self;
    [NSApp beginSheet:editRuleWindow.window modalForWindow:[NSApp mainWindow] modalDelegate:self didEndSelector:@selector(endAddRule) contextInfo:nil];
}

- (IBAction)checkBoxSelected:(id)sender
{
    TEMuteRule *temp = ((TEMuteRule *)[tableContents objectAtIndex:[_tableView rowForView:((NSTableCellView *)sender).superview]]);
    temp.ruleEnabled = !temp.ruleEnabled;
}

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

- (void)saveDataToDisk
{
    NSString *path = [self pathForDataFile];
    
    NSMutableDictionary *rootObject = [NSMutableDictionary dictionary];
    
    [rootObject setValue:tableContents forKey:@"muteRules"];
    [NSKeyedArchiver archiveRootObject:rootObject toFile:path];
}

- (void)loadDataFromDisk
{
    NSString *path = [self pathForDataFile];
    NSDictionary *rootObject = [NSKeyedUnarchiver unarchiveObjectWithFile:path];    
    tableContents = [[rootObject valueForKey:@"muteRules"] mutableCopy];
    if (!tableContents) {
        tableContents = [[NSMutableArray alloc] init];
    }
}

- (void)endAddRule
{
    [_tableView reloadData];
}

- (IBAction)addRuleButtonPressed:(id)sender
{
    TEAddRulePrefWindowController *addRuleWindow = [[TEAddRulePrefWindowController alloc] initWithRule:nil];
    addRuleWindow.parentController = self;
    [NSApp beginSheet:addRuleWindow.window modalForWindow:[NSApp mainWindow] modalDelegate:self didEndSelector:@selector(endAddRule) contextInfo:nil];
}

- (IBAction)removeRuleButtonPressed:(id)sender
{
    if ([_tableView selectedRow] >= 0) {
        [tableContents removeObjectAtIndex:[_tableView selectedRow]];
        [_tableView reloadData];
    }
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        
    }
    
    return self;
}

- (void)loadView
{
    [super loadView];
    [self loadDataFromDisk];
    [_tableView reloadData];
    
}

- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView
{
    return [tableContents count];
}

- (NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row
{
    TEMuteRule *rule = [tableContents objectAtIndex:row];
    
    NSString *identifier = [tableColumn identifier];
    
    if ([identifier isEqualToString:@"ruleName"]) {
        NSTableCellView *cellView = [tableView makeViewWithIdentifier:identifier owner:self];
        cellView.textField.stringValue = rule.ruleName;
        return cellView;
    } else if ([identifier isEqualToString:@"twitterAccounts"]) {
        NSTableCellView *cellView = [tableView makeViewWithIdentifier:identifier owner:self];
        cellView.textField.stringValue = [rule.ruleAccounts componentsJoinedByString:@", "];
        return cellView;
    } else if ([identifier isEqualToString:@"ruleEnabled"]) {
        NSTableCellView *cellView = [tableView makeViewWithIdentifier:identifier owner:self];
        [checkBox setState:(long)rule.ruleEnabled];
        return cellView;
    } else {
        NSAssert1(NO, @"Unhandled table column identifier %@", identifier);
    }
    return nil;
}

@end
