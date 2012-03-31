//
//  TwitterUser.h
//  Twitter+Extras
//

@interface TwitterUser : NSObject
{
    NSDate *lastUpdated;	// 4 = 0x4
    NSString *userID;	// 8 = 0x8
    NSString *username;	// 12 = 0xc
    NSURL *profileImageURL;	// 16 = 0x10
    NSString *fullName;	// 20 = 0x14
    NSString *location;	// 24 = 0x18
    NSString *bio;	// 28 = 0x1c
    NSURL *url;	// 32 = 0x20
    NSURL *expandedURL;	// 36 = 0x24
    NSNumber *protected;	// 40 = 0x28
    NSNumber *verified;	// 44 = 0x2c
    NSNumber *numberOfFollowers;	// 48 = 0x30
    NSNumber *numberOfStatuses;	// 52 = 0x34
    NSNumber *numberOfFollowing;	// 56 = 0x38
    NSNumber *numberOfFavorites;	// 60 = 0x3c
    NSDate *createdAt;	// 64 = 0x40
    NSNumber *following;	// 68 = 0x44
}

- (void)_assimilateUser:(id)arg1;	// IMP=0x0006c0b8
- (void)assimilateUser:(id)arg1;	// IMP=0x0006bf68
- (id)description;	// IMP=0x0006bf0e
- (id)fullName;	// IMP=0x0006ad31
- (long)compare:(id)arg1;	// IMP=0x0006be9d
- (long)compareByLastUpdated:(id)arg1;	// IMP=0x0006be50
- (unsigned long)hash;	// IMP=0x0006be2d
- (BOOL)isEqual:(id)arg1;	// IMP=0x0006bd2a
- (id)largeProfileImageURL;	// IMP=0x0006bcaa
- (BOOL)isPartialUser;	// IMP=0x0006ad43
- (void)setIsPartialUser:(BOOL)arg1;	// IMP=0x0006ad53
- (id)lowercaseUsername;	// IMP=0x0006bc87
- (BOOL)isNotADummyUser;	// IMP=0x0006ad6b
- (id)searchSpace;	// IMP=0x0006bc38
- (BOOL)matchesSearchString:(id)arg1;	// IMP=0x0006bbfd
- (id)twitterURL;	// IMP=0x0006bb88
- (id)following;	// IMP=0x0006ad75
- (void)setFollowing:(id)arg1;	// IMP=0x0006bb4c
- (id)createdAt;	// IMP=0x0006ad80
- (void)setCreatedAt:(id)arg1;	// IMP=0x0006bb10
- (id)numberOfFavorites;	// IMP=0x0006ad8b
- (void)setNumberOfFavorites:(id)arg1;	// IMP=0x0006bad4
- (id)numberOfFollowing;	// IMP=0x0006ad96
- (void)setNumberOfFollowing:(id)arg1;	// IMP=0x0006ba98
- (id)numberOfStatuses;	// IMP=0x0006ada1
- (void)setNumberOfStatuses:(id)arg1;	// IMP=0x0006ba5c
- (id)numberOfFollowers;	// IMP=0x0006adac
- (void)setNumberOfFollowers:(id)arg1;	// IMP=0x0006ba20
- (id)verified;	// IMP=0x0006adb7
- (void)setVerified:(id)arg1;	// IMP=0x0006b9e4
- (id)protected;	// IMP=0x0006adc2
- (void)setProtected:(id)arg1;	// IMP=0x0006b9a8
- (id)expandedURL;	// IMP=0x0006adcd
- (void)setExpandedURL:(id)arg1;	// IMP=0x0006b96c
- (id)url;	// IMP=0x0006add8
- (void)setUrl:(id)arg1;	// IMP=0x0006b930
- (id)bio;	// IMP=0x0006ade3
- (void)setBio:(id)arg1;	// IMP=0x0006b8f4
- (id)location;	// IMP=0x0006adee
- (void)setLocation:(id)arg1;	// IMP=0x0006b8b8
- (void)setFullName:(id)arg1;	// IMP=0x0006b87c
- (id)profileImageURL;	// IMP=0x0006adf9
- (void)setProfileImageURL:(id)arg1;	// IMP=0x0006b840
- (NSString *)username;	// IMP=0x0006ae04
- (void)setUsername:(id)arg1;	// IMP=0x0006b804
- (id)userID;	// IMP=0x0006ae0f
- (void)setUserID:(id)arg1;	// IMP=0x0006b7c8
- (id)lastUpdated;	// IMP=0x0006ae1a
- (void)setLastUpdated:(id)arg1;	// IMP=0x0006b78c

@end