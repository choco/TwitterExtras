#import "ABUIResponder.h"

@interface ABUIView : ABUIResponder
{
    int _tag;	// 12 = 0xc
    NSArray *_textRenderers;	// 16 = 0x10
    id _currentTextRenderer;	// 20 = 0x14
    struct CGPoint startDrag;	// 24 = 0x18
    id drawRect;	// 36 = 0x24
    id layout;	// 40 = 0x28
    NSString *toolTip;	// 44 = 0x2c
    double toolTipDelay;	// 48 = 0x30
    struct {
        int lastWidth;
        int lastHeight;
        char lastOpaque;
        struct CGContext *context;
    } _context;	// 60 = 0x3c
    struct {
        unsigned int userInteractionDisabled:1;
        unsigned int moveWindowByDragging:1;
        unsigned int resizeWindowByDragging:1;
        unsigned int didStartMovingByDragging:1;
        unsigned int didStartResizeByDragging:1;
        unsigned int disableSubpixelTextRendering:1;
        unsigned int pasteboardDraggingEnabled:1;
        unsigned int pasteboardDraggingIsDragging:1;
        unsigned int dragDistanceLock:1;
        unsigned int delegateMouseEntered:1;
        unsigned int delegateMouseExited:1;
        unsigned int delegateWillDisplayLayer:1;
    } _viewFlags;	// 76 = 0x4c
}

+ (void)initialize;	// IMP=0x0000614b
+ (Class)layerClass;	// IMP=0x0000629a
- (void)dealloc;	// IMP=0x00007524
- (id)initWithFrame:(struct CGRect)arg1;	// IMP=0x00007d10
- (id)layer;	// IMP=0x00005efe
- (void)setLayer:(id)arg1;	// IMP=0x00005fb6
- (long)tag;	// IMP=0x00005cf9
- (void)setTag:(long)arg1;	// IMP=0x00005d04
- (BOOL)isUserInteractionEnabled;	// IMP=0x00005d12
- (void)setUserInteractionEnabled:(BOOL)arg1;	// IMP=0x00005d24
- (BOOL)moveWindowByDragging;	// IMP=0x00005d46
- (void)setMoveWindowByDragging:(BOOL)arg1;	// IMP=0x00005d57
- (BOOL)resizeWindowByDragging;	// IMP=0x00005d77
- (void)setResizeWindowByDragging:(BOOL)arg1;	// IMP=0x00005d89
- (BOOL)subpixelTextRenderingEnabled;	// IMP=0x00005daa
- (void)setSubpixelTextRenderingEnabled:(BOOL)arg1;	// IMP=0x00005dbf
- (id)viewDelegate;	// IMP=0x00005de4
- (void)setViewDelegate:(id)arg1;	// IMP=0x00005ff2
- (BOOL)_disableDrawRect;	// IMP=0x00005def
- (struct CGContext *)_CGContext;	// IMP=0x00007c20
- (void)displayLayer:(id)arg1;	// IMP=0x000077f5
- (void)_blockLayout;	// IMP=0x0000767c
- (void)setLayout:(id)arg1;	// IMP=0x000060b3
- (void)layoutSublayersOfLayer:(id)arg1;	// IMP=0x00006119
- (double)toolTipDelay;	// IMP=0x00005df6
- (void)setToolTipDelay:(double)arg1;	// IMP=0x00005e01
- (id)toolTip;	// IMP=0x00005e13
- (void)setToolTip:(id)arg1;	// IMP=0x00007640
- (id)layout;	// IMP=0x00005e1e
- (id)drawRect;	// IMP=0x00005e29
- (void)setDrawRect:(id)arg1;	// IMP=0x00007604

@end

@interface ABUIView (ABUIViewHierarchy)
- (id)superview;	// IMP=0x000065d8
- (id)subviews;	// IMP=0x0000661b
- (long)deepNumberOfSubviews;	// IMP=0x00008389
- (void)setSubviews:(id)arg1;	// IMP=0x000084c6
- (void)_cleanupResponderChain;	// IMP=0x00006668
- (void)removeFromSuperview;	// IMP=0x00006747
- (BOOL)_canRespondToEvents;	// IMP=0x0000680e
- (void)keyDown:(id)arg1;	// IMP=0x00006850
- (BOOL)performKeyEquivalent:(id)arg1;	// IMP=0x00008761
- (void)setNextResponder:(id)arg1;	// IMP=0x00007d7f
- (void)addSubview:(id)arg1;	// IMP=0x00006964
- (void)insertSubview:(id)arg1 atIndex:(long)arg2;	// IMP=0x00006a59
- (void)insertSubview:(id)arg1 belowSubview:(id)arg2;	// IMP=0x00006b5c
- (void)insertSubview:(id)arg1 aboveSubview:(id)arg2;	// IMP=0x00006c72
- (id)_topSubview;	// IMP=0x00006d88
- (id)_bottomSubview;	// IMP=0x00006db9
- (void)bringSubviewToFront:(id)arg1;	// IMP=0x00006e1f
- (void)sendSubviewToBack:(id)arg1;	// IMP=0x00006ed0
- (void)willMoveToWindow:(id)arg1;	// IMP=0x00005e34
- (void)didMoveToWindow;	// IMP=0x00005e39
- (void)didAddSubview:(id)arg1;	// IMP=0x00005e3e
- (void)willRemoveSubview:(id)arg1;	// IMP=0x00005e43
- (void)willMoveToSuperview:(id)arg1;	// IMP=0x00005e48
- (void)didMoveToSuperview;	// IMP=0x00005e4d
- (BOOL)isDescendantOfView:(id)arg1;	// IMP=0x00006f81
- (id)viewWithTag:(long)arg1;	// IMP=0x0000892b
- (id)firstSuperviewOfClass:(Class)arg1;	// IMP=0x00006fb7
- (void)setNeedsLayout;	// IMP=0x00007010
- (void)layoutIfNeeded;	// IMP=0x00007041
- (void)layoutSubviews;	// IMP=0x00005e52
@end

@interface ABUIView (ABUIViewRendering)
- (void)redraw;	// IMP=0x00007072
- (void)drawRect:(struct CGRect)arg1;	// IMP=0x00008d6f
- (void)setDrawRect:(id)arg1;	// IMP=0x00007101
- (void)setEverythingNeedsDisplay;	// IMP=0x0000714e
- (void)setNeedsDisplay;	// IMP=0x0000719c
- (void)setNeedsDisplayInRect:(struct CGRect)arg1;	// IMP=0x000071cd
- (BOOL)clipsToBounds;	// IMP=0x00007214
- (void)setClipsToBounds:(BOOL)arg1;	// IMP=0x00007248
- (float)alpha;	// IMP=0x00008ca1
- (void)setAlpha:(float)arg1;	// IMP=0x00007281
- (BOOL)isOpaque;	// IMP=0x000072bd
- (void)setOpaque:(BOOL)arg1;	// IMP=0x000072f1
- (BOOL)isHidden;	// IMP=0x0000732a
- (void)setHidden:(BOOL)arg1;	// IMP=0x0000735e
- (id)backgroundColor;	// IMP=0x00007397
- (void)setBackgroundColor:(id)arg1;	// IMP=0x00008cd2
@end
