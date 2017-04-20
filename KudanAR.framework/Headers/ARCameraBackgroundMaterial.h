#import <Foundation/Foundation.h>
#import <KudanAR/ARMaterial.h>

@class ARMatrix4;
@class ARTexture;

/**
 A material responsible for drawing the camera feed. Used in ARExtractedCameraTexture.
 **/
@interface ARCameraBackgroundMaterial : ARMaterial

/**
 The model view projection matrix of the portion of the camera to be rendered.  
 **/
@property (nonatomic) ARMatrix4 *markerModelViewProjection;

/**
 The extracted camera luma texture.
 **/
@property (nonatomic) ARTexture *cameraTexture;

/**
 The extracted camera chroma texture.
 **/
@property (nonatomic) ARTexture *cameraTextureUV;

/**
 Initialises ARCameraBackgroundMaterial with a luma amd chroma texture.
 
 @param texture Camera luma texture.
 @param textureUV Camera chroma texture.
 @return ARCameraBackgroundMaterial

 **/
- (instancetype)initWithTexture:(ARTexture *)texture textureUV:(ARTexture *)textureUV;

@end
