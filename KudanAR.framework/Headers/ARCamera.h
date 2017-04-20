#import <Foundation/Foundation.h>
#import <KudanAR/ARNode.h>

@class ARViewPort;

/**
 An ARCamera is a subclass of ARNode that represents the root of the scenegraph. It is attached to an ARViewPort and controls the projection.
 */
@interface ARCamera : ARNode

/**
 The projection matrix representing the camera intrinsics.
 A computer monitor is a 2D surface. A 3D scene rendered must therefore be projected onto the computer screen as a 2D image. 
 The projection matrix is used for this projection transformation. First, it transforms all vertex data from eye space to world space. 
 The resulting coordinates are then transformed from camera space to screen space.
 */
@property (nonatomic) ARMatrix4 *projectionMatrix;

/**
 Reference to a default static camera. Will be created if it hasn't already.
 
 Example of use:
 @code
 ARCamera *camera = [ARCamera defaultCamera];
 @endcode
 */
+ (ARCamera *)defaultCamera;

/**
 The far plane distance of the camera frustum.
 */
@property (nonatomic) CGPoint frustumPlaneDistance;

/**
 The principle point of the camera. This is where the optical axis intersects the image plane.
 **/
@property (nonatomic) CGPoint principlePoint;

/**
 The cameras horizontal and verticle field of view. The x represents the horizontal fov and the y represents the vertical fov. 
 **/
@property (nonatomic) CGPoint fov;

/**
 The viewport this camera is attached to, or nil if detached.
 */
@property (nonatomic, weak) ARViewPort *viewPort;

@end
