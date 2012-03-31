#import "TMStatusListViewController.h"
#import "ABUITableViewCell.h"

@interface TMStatusCell : ABUITableViewCell
{
    TwitterStatus *status;	// 88 = 0x58
    TMStatusListViewController *listViewController;	// 136 = 0x88
    struct {
        unsigned int firstInList:1;
        unsigned int isSelectingWithMouse:1;
        unsigned int dim:1;
        unsigned int hasSubtext:1;
        unsigned int didDrag:1;
        unsigned int hover:1;
        unsigned int drawSuperBlue:1;
        unsigned int shouldHighlightMention:1;
        unsigned int special:1;
    } _cellFlags;	// 140 = 0x8c
}

+ (void)setupFonts;	// IMP=0x0007aece
+ (void)initialize;	// IMP=0x0007b08c
+ (float)heightForStatus:(id)arg1 inTableView:(id)arg2;	// IMP=0x0007b814
- (id)description;	// IMP=0x0007b7a6
- (void)drawUserInfo:(struct CGRect)arg1;	// IMP=0x0007ddad
- (BOOL)derepeaterEnabled;	// IMP=0x00078462
- (id)representedPasteboardObject;	// IMP=0x00078469
- (id)initWithStyle:(int)arg1 reuseIdentifier:(id)arg2;	// IMP=0x0007d1fd
- (void)dealloc;	// IMP=0x0007d084
- (struct CGRect)avatarRect;	// IMP=0x0007d028
- (BOOL)isHovered;	// IMP=0x000786b0
- (void)_layout;	// IMP=0x0007cef8
- (void)layoutSubviews;	// IMP=0x0007ceb8
- (id)derepeaterView;	// IMP=0x00078474
- (id)derepeaterIdentifier;	// IMP=0x000786ea
- (void)drawRect:(struct CGRect)arg1;	// IMP=0x0007c301
- (void)_updateAttributedStrings;	// IMP=0x00078731
- (void)setEverythingNeedsDisplay;	// IMP=0x0007c2c1
- (void)setStatus:(id)arg1;	// IMP=0x00078916
- (BOOL)hasClickableMetaText;	// IMP=0x00078adc
- (void)prepareForDisplay;	// IMP=0x0007c269
- (void)userDidUpdate:(id)arg1;	// IMP=0x00078b15
- (void)__updateWithNewHoverState;	// IMP=0x00078b60
- (void)_hoverStateChanged;	// IMP=0x00078c87
- (BOOL)canViewConversation;	// IMP=0x00078cc8
- (void)updateControls:(id)arg1;	// IMP=0x00078cf8
- (void)mouseEntered:(id)arg1;	// IMP=0x0007c209
- (void)mouseExited:(id)arg1;	// IMP=0x0007c1c2
- (void)view:(id)arg1 mouseEntered:(id)arg2;	// IMP=0x000790aa
- (void)view:(id)arg1 mouseExited:(id)arg2;	// IMP=0x000790e3
- (void)flashKeyboardActivatedHitRange:(id)arg1;	// IMP=0x00079102
- (void)mouseDown:(id)arg1;	// IMP=0x0007c145
- (void)mouseDragged:(id)arg1;	// IMP=0x0007c0c1
- (void)mouseUp:(id)arg1;	// IMP=0x0007beb1
- (id)activeRangesForTextRenderer:(id)arg1;	// IMP=0x00079278
- (void)setSelected:(BOOL)arg1 animated:(BOOL)arg2;	// IMP=0x0007bd18
- (id)menuForEvent:(id)arg1;	// IMP=0x000793c2
- (BOOL)mine;	// IMP=0x0007a25b
- (BOOL)canBlock;	// IMP=0x0007a29f
- (BOOL)canRetweet;	// IMP=0x0007a308
- (BOOL)validateMenuItem:(id)arg1;	// IMP=0x0007a3de
- (void)copy:(id)arg1;	// IMP=0x0007a47a
- (void)copyLinkToTweet:(id)arg1;	// IMP=0x0007a509
- (id)_baseAlert;	// IMP=0x0007bbbf
- (void)block:(id)arg1;	// IMP=0x0007a5ac
- (void)blockSheetDidEnd:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;	// IMP=0x0007a853
- (void)delete:(id)arg1;	// IMP=0x0007a8c5
- (void)deleteSheetDidEnd:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;	// IMP=0x0007aa47
- (void)endPasteboardDragging:(unsigned long)arg1;	// IMP=0x0007aa91
- (void)viewTweetSource:(id)arg1;	// IMP=0x0007aabf
- (void)viewOnWeb:(id)arg1;	// IMP=0x0007ab15
- (void)userDetails:(id)arg1;	// IMP=0x0007ab91
- (void)reply:(id)arg1;	// IMP=0x0007bb22
- (void)directMessage:(id)arg1;	// IMP=0x0007ba5f
- (void)favorite:(id)arg1;	// IMP=0x0007ac0d
- (void)retweet:(id)arg1;	// IMP=0x0007ac88
- (void)retweetSheetDidEnd:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;	// IMP=0x0007ae2d
- (void)quoteTweet:(id)arg1;	// IMP=0x0007b9c2
- (void)viewConversation:(id)arg1;	// IMP=0x0007ae90
- (id)status;	// IMP=0x0007847f

@end
