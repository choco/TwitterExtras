#import "ABUIVIew.h"

@interface ABUITableViewCell : ABUIView
{
    NSString *_reuseIdentifier;	// 80 = 0x50
    struct {
        unsigned int highlighted:1;
        unsigned int selected:1;
    } _tableViewCellFlags;	// 84 = 0x54
}

- (void)setReuseIdentifier:(id)arg1;	// IMP=0x0000d49f
- (id)initWithStyle:(int)arg1 reuseIdentifier:(id)arg2;	// IMP=0x0000d5de
- (void)dealloc;	// IMP=0x0000d815
- (id)reuseIdentifier;	// IMP=0x0000d443
- (void)prepareForReuse;	// IMP=0x0000d4db
- (void)prepareForDisplay;	// IMP=0x0000d53a
- (id)tableView;	// IMP=0x0000d559
- (id)indexPath;	// IMP=0x0000d578
- (BOOL)acceptsFirstMouse:(id)arg1;	// IMP=0x0000d44e
- (void)mouseDown:(id)arg1;	// IMP=0x0000d73e
- (void)mouseUp:(id)arg1;	// IMP=0x0000d649
- (BOOL)isHighlighted;	// IMP=0x0000d455
- (BOOL)isSelected;	// IMP=0x0000d465
- (void)setSelected:(BOOL)arg1;	// IMP=0x0000d5af
- (void)setSelected:(BOOL)arg1 animated:(BOOL)arg2;	// IMP=0x0000d477
- (id)derepeaterView;	// IMP=0x0000d491
- (id)derepeaterIdentifier;	// IMP=0x0000d498

@end