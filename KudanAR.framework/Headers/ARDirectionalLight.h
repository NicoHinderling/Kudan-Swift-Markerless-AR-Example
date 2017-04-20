#import "ARLight.h"

/**
 An ARDirectionalLight represents a light source of constant intensity emitted from a specific direction. This light behaves as if all rays created are parallel and emitted from a distance infinitely far away.
 Affects objects that use ARLightMaterial.
 Direction of light source is set by changing the light's orientation variable.
 
 Example of use:
 @code
 ARNode *node = [[ARNode alloc] init];
 ARDirectionalLight *directionalLight = [[ARDirectionalLight alloc] initWithColour:[ARVector3 vectorWithValuesX:0.1 y:0.2 z:0.3]];
 [directionalLight rotateByDegrees:45 axisX:1 y:0 z:0];
 @endcode
 */
@interface ARDirectionalLight : ARLight

@end
