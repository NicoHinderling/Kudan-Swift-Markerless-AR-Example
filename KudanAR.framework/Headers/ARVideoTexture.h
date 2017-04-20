#import <Foundation/Foundation.h>
#import <KudanAR/ARPlayableTexture.h>
#import <KudanAR/ARRenderer.h>
#import <AVFoundation/AVFoundation.h>

/**
 A class representing the texture used to render videos.
 **/
@interface ARVideoTexture : ARPlayableTexture <ARRendererDelegate, AVAudioPlayerDelegate, NSCopying>

/**
 Initialises video texture with audio file.
 
 @param videoFile Video name and extension in bundle.
 @param audioFile Video's audio track name and extension in bundle.
 **/
- (instancetype)initWithVideoFile:(NSString *)videoFile audioFile:(NSString *)audioFile;

/**
 If video is active.
 **/
@property (nonatomic) BOOL isActive;

/**
 Current video time in seconds.
 **/
@property (nonatomic) double currentVideoTime;

/**
 Time of last frame rendered in seconds.
 **/
@property (nonatomic) double lastRenderTime;

/**
 Removes video texture from cache.
 **/
- (void)spill;

/**
 Adds video texture to video manager. If there's no room spills the oldest video texture. Video manager can hold 3 video textures at once.
 **/
- (void)activate;

@end
