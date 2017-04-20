#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>

#import <Foundation/Foundation.h>

/**
 * A wrapper class for apples CMMotionManager.
 **/
@interface ARCMMotionManager : NSObject

/**
 * Returns Apple's CMMotionManager. Use this singleton for recieving device updates as Apple state creating multiple instances of the CMMotionManager can affect the rate at which data is recieved from the accelerometer and gyroscope. The motion manager is initialised with default gyro updates of  every 0.05s. 
 **/
+ (CMMotionManager *)getInstance;

@end
