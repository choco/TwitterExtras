@interface ABUIColor : NSObject
{
    struct CGColor *_cgColor;	// 4 = 0x4
    NSColor *_nsColor;	// 8 = 0x8
}

+ (id)colorWithPatternImage:(id)arg1;	// IMP=0x0000edfb
+ (id)colorWithNSColor:(id)arg1;	// IMP=0x0000ee45
+ (id)colorWithWhite:(float)arg1 alpha:(float)arg2;	// IMP=0x0000eede
+ (id)colorWithRed:(float)arg1 green:(float)arg2 blue:(float)arg3 alpha:(float)arg4;	// IMP=0x0000ef37
+ (id)colorWithCGColor:(struct CGColor *)arg1;	// IMP=0x0000efa6
+ (id)clearColor;	// IMP=0x0000eff0
+ (id)blackColor;	// IMP=0x0000f040
+ (id)darkGrayColor;	// IMP=0x0000f090
+ (id)lightGrayColor;	// IMP=0x0000f0e0
+ (id)whiteColor;	// IMP=0x0000f130
+ (id)grayColor;	// IMP=0x0000f180
+ (id)redColor;	// IMP=0x0000f1d0
+ (id)greenColor;	// IMP=0x0000f230
+ (id)blueColor;	// IMP=0x0000f290
+ (id)cyanColor;	// IMP=0x0000f2f0
+ (id)yellowColor;	// IMP=0x0000f350
+ (id)magentaColor;	// IMP=0x0000f3b0
+ (id)orangeColor;	// IMP=0x0000f410
+ (id)purpleColor;	// IMP=0x0000f470
+ (id)brownColor;	// IMP=0x0000f4d0
+ (id)selectedGradientBottomBlue;	// IMP=0x0000f530
+ (id)graphiteColor;	// IMP=0x0000f590
+ (id)linkColor;	// IMP=0x0000f5f0
+ (id)sidebarBackgroundColor;	// IMP=0x0000f632
+ (id)backgroundSidebarBackgroundColor;	// IMP=0x0000f68d
- (id)initWithWhite:(float)arg1 alpha:(float)arg2;	// IMP=0x0000f6e8
- (id)initWithRed:(float)arg1 green:(float)arg2 blue:(float)arg3 alpha:(float)arg4;	// IMP=0x0000f737
- (id)initWithCGColor:(struct CGColor *)arg1;	// IMP=0x0000faa0
- (id)initWithPatternImage:(id)arg1;	// IMP=0x0000f94e
- (void)dealloc;	// IMP=0x0000f79c
- (struct CGColor *)CGColor;	// IMP=0x0000ed9f
- (void)set;	// IMP=0x0000edc9
- (void)setFill;	// IMP=0x0000f92a
- (void)setStroke;	// IMP=0x0000f906
- (id)colorWithAlphaComponent:(float)arg1;	// IMP=0x0000f8b5
- (id)nsColor;	// IMP=0x0000f804
- (float)alpha;	// IMP=0x0000f7eb

@end