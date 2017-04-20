#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import "ARRenderer.h"

@class ARWorld;
@class ARQuaternion;

/**
 Delegate called when the gyro has started and contains values.
 */
@protocol ARGyroManagerDelegate  <NSObject>

@required
@optional

- (void)gyroStarted;

@end

/**
 A manager class representing the device's gyro. This class is resposible for using IMU data to transform AR content with device rotations.
 */
@interface ARGyroManager : NSObject <ARRendererDelegate>

/**
 @return ARGyroManager singleton
 Returns the ARGyroManager singleton. Initialises if it hasn't been allready.
 */
+ (ARGyroManager *)getInstance;

/**
 Enum representing the gyro's state.
 */
typedef enum {
    ARGyroManagerStateInitialised, ///< ARGyroManagerStateInitialised Gyro is initialised.
    ARGyroManagerStateStopped, ///< ARGyroManagerStateStopped Gyro is not running.
    ARGyroManagerStateStarted, ///< ARGyroManagerStateStarted Gyro is running.
} ARGyroManagerState;

/**
 The gyro manager's current state.
 */
@property (nonatomic) ARGyroManagerState gyroState;

/**
 Enum representing the gyro managers internal state.
 */
typedef enum {
    ARGyroManagerStateInternalInitialised,  ///< ARGyroManagerStateInitialised Gyro is initialised.
    ARGyroManagerStateInternalStopped, ///< ARGyroManagerStateStopped Gyro is not running.
    ARGyroManagerStateInternalStarted,  ///< ARGyroManagerStateStarted Gyro is running.
} ARGyroManagerStateInternal;

/**
 The gyro managers current internal state
 */
@property (nonatomic) ARGyroManagerStateInternal internalGyroState;

/**
 Initialises the ARGyroManager singleton and the ARCMMotionManger singleton with a default gyro update interval of 0.05 seconds.
 */
- (void)initialise;

/**
 Deinitialises the ARGyroManager singleton and dereferences CMMotiionManger.
 */
- (void)deinitialise;

/**
 Starts device motion updates and adds ARGyroManager to the list of ARRenderDelegates.
 */
- (void)start;
/**
 Stops device motion updates and removes ARGyroManager from the list of ARRenderDelegates.
 */
- (void)stop;

- (void)actualStart;
- (void)actualStop;

/**
 Updates the world orientation.
 */
- (void)updateNode;

/**
 The motion manager used to update the ARGyroManager's orientation.
 */
@property (nonatomic, readonly) CMMotionManager *motionManager;

/**
 The reference frame used to start the motion manager. Default is CMAttitudeReferenceFrameXTrueNorthZVertical.
 */
@property (nonatomic) CMAttitudeReferenceFrame gyroReferenceFrame;

/**
 A node representing the ARGyroManager's world.
 **/
@property (nonatomic) ARWorld *world;

/**
 Add a delegate for gyro event notifications.
 
 @param delegate The delegate to add to the Gyro Manager.
 */
- (void)addDelegate:(id < ARGyroManagerDelegate>)delegate;

/**
 Remove a delegate for gyro event notifications.
 
 @param delegate The delegate to remove from the Gyro Manager.
 */
- (void)removeDelegate:(id < ARGyroManagerDelegate>)delegate;

@end
