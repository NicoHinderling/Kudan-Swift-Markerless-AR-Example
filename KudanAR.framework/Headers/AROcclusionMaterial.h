#import <Foundation/Foundation.h>
#import <KudanAR/ARColourMaterial.h>

/**
 This material type can be used by ARMeshNode objects to achieve an occlusion effect, where real-world camera objects can occlude the rendered content.
 This gives the appearance of models or images moving behind, under or around real-world objects, improving the level of immersion in the scene.
 */
@interface AROcclusionMaterial : ARColourMaterial


@end
