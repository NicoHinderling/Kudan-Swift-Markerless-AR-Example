#import <Foundation/Foundation.h>
#import <KudanAR/ARTexture.h>

@class ARPlayableTexture;


/**
 A protocol for playable texture events.
 */
@protocol ARPlayableTextureDelegate <NSObject>

@required
@optional
/**
 Method called when the playable texture finishes.
 
 @param texture The playable texture that finished.
 */
- (void)playableTextureDidFinish:(ARPlayableTexture *)texture;

@end

/**
 This class represents textures that are capable of changing, such as videos or 2D animations. This class should not be used directly.
 For Animations, please use ARAnimatedTexture.
 For Videos and Alpha Videos, please use ARVideoTexture.
 */
@interface ARPlayableTexture : ARTexture

/**
 The frame rate of the playable texture. This is set automatically but can be set manually in order to change playback speed.
 */
@property (nonatomic) float frameRate;

/**
 Resets the playable texture back to the beginning of its sequence.
 */
- (void)reset;

/**
 Start playback of the playable texture.
 */
- (void)play;

/**
 Pause playback of the playable texture.
 */
- (void)pause;

/** 
 An enum representing the current state of a playable texture
 **/
typedef NS_ENUM(NSInteger, ARPlayableTextureState) {
    ARPlayableTextureStateUninitialised, ///< Playable texture is not initialised
    ARPlayableTextureStatePaused, ///< Playable texture is paused
    ARPlayableTextureStatePlaying, ///< Playable texture is playing
    ARPlayableTextureStateFinished, ///< Playable texture has finished playing 
};

@property (nonatomic) ARPlayableTextureState playState;

/**
 The amount of time, in seconds, where the texture will continue to play even if it is not visible and no frames are being rendered. This is useful for momentary losses of tracking. The recommended value is 0.5 seconds.
 */
@property (nonatomic) NSTimeInterval pauseTolerance;

/**
 The amount of time, in seconds, to wait before resetting to the beginning, if the node is not being rendered. A value of 0 means the video will not reset.
 */
@property (nonatomic) NSTimeInterval resetThreshold;

/**
 Whether or not to continually render the last frame after the playable texture has finished playing. Default is NO.
 */
@property (nonatomic) BOOL lastFramePersist;

/**
 Delegate to receive playable texture events. Currently, the only delegate is playableTextureDidFinish.
 */
@property (nonatomic, weak) id<ARPlayableTextureDelegate> delegate;

@end
