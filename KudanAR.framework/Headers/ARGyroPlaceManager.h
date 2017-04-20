#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <KudanAR/ARRenderer.h>

@class ARWorld;

/**
 Gyro place is a sensor-only tracker that places content on a virtual floor plane where the device is aimed.
 */
@interface ARGyroPlaceManager : NSObject <ARRendererDelegate>

/**
 Get the Gyro Place Manager singleton.
 
 Example of use:
 @code
 ARGyroPlaceManager *gyroPlaceManager = [ARGyroPlaceManager getInstance];
 @endcode
 
 @return The Gyro Place Manager singleton.
 */
+ (ARGyroPlaceManager *)getInstance;

/**
 Initialise the Gyro Place Manager. Sometimes, while the manager first initialises, the device's gyroscope will report incorrect values, causing the orientation of the target node to appear incorrect.
 This will correct itself after a number of frames.
 
 
 As part of the initialisation: 
 * New world is created
 * The floorDepth is set to -150
 * The ARGyroPlaceManager adds itself as a delegate of ARRenderer
 * ARGyroManager is initialised and started.
 
 
 Example of use:
 @code
 [[ARGyroPlaceManager getInstance] initialise];
 @endcode
 */
- (void)initialise;

/**
 Deinitialise the ARGyroPlaceManager. 
 
 By doing so:
 * ARGyroPlaceManager removes itself from being a delegate of ARRenderer
 * ARGyroManager is stopped and deinitialised
 * world node is set to nil
 * floorDepth set to 0
 
 Example of use:
 @code
 [[ARGyroPlaceManager getInstance] deinitialise];
 @endcode
 */
- (void)deinitialise;

/**
 The distance between the floor and the camera. The units are arbitrary but can have real-world meaning to achieve realistic scale for placed content.
 Eg. if you estimate the device to be 100cm above the floor, set floorDepth to -100. Content rendered using this same space will look approximately the correct scale.
 The default value is -150;
 */
@property (nonatomic) float floorDepth;

/**
 The world node that is controlled by this tracker. The world is placed where the camera normal intersects the floor plane.
 */
@property (nonatomic) ARWorld *world;

/**
 The centre of the screen in viewport coordinates. This is automatically set but can be overridden if you with a different part of the screen to act as the target.
 */
@property (nonatomic) CGPoint screenCentre;

@end
