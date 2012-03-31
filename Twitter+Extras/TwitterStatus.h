//
//  TwitterStatus.h
//  Twitter+Extras
//

#import "TwitterUser.h"

@interface TwitterStatus : NSObject
{
    NSDate *lastUpdated;	// 4 = 0x4
    NSString *statusID;	// 8 = 0x8
    NSString *originalText;	// 12 = 0xc
    NSString *text;	// 16 = 0x10
    NSString *displayText;	// 20 = 0x14
    NSString *source;	// 24 = 0x18
    //ABActiveTextRanges *originalTextRanges;	// 28 = 0x1c
    //ABActiveTextRanges *activeTextRanges;	// 32 = 0x20
    NSArray *displayTextRanges;	// 36 = 0x24
    NSDate *date;	// 40 = 0x28
    NSDate *fakeDate;	// 44 = 0x2c
    TwitterUser *fromUser;	// 48 = 0x30
    NSMutableArray *contributors;	// 52 = 0x34
    NSString *inReplyToStatusID;	// 56 = 0x38
    //GeoRSSPoint *location;	// 60 = 0x3c
    //TwitterPlace *place;	// 64 = 0x40
    TwitterStatus *retweetedStatus;	// 68 = 0x44
    TwitterStatus *retweetingStatus;	// 72 = 0x48
    int recentRetweets;	// 76 = 0x4c
    //TwitterEntitySet *entities;	// 80 = 0x50
    struct {
        NSArray *links;
        NSString *sourceName;
        NSString *sourceLink;
        NSString *accessibilityText;
    } _derived;	// 84 = 0x54
    struct {
        unsigned short _476;
    } _height;	// 100 = 0x64
    struct {
        unsigned int didPrepare:1;
        unsigned int isPartialStatus:1;
        unsigned int isRead:1;
        unsigned int wasSeen:1;
        unsigned int didGlobalNotification:1;
        unsigned int containsMedia:1;
        unsigned int containsMusic:1;
        unsigned int containsRED:1;
        unsigned int contains4SQ:1;
        unsigned int mentionsLoadingAccount:1;
        unsigned int favoritedByLoadingAccount:1;
        unsigned int searchResultType:2;
        unsigned int isPromoted:1;
        unsigned int hasRecordedImpression:1;
    } _flags;	// 104 = 0x68
}

+ (id)statusWithDictionary:(id)arg1;	// IMP=0x00065ffa
+ (id)statusWithXML:(id)arg1;	// IMP=0x00066f29
+ (id)statusWithJSON:(id)arg1;	// IMP=0x00066e73
+ (id)statusesWithXML:(id)arg1;	// IMP=0x00066dd6
+ (id)promotedStatusesWithJSON:(id)arg1;	// IMP=0x00066d39
+ (id)statusesWithJSON:(id)arg1;	// IMP=0x00066c9c
+ (id)statusesWithSearchJSON:(id)arg1;	// IMP=0x00066bff
- (void)setHasRecordedImpression:(BOOL)arg1;	// IMP=0x000646c3
- (BOOL)hasRecordedImpression;	// IMP=0x000646e6
- (id)originalText;	// IMP=0x000649cb
- (void)_parseEntities;	// IMP=0x0006605e
- (id)entities;	// IMP=0x00064a51
- (void)parseDictionary:(id)arg1;	// IMP=0x00064a75
- (id)init;	// IMP=0x00066b82
- (void)dealloc;	// IMP=0x000676f8
- (id)description;	// IMP=0x00064e47
- (unsigned long)hash;	// IMP=0x00064eb6
- (BOOL)isEqual:(id)arg1;	// IMP=0x00064ed9
- (id)comparableDate;	// IMP=0x00064f9a
- (long)compare:(id)arg1;	// IMP=0x00064ff8
- (void)_assimilateStatus:(id)arg1;	// IMP=0x000650c0
- (void)assimilateStatus:(id)arg1;	// IMP=0x00065330
- (int)buoyancy;	// IMP=0x000646f8
- (BOOL)isPromoted;	// IMP=0x0006470a
- (BOOL)isPopular;	// IMP=0x0006471c
- (BOOL)isNotPromoted;	// IMP=0x00064735
- (NSString *)text;	// IMP=0x00065416
- (id)displayText;	// IMP=0x00065458
- (void)_renderDisplayText;	// IMP=0x00067399
- (id)originalTextRanges;	// IMP=0x000654b5
- (id)activeTextRanges;	// IMP=0x00065517
- (void)_updateFlags;	// IMP=0x00065579
- (void)_renderAccessibilityText;	// IMP=0x000656e1
- (void)_prepare;	// IMP=0x00065784
- (id)accessibilityText;	// IMP=0x0006474a
- (void)setText:(id)arg1;	// IMP=0x000658df
- (void)setEntities:(id)arg1;	// IMP=0x0006593b
- (BOOL)isPartialStatus;	// IMP=0x00064755
- (void)setIsPartialStatus:(BOOL)arg1;	// IMP=0x00064766
- (BOOL)isRead;	// IMP=0x00064786
- (void)setIsRead:(BOOL)arg1;	// IMP=0x00064798
- (BOOL)wasSeen;	// IMP=0x000647b9
- (void)setWasSeen:(BOOL)arg1;	// IMP=0x000647cb
- (id)twitterURL;	// IMP=0x00065979
- (BOOL)isNotADummyStatus;	// IMP=0x000647ec
- (BOOL)didGlobalNotification;	// IMP=0x000647f6
- (void)setDidGlobalNotification:(BOOL)arg1;	// IMP=0x00064808
- (BOOL)containsMedia;	// IMP=0x00064829
- (BOOL)isMusicLink;	// IMP=0x0006483b
- (BOOL)containsRED;	// IMP=0x0006484d
- (BOOL)contains4SQ;	// IMP=0x0006485f
- (BOOL)favoritedByLoadingAccount;	// IMP=0x00064871
- (BOOL)mentionsLoadingAccount;	// IMP=0x00064883
- (BOOL)isRetweet;	// IMP=0x00064895
- (BOOL)hasSubtext;	// IMP=0x000648a7
- (BOOL)isGap;	// IMP=0x000648d3
- (id)retweetedBy;	// IMP=0x00065a20
- (id)representedStatus;	// IMP=0x000648da
- (int)searchResultType;	// IMP=0x000648ea
- (void)setSearchResultType:(int)arg1;	// IMP=0x000648fc
- (BOOL)matchesSearchString:(id)arg1;	// IMP=0x00065a43
- (id)arrayOfStringsForRanges:(id)arg1 inString:(id)arg2 chopLeading:(id)arg3;	// IMP=0x000669de
- (id)links;	// IMP=0x00065ac3
- (id)usernames;	// IMP=0x00065b49
- (id)hashtags;	// IMP=0x00065bb3
- (void)_parseSource;	// IMP=0x000672ec
- (void)parseSourceXML:(id)arg1 info:(id)arg2;	// IMP=0x00065c1d
- (id)sourceName;	// IMP=0x00065d5d
- (id)sourceLink;	// IMP=0x00065d88
- (id)inReplyToUsername;	// IMP=0x00065db2
- (id)displayTextRanges;	// IMP=0x00065e07
- (void)setDisplayText:(id)arg1;	// IMP=0x000672b0
- (long)recentRetweets;	// IMP=0x00064920
- (void)setRecentRetweets:(long)arg1;	// IMP=0x0006492b
- (void)setOriginalText:(id)arg1;	// IMP=0x00067274
- (id)retweetingStatus;	// IMP=0x00064939
- (void)setRetweetingStatus:(id)arg1;	// IMP=0x00064944
- (TwitterStatus *)retweetedStatus;	// IMP=0x00064952
- (void)setRetweetedStatus:(id)arg1;	// IMP=0x00067238
- (id)place;	// IMP=0x0006495d
- (void)setPlace:(id)arg1;	// IMP=0x000671fc
- (id)location;	// IMP=0x00064968
- (void)setLocation:(id)arg1;	// IMP=0x000671c0
- (id)inReplyToStatusID;	// IMP=0x00064973
- (void)setInReplyToStatusID:(id)arg1;	// IMP=0x00067184
- (id)contributors;	// IMP=0x0006497e
- (void)setContributors:(id)arg1;	// IMP=0x00067148
- (TwitterUser *)fromUser;	// IMP=0x00064989
- (void)setFromUser:(id)arg1;	// IMP=0x0006710c
- (id)fakeDate;	// IMP=0x00064994
- (void)setFakeDate:(id)arg1;	// IMP=0x000670d0
- (id)date;	// IMP=0x0006499f
- (void)setDate:(id)arg1;	// IMP=0x00067094
- (id)statusID;	// IMP=0x000649aa
- (void)setStatusID:(id)arg1;	// IMP=0x00067058
- (id)source;	// IMP=0x000649b5
- (void)setSource:(id)arg1;	// IMP=0x0006701c
- (id)lastUpdated;	// IMP=0x000649c0
- (void)setLastUpdated:(id)arg1;	// IMP=0x00066fe0

@end