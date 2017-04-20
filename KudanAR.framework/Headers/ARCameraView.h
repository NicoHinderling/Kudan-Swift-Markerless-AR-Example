#import <Foundation/Foundation.h>
#import <KudanAR/ARView.h>
#import <KudanAR/ARCameraStream.h>

@class ARTexture;
@class ARCameraViewController;
@class ARViewPort;

/**
 An ARCameraView is a subclass of ARView that contains viewports for the automatic rendering of the camera image, content and point clouds.
 */
@interface ARCameraView : ARView <ARCameraStreamEvent>

/**
 The camera texture that the camera stream is drawing to. Essentially, this is the camera feed seen whilst running an AR scene.
 */
@property (nonatomic) ARTexture *cameraTexture;

/**
 Resume rendering of the camera view.
 */
- (void)pause;

/**
 Pause rendering of the camera view.
 */
- (void)resume;

/**
 Method called when a new camera frame is received.
 Image data is in the YUV format. The first WxH bytes of this data will be the greyscale image.
 It is possible to hook into this method and get the camera data in order to use it for other purposes.
 
 @param data The data in greyscale.
 @param timeStamp the time the frame was received.
 */
- (void)didReceiveNewFrame:(NSData *)data timeStamp:(NSTimeInterval)timeStamp;

/**
 The ARCameraViewController that contains this view.
 */
@property (nonatomic, weak) ARCameraViewController *cameraViewController;

/**
 The viewport responsible for displaying the camera feed.
 This has an orthographic projection.
 */
@property (nonatomic) ARViewPort *cameraViewPort;

/**
 The viewport responsible for displaying any AR content, such as images, videos or 3D models, on top of the camera feed.
 This has a perspective projection.
 */
@property (nonatomic) ARViewPort *contentViewPort;

@property (nonatomic) ARViewPort *pointsViewPort;

@end
