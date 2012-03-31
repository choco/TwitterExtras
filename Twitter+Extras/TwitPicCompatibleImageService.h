//
//  TwitPicCompatibleImageService.h
//  Twitter+Extras
//

#import "ABImageService.h"

@interface TwitPicCompatibleImageService : ABImageService
{
}

+ (id)identifierForURL:(id)arg1 base:(id)arg2;	// IMP=0x00034b05
- (id)apiRoot;	// IMP=0x00033d6c
- (id)apiKey;	// IMP=0x00033b9c
- (id)apiKeyParameterName;	// IMP=0x00033ba3
- (id)mediaParameterName;	// IMP=0x00033bad
- (id)mediaURLResponseTag;	// IMP=0x00033bb7
- (id)messageParameterName;	// IMP=0x00033bc1
- (BOOL)useBasicAuth;	// IMP=0x00033bc8
- (BOOL)useOAuthEcho;	// IMP=0x00033bcf
- (id)OAuthEchoServiceProvider;	// IMP=0x00033bd9
- (id)OAuthEchoAuthorizationHeaderForAccount:(id)arg1;	// IMP=0x0003556c
- (void)addMoarStuff:(id)arg1;	// IMP=0x00033be3
- (BOOL)OAuthEchoInPOST;	// IMP=0x00033be8
- (void)postImage:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;	// IMP=0x000358d8
- (void)postVideo:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;	// IMP=0x00035c4f
- (void)didPostImage:(id)arg1 info:(id)arg2;	// IMP=0x00036014
- (void)parseYFrogXML:(id)arg1 info:(id)arg2;	// IMP=0x00034a4f

@end