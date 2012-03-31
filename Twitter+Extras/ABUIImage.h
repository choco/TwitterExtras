@interface ABUIImage : NSObject
{
    struct CGImage *_imageRef;	// 4 = 0x4
}

+ (id)_imageWithABImage:(id)arg1;	// IMP=0x0000fe29
+ (id)imageNamed:(id)arg1 cache:(BOOL)arg2;	// IMP=0x0000fd0c
+ (id)imageNamed:(id)arg1;	// IMP=0x0000fcde
+ (id)imageWithData:(id)arg1;	// IMP=0x0000fc4f
+ (id)imageWithCGImage:(struct CGImage *)arg1;	// IMP=0x0000fc05
- (id)initWithCGImage:(struct CGImage *)arg1;	// IMP=0x0000fbbc
- (void)dealloc;	// IMP=0x0001014a
- (struct CGSize)size;	// IMP=0x000100ea
- (struct CGImage *)CGImage;	// IMP=0x0000fb8d
- (void)drawAtPoint:(struct CGPoint)arg1;	// IMP=0x000100a5
- (void)drawAtPoint:(struct CGPoint)arg1 blendMode:(int)arg2 alpha:(float)arg3;	// IMP=0x00010031
- (void)drawInRect:(struct CGRect)arg1;	// IMP=0x0000ffec
- (void)drawInRect:(struct CGRect)arg1 blendMode:(int)arg2 alpha:(float)arg3;	// IMP=0x0000ff72
- (long)leftCapWidth;	// IMP=0x0000fb98
- (long)topCapHeight;	// IMP=0x0000fb9f
- (id)stretchableImageWithLeftCapWidth:(long)arg1 topCapHeight:(long)arg2;	// IMP=0x0000ff37
- (id)dataRepresentationForType:(id)arg1 compression:(float)arg2;	// IMP=0x0000fe61

@end