#import <Foundation/Foundation.h>
#import <KudanAR/ARMaterial.h>

@class ARTexture;

/**
 An ARTextureMaterial is a material for shading a texture. This is commonly used with 3D models that do not require dynamic lighting.
 */
@interface ARTextureMaterial : ARMaterial

/**
 The main texture displayed on the material.
 */
@property (nonatomic) ARTexture *texture;

/**
 The blend texture is a secondary texture with an inverted alpha value. It blends with the colour texture based on the blend parameter.
 The level of transparency for both the main and blend textures depends on the blend parameter. If the blend parameter is 0, the renderer will draw only the main texture. If the blend parameter is 1, the renderer will draw only the blend texture. Anything in between displays both textures at varying degrees of transparency.
 */
@property (nonatomic) ARTexture *blendTexture;

/**
 Initialise with an existing ARTexture.
 
 Example of use:
 @code
 ARTexture *texture = [[ARTexture alloc] initWithUIImage:[UIImage imageNamed:@"example.jpg"]];
 ARTextureMaterial *textureMaterial = [[ARTextureMaterial alloc] initWithTexture:texture];
 @endcode
 
 @param texture The texture to initialise with.
 
 @return The material, initialised with the texture.
 */
- (instancetype)initWithTexture:(ARTexture *)texture;

/**
 Class method to create an instance of an ARTextureMaterial using an ARTexture.
 
 Example of use:
 @code
 ARTexture *texture = [[ARTexture alloc] initWithUIImage:[UIImage imageNamed:@"example.jpg"]];
 ARTextureMaterial *textureMaterial = [ARTextureMaterial materialWithTexture:texture];
 @endcode
 
 @param texture The texture to initialise with.
 @return The initialised material.
 */
+ (instancetype)materialwithTexture:(ARTexture *)texture;

/**
 The alpha factor. Combine with the texture sample to alter transparency. Range is 0..1, where 0 is fully transparent and 1 is fully opaque. Default value is 1.
 */
@property (nonatomic) float alpha;

/**
 The blend parameter. Mixes blendTexture with texture based on value. Range is 0..1, where 0 is only the main texture and 1 is only the blend texture. Default value is 0.
 */
@property (nonatomic) float blendParameter;

@end
