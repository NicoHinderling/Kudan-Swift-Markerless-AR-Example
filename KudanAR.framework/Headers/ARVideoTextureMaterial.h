#import <KudanAR/ARTextureMaterial.h>

@class ARVideoTexture;

/**
 An ARVideoTextureMaterial is a material designed specifically for use with an ARVideoTexture. It provides extra properties unique to ARVideoTextures, including alpha transparency and fade time.
 */
@interface ARVideoTextureMaterial : ARMaterial

/**
 The video texture to be rendered.
 **/
@property (nonatomic) ARVideoTexture *texture;

/**
 Initialise ARVideoTextureMaterial with video texture.
 
 @param texture  The video texture to be rendered.
 **/
- (instancetype)initWithTexture:(ARVideoTexture *)texture;

/**
 Initialise ARVideoTextureMaterial with video texture class method.
 
 @param texture  The video texture to be rendered.
 **/
+ (instancetype)materialwithTexture:(ARVideoTexture *)texture;

/**
 The transparency of the video. 0..1 with 0 being fully transparent and 1 being fully opaque.
 */
@property (nonatomic) float alpha;

/**
 The time in seconds in which to fade the video in. This takes control of the alpha property. Default is 0 seconds.
 */
@property (nonatomic) float fadeInTime;

@end
