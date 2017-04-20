
#import <Foundation/Foundation.h>
#import <KudanAR/ARRenderTargetTexture.h>
#import <KudanAR/ARRenderer.h>

@class ARNode;

/**
 The ARExtractedCameraTexture is a texture that takes its data directly from the camera stream. This can be used during rendering to deform the camera texture.
 
 Example of use for Marker tracking:
 @code
 ARImageTrackable *imageTrackable = [[ARImageTrackable alloc] initWithBundledFile:@"example.jpg"];
 ARExtractedCameraTexture *cameraTexture = [[ARExtractedCameraTexture alloc] initWithWidth:512 height:512];
 
 cameraTexture.srcNode = [ARNode nodeWithName:@"camera texture source node"];
 cameraTexture.srcWidth = trackable.width;
 cameraTexture.srcHeight = trackable.height;
 
 [trackable.world addChild:extracted.srcNode];
 @endcode
 
 Example of use for Markerless tracking:
 @code
 ARExtractedCameraTexture *cameraTexture = [[ARExtractedCameraTexture alloc] initWithWidth:512 height:512];
 
 cameraTexture.srcNode = [ARNode nodeWithName:@"camera texture source node"];;
 cameraTexture.srcWidth = 100;
 cameraTexture.srcHeight = 100;
 @endcode
 */
@interface ARExtractedCameraTexture : ARRenderTargetTexture <ARRendererDelegate>

/**
 The node which defines the region of the camera image the texture should be extracted from. 
 Move this node around by adding to the area of interest (e.g the world of a trackable). Can be reparented to your own nodes.
 */
@property (nonatomic) ARNode *srcNode;

/**
 The width in the coordinate space of the source node that determines the X-axis boundaries of the texture.
 */
@property (nonatomic) float srcWidth;

/**
 The height in the coordinate space of the source node that determines the Y-axis boundaries of the texture.
 */
@property (nonatomic) float srcHeight;

/**
 Initialises the texture with the given dimensions. Overall resolution doesn't have to match the aspect ratio of srcWidth:srcHeight.
 
 Example of use:
 @code
 ARExtractedCameraTexture *cameraTexture = [[ARExtractedCameraTexture alloc] initWithWidth:512 height:512];
 @endcode
 
 @param width The width of the extracted texture. Maximum width 2048. Recommended width 512 for balance between performance and quality.
 @param height The height of the extracted texture. Maximum width 2048. Recommended height 512 for balance between performance and quality.
 */
- (instancetype)initWithWidth:(float)width height:(float)height;

@end
