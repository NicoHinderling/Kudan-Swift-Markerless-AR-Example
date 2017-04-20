#import <KudanAR/ARLight.h>

/**
 ARPointLight represents a light in the scene that shines in all directions equally from a specific position, much like the standard ARLight.
 However, unlike ARLight, ARPointLight accounts for attenuation, with the level of light falling off over distance, following the inverse square law.
 */
@interface ARPointLight : ARLight

/**
 The decay of the light intensity over distance.
 
 Smaller values represent less decay.
 */
@property (nonatomic) float attenuation;

@end
