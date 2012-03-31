//
//  ABImageService.h
//  Twitter+Extras
//

@interface ABImageService : NSObject
{
}

+ (id)service;	// IMP=0x00033d85
+ (id)fullSizeImageURLForURL:(id)arg1;	// IMP=0x00033dc8
+ (id)thumbnailImageURLForURL:(id)arg1;	// IMP=0x00033f55
+ (BOOL)isImageServiceLink:(id)arg1;	// IMP=0x000340bf
+ (BOOL)entitiesMightContainMedia:(id)arg1;	// IMP=0x0003559a
+ (BOOL)stringMightContainMedia:(id)arg1;	// IMP=0x000341d0
+ (id)isVideoServiceLink:(id)arg1;	// IMP=0x00034384
+ (BOOL)isMediaLink:(id)arg1;	// IMP=0x00034426
+ (BOOL)isHotLink:(id)arg1;	// IMP=0x00034478
+ (BOOL)isYFrogImageLink:(id)arg1;	// IMP=0x0003450f
+ (BOOL)isTwitPicLink:(id)arg1;	// IMP=0x000345fe
+ (BOOL)isTwitgooLink:(id)arg1;	// IMP=0x00034697
+ (BOOL)isImglyLink:(id)arg1;	// IMP=0x000346b2
+ (BOOL)isPixImLink:(id)arg1;	// IMP=0x000346cd
+ (BOOL)isTweetphotoLink:(id)arg1;	// IMP=0x000346e8
+ (BOOL)isPikchurLink:(id)arg1;	// IMP=0x00034703
+ (BOOL)isMobypictureLink:(id)arg1;	// IMP=0x0003471e
+ (id)currentService;	// IMP=0x00034739
+ (long)approximateImageLinkLength;	// IMP=0x00034837
+ (long)approximateVideoLinkLength;	// IMP=0x00034918
+ (void)postImage:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;	// IMP=0x00034938
+ (id)currentVideoService;	// IMP=0x00034985
+ (void)postVideo:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;	// IMP=0x00034a02
- (void)postImage:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;	// IMP=0x00033d3e
- (void)postVideo:(id)arg1 associatedMessage:(id)arg2 fromAccount:(id)arg3 callback:(id)arg4;	// IMP=0x00033d55

@end