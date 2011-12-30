//
//  Twitter.h
//  Twitter+Extras
//

@interface Twitter : NSObject <NSCoding>
{
    NSMutableArray *accounts;	// 4 = 0x4
    NSTimer *scribeTimer;	// 12 = 0xc
    NSTimer *heartbeatTimer;	// 16 = 0x10
    NSTimer *cachePruningTimer;	// 20 = 0x14
    double clockDelta;	// 24 = 0x18
}

+ (id)sharedTwitter;	// IMP=0x000470b4
- (void)heartbeat:(id)arg1;	// IMP=0x00046d27
- (void)pruneCaches:(id)arg1;	// IMP=0x000470f6
- (id)init;	// IMP=0x000481f9
- (id)initWithCoder:(id)arg1;	// IMP=0x00048000
- (void)encodeWithCoder:(id)arg1;	// IMP=0x00046d81
- (void)dealloc;	// IMP=0x00047d1b
- (void)saveStreams;	// IMP=0x00047200
- (void)shutdown;	// IMP=0x00046cfa
- (id)accounts;	// IMP=0x00046cff
- (void)signInWithUsername:(id)arg1 password:(id)arg2 callback:(id)arg3;	// IMP=0x00047f17
- (void)didSignIn:(id)arg1 info:(id)arg2;	// IMP=0x00047e07
- (void)addAccount:(id)arg1;	// IMP=0x00046dfc
- (void)removeAccount:(id)arg1;	// IMP=0x00046e96
- (BOOL)containsAccount:(id)arg1;	// IMP=0x00046ed3
- (id)accountWithUsername:(id)arg1;	// IMP=0x000472ea
- (id)defaultAccount;	// IMP=0x00046f00
- (void)reorderAccountFromIndex:(long)arg1 toIndex:(long)arg2;	// IMP=0x00046f4a
- (void)flushScribe:(id)arg1;	// IMP=0x00047013
- (void)flushScribeInBackground;	// IMP=0x00047431
- (id)duckie;	// IMP=0x00047044
- (void)refresh;	// IMP=0x00047557
- (BOOL)hasFreshMessages;	// IMP=0x00047690
- (BOOL)hasFreshAnythingApplicableToStatusItem;	// IMP=0x0004778c
- (BOOL)hasFreshAnythingApplicableToDockBadge;	// IMP=0x00047888
- (BOOL)hasAnythingUnread;	// IMP=0x00047984
- (void)markAllAsRead;	// IMP=0x00047087
- (id)cachedUsers;	// IMP=0x00047a80
- (BOOL)canBlock:(id)arg1;	// IMP=0x00047bbb
- (double)clockDelta;	// IMP=0x00046d0a
- (void)setClockDelta:(double)arg1;	// IMP=0x00046d15

@end