#import "ABUIViewController.h"

@interface TMStatusListViewController : ABUIViewController 
{
    TwitterAccount *account;	// 20 = 0x14
    NSArray *statuses;	// 24 = 0x18
    NSArray *setStatusesAfterTrackingEnds;	// 28 = 0x1c
    NSArray *unfilteredStatuses;	// 32 = 0x20
    BOOL derepeaterEnabled;	// 48 = 0x30
    BOOL dimMentions;	// 49 = 0x31
    BOOL disableMyMentionsHighlighting;	// 50 = 0x32	// 56 = 0x38
    struct {
        float relativeOffset;
        NSString *statusID;
    } saveScrollPosition;	// 72 = 0x48
    struct {
        unsigned int findMode:1;
        unsigned int isSettingStatuses:1;
    } _flags;	// 80 = 0x50
    double lastMoveTime;	// 84 = 0x54
    NSDate *lastViewedTime;	// 92 = 0x5c
    NSTimer *refreshTimer;	// 96 = 0x60
}

+ (id)standardPullDownView;	// IMP=0x00070f91
- (void)dealloc;	// IMP=0x00071582
- (id)copyWithZone:(struct _NSZone *)arg1;	// IMP=0x00073fb7
- (id)tableView;	// IMP=0x0006e225
- (id)toolbar;	// IMP=0x0006e230
- (id)initialFirstResponder;	// IMP=0x0006e319
- (void)loadOlder:(id)arg1;	// IMP=0x0006e23b
- (void)loadNewer:(id)arg1;	// IMP=0x0006e240
- (void)fillInGap:(id)arg1;	// IMP=0x0006e245
- (void)viewedMostRecent:(id)arg1;	// IMP=0x0006e24a
- (BOOL)isLoadingNewer;	// IMP=0x0006e24f
- (id)lastUpdated;	// IMP=0x0006e256
- (id)autosaveName;	// IMP=0x0006e25d
- (BOOL)showToolbar;	// IMP=0x0006e264
- (void)setupToolbar;	// IMP=0x0006e26b
- (void)popBack;	// IMP=0x0006e33c
- (BOOL)bleedsToTopOfWindow;	// IMP=0x0006e375
- (BOOL)bleedsToBottomOfWindow;	// IMP=0x0006e3d8
- (id)viewForRootBounce;	// IMP=0x0006e270
- (BOOL)canPullToRefresh;	// IMP=0x0006e27b
- (id)pullDownView;	// IMP=0x0006e45b
- (void)loadView;	// IMP=0x000737fc
- (id)_defaultsScrollPositionKey;	// IMP=0x0006e981
- (BOOL)savePositionEnabled;	// IMP=0x0006e282
- (void)_saveStatusID:(id)arg1 relativeOffset:(float)arg2;	// IMP=0x0006e9c6
- (void)_getStatusID:(id *)arg1 relativeOffset:(float *)arg2;	// IMP=0x0007139c
- (void)savePosition;	// IMP=0x000735af
- (void)_reloadData;	// IMP=0x0007339b
- (void)_startFind;	// IMP=0x0006eacb
- (void)_updateDisplayStatuses;	// IMP=0x0006ede7
- (void)textViewDidChange:(id)arg1;	// IMP=0x0006ee80
- (void)_endFind;	// IMP=0x0006eea7
- (void)performFindPanelAction:(id)arg1;	// IMP=0x0006f193
- (BOOL)textFieldShouldClear:(id)arg1;	// IMP=0x0006f233
- (id)selectedStatus;	// IMP=0x0006f282
- (void)setSelectedStatus:(id)arg1 animated:(BOOL)arg2 scrollPosition:(int)arg3;	// IMP=0x0006f30b
- (void)_tabToTable;	// IMP=0x0006f394
- (BOOL)textFieldShouldReturn:(id)arg1;	// IMP=0x0006f439
- (BOOL)textFieldShouldTabToNext:(id)arg1;	// IMP=0x0006f45d
- (id)visibleStatuses;	// IMP=0x00073226
- (BOOL)headerCellIsVisible;	// IMP=0x0006f481
- (BOOL)loadOlderCellIsVisible;	// IMP=0x000730e3
- (float)pollInterval;	// IMP=0x0006e294
- (BOOL)_prefShouldScrollToTop;	// IMP=0x0006f4e8
- (void)jumpToTop:(id)arg1;	// IMP=0x0006f527
- (void)jumpToBottom:(id)arg1;	// IMP=0x0006f552
- (void)_startTimer;	// IMP=0x00071491
- (void)_cancelTimer;	// IMP=0x0006f57d
- (void)fontDidChange:(id)arg1;	// IMP=0x0006f5c2
- (void)viewWillAppear:(BOOL)arg1;	// IMP=0x00072fd3
- (void)viewWillDisappear:(BOOL)arg1;	// IMP=0x00072f39
- (void)viewWillBeObscured:(BOOL)arg1;	// IMP=0x0006f622
- (void)viewDidAppear:(BOOL)arg1;	// IMP=0x00072f04
- (void)viewWillBeUnobscured:(BOOL)arg1;	// IMP=0x00072e7a
- (void)_endWaitSetStatuses;	// IMP=0x0006f702
- (void)setStatuses:(id)arg1;	// IMP=0x00072b1e
- (long)tableView:(id)arg1 numberOfRowsInSection:(long)arg2;	// IMP=0x0006f78e
- (float)tableView:(id)arg1 heightForRowAtIndexPath:(id)arg2;	// IMP=0x0007152c
- (BOOL)isConversationList;	// IMP=0x0006e29b
- (BOOL)canViewConversation:(id)arg1;	// IMP=0x0006f7b1
- (void)viewConversation:(id)arg1;	// IMP=0x0006f807
- (id)hoveredStatusCell;	// IMP=0x000729c3
- (id)hoveredStatus;	// IMP=0x0006f94d
- (id)doViewStatusAction:(id)arg1;	// IMP=0x0006f97e
- (id)menuItemWithTitle:(id)arg1 action:(id)arg2;	// IMP=0x0006f9ab
- (BOOL)_addActiveRanges:(id)arg1 forStatus:(id)arg2 toMenu:(id)arg3;	// IMP=0x00072835
- (BOOL)_addOpenAllLinksItem:(id)arg1 toMenu:(id)arg2;	// IMP=0x0006faa6
- (BOOL)_addUserDetailsItem:(id)arg1 toMenu:(id)arg2;	// IMP=0x0006fd8f
- (BOOL)_addViewConversationItem:(id)arg1 toMenu:(id)arg2;	// IMP=0x0006ff43
- (void)addMenuItemsForStatus:(id)arg1 toMenu:(id)arg2;	// IMP=0x0007012f
- (id)actionsForStatus:(id)arg1;	// IMP=0x00070504
- (void)magicStatusDetailsForStatusCell:(id)arg1;	// IMP=0x00072507
- (void)jumpToBestStatusEntity:(id)arg1;	// IMP=0x0007059f
- (void)showStatusEntitiesMenu:(id)arg1;	// IMP=0x000705f1
- (BOOL)validateMenuItem:(id)arg1;	// IMP=0x0007228c
- (void)swipeForward:(id)arg1;	// IMP=0x00070651
- (void)doubleClickStatusCell:(id)arg1;	// IMP=0x000706e4
- (void)_setPullToRefreshState:(int)arg1;	// IMP=0x00071b7c
- (void)_updatePullToRefresh;	// IMP=0x0007071c
- (void)scrollViewDidScroll:(id)arg1;	// IMP=0x00071b39
- (void)scrollViewDidEndDragging:(id)arg1;	// IMP=0x00070841
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;	// IMP=0x0006e2a2
- (void)tableView:(id)arg1 didClickRowAtIndexPath:(id)arg2 withEvent:(id)arg3;	// IMP=0x000708b2
- (BOOL)isSpecialStatus:(id)arg1;	// IMP=0x0006e2a7
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;	// IMP=0x0007097c
- (id)topFullyVisibleStatusCell;	// IMP=0x000718ac
- (id)adjacentIndexPath:(id)arg1 direction:(long)arg2;	// IMP=0x0006e2ae
- (void)selectObjectWithID:(id)arg1;	// IMP=0x00070d24
- (void)_moveSelection:(int)arg1;	// IMP=0x000716c2
- (void)moveUp:(id)arg1;	// IMP=0x00070d76
- (void)moveDown:(id)arg1;	// IMP=0x00070d9d
- (BOOL)willPopViewController;	// IMP=0x00070dc4
- (BOOL)performKeyAction:(id)arg1;	// IMP=0x00070df3
- (BOOL)disableMyMentionsHighlighting;	// IMP=0x0006e2b5
- (void)setDisableMyMentionsHighlighting:(BOOL)arg1;	// IMP=0x0006e2c1
- (BOOL)dimMentions;	// IMP=0x0006e2cf
- (void)setDimMentions:(BOOL)arg1;	// IMP=0x0006e2db
- (BOOL)derepeaterEnabled;	// IMP=0x0006e2e9
- (void)setDerepeaterEnabled:(BOOL)arg1;	// IMP=0x0006e2f5
- (id)statuses;	// IMP=0x0006e303
- (id)account;	// IMP=0x0006e30e
- (void)setAccount:(id)arg1;	// IMP=0x00071686

@end