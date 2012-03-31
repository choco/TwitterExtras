#import "ABUIView.h"
#import "ABUIImage.h"

@interface ABUIImageView : ABUIView
{
    ABUIImage *_image;	// 80 = 0x50
}

- (id)initWithImage:(id)arg1;	// IMP=0x00012744
- (void)dealloc;	// IMP=0x00012809
- (id)image;	// IMP=0x00012739
- (void)setImage:(id)arg1;	// IMP=0x000127ba
- (void)drawRect:(struct CGRect)arg1;	// IMP=0x0001284d

@end