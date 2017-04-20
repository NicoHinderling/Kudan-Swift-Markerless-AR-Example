#import <Foundation/Foundation.h>
#import <KudanAR/ARRenderer.h>

@class ARNode;

/**
 A material represents how an object is shaded. This serves as a base class and shouldn't be created directly.
 */
@interface ARMaterial : NSObject

/**
 Method called after this material has been used to render an object. This can be useful for playable textures if you wish to check their updated state.
 */
- (void)postRender;

/**
 The material's name, this is automatically set during the model importer process.
 **/
@property (nonatomic) NSString *name;

/**
 Whether this material involves transparency. Default is NO.
 */
@property (nonatomic) BOOL isTranslucent;

/**
 The blend mode to use with this material. 
 If transparency is enabled, the ARBlendMode will control how the renderer blends the object it is drawing with the framebuffer, based on its alpha value.
 */
@property (nonatomic) ARBlendMode blendMode;

/**
 Whether pixels rendered with this material should be depth tested against existing pixels in the framebuffer. Default is YES.
 */
@property (nonatomic) BOOL depthTest;

/**
 Whether pixels rendered with this material should generate depth information in the framebuffer. Default is YES.
 */
@property (nonatomic) BOOL depthWrite;

/**
 Whether to write to the colour buffer. If NO, only depth information will be written. Default is YES.
 */
@property (nonatomic) BOOL colourWrite;

/**
 The face culling mode. Default is ARFaceCullModeBack.
 */
@property (nonatomic) ARFaceCullMode cullMode;


@end
