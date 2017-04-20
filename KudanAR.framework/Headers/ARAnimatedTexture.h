#import <Foundation/Foundation.h>
#import <KudanAR/ARPlayableTexture.h>
#import <KudanAR/ARRenderer.h>

/**
 A texture consisting of a series of frames. 
 Each frame added to this texture is played in sequence when the texture is rendered on a material until it the sequence reaches the end, 
 at which point the default behaviour is to loop back to the first frame and start again.
 This behaviour can be disabled if need be, so that the last frame in the sequence is continually rendered once the sequence has finished.
 This is useful for simple 2D animations, akin to a gif or sprite sheet, as transparency is maintained when using .png images.
 */
@interface ARAnimatedTexture : ARPlayableTexture <ARRendererDelegate>

/**
 The total number of frames in this texture's sequence.
 */
@property (nonatomic, readonly) NSUInteger numberOfFrames;

/**
 Adds a new frame to the end of this texture's sequence.
 
 Example of use:
 @code
 ARAnimatedTexture *animatedTexture = [[ARAnimatedTexture alloc] init];
 [animatedTexture addFrameFromImage:image];
 @endcode
 
 @param image The UIImage containing the texture. It should have the same resolution as any previously added images. 
 If lastFramePersist (Inherited from ARPlayableTexture) is set to YES, this will become the frame that gets continually rendered once the sequence has finished.
 */
- (void)addFrameFromImage:(UIImage *)image;

@end
