#import <Foundation/Foundation.h>

@class ARMaterialProperty;
@class ARTextureCube;

/**
 A class representing the materials reflection.
 **/
@interface ARMaterialPropertyReflection : NSObject

//@property (nonatomic) ARMaterialProperty *reflectivity;

/**
 The reflectivity ratio in range 0..1.
 **/
@property (nonatomic) float reflectivity;

/**
 The texture cube that is reflected.
 **/
@property (nonatomic) ARTextureCube *environment;

@end
