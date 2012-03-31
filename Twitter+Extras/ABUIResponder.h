@interface ABUIResponder : NSResponder
{
}

- (BOOL)becomeFirstResponder;	// IMP=0x00005cc5
- (BOOL)resignFirstResponder;	// IMP=0x00005ccf
- (BOOL)acceptsFirstMouse:(id)arg1;	// IMP=0x00005cd9
- (id)menuForEvent:(id)arg1;	// IMP=0x00005ce3
- (BOOL)performKeyAction:(id)arg1;	// IMP=0x00005cea
- (id)initialFirstResponder;	// IMP=0x00005cf1

@end