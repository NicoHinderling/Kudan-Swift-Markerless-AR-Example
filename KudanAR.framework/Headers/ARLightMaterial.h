#import <Foundation/Foundation.h>
#import <KudanAR/ARMaterial.h>

@class ARTextureCube;
@class ARMaterialProperty;
@class ARMaterialPropertyReflection;

/**
 An ARLightMaterial is a material for shading using dynamic lighting. This is most commonly used with 3D models.
 
 Example of use:
 @code
 ARLightMaterial *lightMaterial = [[ARLightMaterial alloc] init];
 lightMaterial.colour.value = [ARVector3 vectorWithValuesX:1 Y:1 Z:1];
 lightMaterial.diffuse.texture = [[ARTexture alloc] initWithUIImage: [UIImage imageNamed:@"example.jpg"]];
 lightMaterial.ambient.value = [ARVector3 vectorWithValuesX:0.2 Y:0.2 Z:0.2];
 lightMaterial.normal.texture = [[ARTexture alloc] initWithUIImage: [UIImage imageNamed:@"exampleNormal.jpg"]];
 @endcode
 */
@interface ARLightMaterial : ARMaterial

/**
 The base colour of the material, settable via either a vector or with a texture.
 */
@property (nonatomic) ARMaterialProperty *colour;

/**
 The blend texture is a secondary texture with an inverted alpha value. It blends with the colour texture based on the blend parameter.
 The level of transparency for both the main and blend textures depends on the blend parameter. If the blend parameter is 0, the renderer will draw only the main texture. If the blend parameter is 1, the renderer will draw only the blend texture. Anything in between displays both textures at varying degrees of transparency.
 
 Only used when colour.texture is set.
 */
@property (nonatomic) ARTexture *blendTexture;

/**
 The diffuse component of lighting applied to the material. 
 The lighting on the surface decreases as the angle between it and the light decreases. The lighting depends only on this angle, and does not change as objects move around.
 
 Can be set as a constant value or as a texture.
 */
@property (nonatomic) ARMaterialProperty *diffuse;

/**
 The ambient component of lighting applied to the material. 
 Represents a solid colour unaffected by other lighting in the scene.
 
  Can be set as a constant value or as a texture.
 */
@property (nonatomic) ARMaterialProperty *ambient;

/**
 The specular component of lighting applied to the material.
 A specular highlight is dependent on the surface angle, light angle, and viewing angle. The highlight is actually just a realtime-suitable way to simulate blurred reflections of a light source. The level of blur for the highlight is controlled with the shininess property.
 Represents the reflection of light at the reflection angle from an incident light source.
 
 Can be set as a constant value or as a texture.
 */
@property (nonatomic) ARMaterialProperty *specular;

/**
 This property contains two properties of its own, an environment map and a reflectivity factor. These are used for image-based reflections and refractions.
 
 Reflectivity is set in the range of 0..1.
 
 The Environment map variable is a texture cube that simulates the environment surrounding the material. It must be assigned a cube map for reflection to occur.
*/
@property (nonatomic) ARMaterialPropertyReflection *reflection;

/**
 The map used to calculate surface normals for high-quality lighting.
 
 Can be set as a texture only.
 */
@property (nonatomic) ARMaterialProperty *normal;

/**
 The shininess factor affects the amount of specular light emitted by the material. 
 A lower value makes the material appear duller.
 A higher value makes the material appear shinier.
 */
@property (nonatomic) float shininess;

/**
 Transparency of the material. 1.0 for fully opaque objects. 0.0 for fully transparent objects.
 
 Default is 1.0.
 */
@property (nonatomic) float alpha;

/**
 The blend parameter. Mixes blendTexture with the colour texture based on value.
 The range is 0..1, where 0 is only the colour texture and 1 is only the blend texture.
 
 Default is 0.0.
 */
@property (nonatomic) float blendParameter;

/**
 Ratio between the refractive indices of the mediums the light enters and exits during refraction. 
 
 Default is 1.0.
 
 For example:   Air has a refractive index of 1.0003
                Glass has a refractive index of 1.517
 
                The correct ratio of light that is entering a glass material from air is:
 
                    refractivityRatio = r(Air) / r(Glass) = 1.0003 / 1.517 = 0.66
 */
@property (nonatomic) float refractivityRatio;

/**
 Maximum number of dynamic lights the material can be lit by in the scene. More lights will cause more intensive calculations and produce lower framerates.
 
 Default is 1.
 */
@property (nonatomic) int maxLights;

/**
 Whether the lighting calculations should occur on a per-vertex or a per-pixel basis. Per-pixel lighting calculations produce better visual results at the expense of performance. Some lighting functions, such as normal maps and accurate dynamic lighting, are unavailable in the per-vertex case.
 */
@property (nonatomic) BOOL perPixelShader;

@end
