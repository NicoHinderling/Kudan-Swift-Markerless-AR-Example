#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ARRenderer.h"

@class ARWorld;
@class ARViewPort;
@class ARQuaternion;
@class ARVideoNode;

/**
 The ARFullscreenManager is a class that allows ARVideos to smoothly transition to fullscreen videos and back.
 */
@interface ARFullscreenManager : NSObject <ARRendererDelegate>

#pragma mark - Properties

/**
 The width of the camera's near clip plane.
 */
@property (nonatomic, readonly) float nearPlaneWidth;

/**
 The height of the camera's near clip plane.
 */
@property (nonatomic, readonly) float nearPlaneHeight;

/**
 Correctional value to account for the difference in viewport width to its associated render target.
 */
@property (nonatomic, readonly) float renderTargetCorrection;

/**
 The offset of the camera principle point from the screen centre.
 */
@property (nonatomic, readonly) CGPoint principlePointOffset;

/**
 Rotation of the screen from default state of UIInterfaceOrientationLandscapeLeft.
 */
@property (nonatomic, readonly) ARQuaternion *screenOrientation;

/**
 The ARWorld containing the fullscreen node.
 */
@property (nonatomic, readonly) ARWorld *world;

/**
 The current node in fullscreen. Will be nil if no node is currently fullscreen.
 */
@property (nonatomic, readonly) ARVideoNode *fullscreenNode;

/**
 The amount of time, in seconds, that the animation going between node and fullscreen should take. Changing this value will make the transition faster or slower. By default, it takes 1 second to complete.
 */
@property (nonatomic) NSTimeInterval fullscreenAnimationTime;

/**
 The amount of time, in seconds, that the animation for turning the video when the screen orientation changes should take. Changing this value will make the animation faster or slower. By default, it takes 1 second to complete.
 */
@property (nonatomic) NSTimeInterval rotationAnimationTime;

/**
 The amount of time, in seconds, that the background around the video fading to black should take. Changing this value will make the transition faster or slower. By default, it takes 1 second to complete. This only applies if showBackground is set to YES.
 */
@property (nonatomic) NSTimeInterval backgroundFadeAnimationTime;

/**
 Whether or not a black placeholder box will be left in the place of a node when fullscreen is enabled. A black box will appear at the VideoNode's location if YES. Nothing will appear at the node's location if NO.
 */
@property (nonatomic) BOOL showPlaceholder;

/**
 Whether or not the node will have a black borders that fade in to obscure the rest of the scene after enabling fullscreen. The size of the black borders will be dependant on the aspect ratio of the video vs the aspect ratio of the screen.
 */
@property (nonatomic) BOOL showBackground;

#pragma mark - Methods

/**
 Gets the ARFullscreenManager singleton.
 
 Example of use:
 @code
 ARFullscreenManager *fullscreenManager = [ARFullscreenManager getInstance];
 @endcode
 */
+ (ARFullscreenManager *)getInstance;

/**
 Initialises the manager to enable fullscreen in the desired viewport. Must be called for fullscreen to occur.
 
 Example of use:
 @code
 [[ARFullscreenManager getInstance] initialiseWithViewport:self.cameraView.contentViewPort];
 @endcode
 */
- (void)initialiseWithViewport:(ARViewPort *)viewport;

/**
 Disables fullscreen and removes all references and delegates.
 
 Example of use:
 @code
 [[ARFullscreenManager getInstance] deinitialise];
 @endcode
 */
- (void)deinitialise;

/**
 Called when the orientation of the device changes. Used to keep fullscreen nodes in the correct orientation. Should be called automatically.
 
 Example of use:
 @code
 [[ARFullscreenManager getInstance] fullscreenManager setDeviceOrientation:UIInterfaceOrientationPortrait];
 @endcode
 */
- (void)setDeviceOrientation:(UIInterfaceOrientation)orientation;

/**
 Makes the specified ARVideoNode transition to fullscreen view. Can only be called if no other node is currently fullscreen.
 
 Example of use:
 @code
 // self.videoNode - A previously made ARVideoNode
 [[ARFullscreenManager getInstance] makeNodeFullscreen:self.videoNode];
 @endcode
 */
- (void)makeNodeFullscreen:(ARVideoNode *)node;

/**
 Transitions the current fullscreen node back to it's original transformation in it's parent.
 
 Example of use:
 @code
 [[ARFullscreenManager getInstance] disableFullscreen];
 @endcode
 */
- (void)disableFullscreen;

@end
