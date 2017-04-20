#import <KudanAR/ARPointLight.h>

/**
 An ARSpotLight represents a light in the scene that shines from a specific position along a specific direction with a cone-shaped area of effect.
 It can be translated and rotated just like any other node. 
 It can be seen as a combination of an ARPointLight and an ARDirectionLight, as both the position and orientation of an ARSpotLight will affect the overall level of illumination on each object in the scene.
 */
@interface ARSpotLight : ARPointLight

/**
 The angle between the centre of the light direction vector and the side of the light cone at which the light intensity begins to decay, expressed in radians.
 Should be no more than M_PI / 2.
 Should not be greater than the outer spot angle.
 */
@property (nonatomic) float innerSpotAngle;

/**
 The angle between the centre of the light direction vector and the side of the light cone at which the light intensity becomes 0, expressed in radians.
 Should be no more than M_PI / 2.
 Should not be less than the inner spot angle.
 */
@property (nonatomic) float outerSpotAngle;

/**
 The normalised direction that the spotlight is pointing in.
 */
@property (nonatomic) ARVector3 *spotDirection;

@end
