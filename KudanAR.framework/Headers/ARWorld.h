#import <Foundation/Foundation.h>
#import <KudanAR/ARNode.h>

/**
 A node representing the concept of a world. A world has special properties in that there are helper methods to convert arbitrary node transformations into world space. 
 It also has special meaning for reflection maps as reflections are calculated in world space. This means that the environment map is aligned with the closest descendent ARWorld.
 */
@interface ARWorld : ARNode

@end
