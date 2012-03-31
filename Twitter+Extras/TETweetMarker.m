//
//  TETweetMarker.m
//  Twitter+Extras
//
//  Created by Enrico Ghirardi on 03/03/12.
//  Copyright (c) 2011 Just a Dream All rights reserved.
//

#import "TETweetMarker.h"

static NSString* const kTweetMarkerBaseURL = @"https://api.tweetmarker.net/v1/lastread?";
#warning TweetMarker won't work without a real api-key!!!! Download the binary version on the project page!
static NSString* const kAPI_KEY = @"Y U NO NEED AN API KEY ?!?!?!?!";
static NSString* const kAuthServiceProviderKey = @"X-Auth-Service-Provider";
static NSString* const kAuthServiceProvider = @"https://api.twitter.com/1/account/verify_credentials.json";
static NSString* const kCredentialsKey = @"X-Verify-Credentials-Authorization";

@implementation TETweetMarker

+ (NSString *)getLastStatusIDForTwitterAccount:(TwitterAccount *)account forCollection:(NSString *)collection
{
    NSError *err;
    NSURL *getURL = [NSURL URLWithString:[NSString stringWithFormat:@"%@collection=%@&username=%@&api_key=%@", kTweetMarkerBaseURL, collection, [account username], kAPI_KEY]];
    NSURLRequest *getRequest = [NSURLRequest requestWithURL:getURL];
    NSData *responseData = [NSURLConnection sendSynchronousRequest:getRequest returningResponse:nil error:&err];
    if (!responseData) {
        NSLog(@"[+] Connection Error: %@", [err localizedDescription]);
    }
    NSString *responseString = [[NSString alloc] initWithData:responseData encoding:NSUTF8StringEncoding];
    NSLog(@"[+] Response: %@", responseString); //just testing if it works
    return [responseString autorelease];
}

+ (BOOL)setLastStatusID:(NSString *)statusID forTwitterAccount:(TwitterAccount *)account forCollection:(NSString *)collection
{    
    Class twitPicCompClientMetaClass = objc_getClass("TwitPicCompatibleImageService");
    id twitPicService = objc_msgSend(twitPicCompClientMetaClass, @selector(service));
    NSString *authHeaders = [twitPicService OAuthEchoAuthorizationHeaderForAccount:account];
    NSURL *postURL = [NSURL URLWithString:[NSString stringWithFormat:@"%@collection=%@&username=%@&api_key=%@", kTweetMarkerBaseURL, collection, [account username], kAPI_KEY]];
    NSMutableURLRequest *postReq = [NSMutableURLRequest requestWithURL:postURL];
    [postReq setValue:kAuthServiceProvider forHTTPHeaderField:kAuthServiceProviderKey];
    [postReq setValue:authHeaders forHTTPHeaderField:kCredentialsKey];
    [postReq setHTTPBody:[statusID dataUsingEncoding:NSASCIIStringEncoding allowLossyConversion:YES]];
    [postReq setHTTPMethod:@"POST"];
    
    NSError *err;
    NSHTTPURLResponse *respCode;
    NSData *responseData = [NSURLConnection sendSynchronousRequest:postReq returningResponse:&respCode error:&err];
    if ((!responseData) || ([respCode statusCode]!=200)) {
        NSLog(@"[+] Connection Error: %@", [err localizedDescription]);
        return NO;
    }
    
    NSString *responseString = [[NSString alloc] initWithData:responseData encoding:NSUTF8StringEncoding];
    NSLog(@"[+] Response: %@", responseString); 
    return YES;
}

@end
