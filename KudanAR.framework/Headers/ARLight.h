#import <Foundation/Foundation.h>
#import <KudanAR/ARNode.h>

@class ARVector3;

/**
 The base light class from which all light classes derive. If an ARLight is used, it will behave similarly to a point light, but it will not have any attenuation, so the light will not fade over distance.
 
 Example of use:
 @code
 ARNode *node = [[ARNode alloc] init];
 ARLight *light = [[ARLight alloc] initWithColour:[ARVector3 vectorWithValuesX:0.1 Y:0.2 Z:0.3];
 [node addChild:light];
 light.position = [ARVector3 vectorWithValuesX:0 Y:0 Z:0];
 light.ambientCoefficient = 0.5;
 @endcode
 */
@interface ARLight : ARNode

/**
 An ARVector3 representing the colour component of this light. Each component (X, Y, Z) of this vector should be in the range 0..1.
 */
@property (nonatomic) ARVector3 *colour;

/**
 The minimum amount of illumination added to all objects in the scene regardless of incident light.
 */
@property (nonatomic) float ambientCoefficient;

/**
 Initialises an instance of ARLight using the given RGB values in the form of an ARVector3.
 
 Example of use:
 @code
 ARLight *light = [[ARLight alloc] initWithColour:[ARVector3 vectorWithValuesX:0.3 Y:0.4 Z:0.5];
 @endcode
 @param colour ARVector3 which holds R,G,B values of 0..1
 */
- (instancetype)initWithColour:(ARVector3 *)colour;

@end
