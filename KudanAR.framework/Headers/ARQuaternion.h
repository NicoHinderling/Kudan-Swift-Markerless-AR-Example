#import <Foundation/Foundation.h>

@class ARVector3;
@class ARMatrix4;

@interface ARQuaternion : NSObject <NSCoding>

+ (ARQuaternion *)quaternionWithIdentity;
+ (ARQuaternion *)quaternionWithX:(float)x y:(float)y z:(float)z w:(float)w;
+ (ARQuaternion *)quaternionFromMatrix4:(ARMatrix4 *)matrix;
+ (ARQuaternion *)quaternionWithDegrees:(float)angle axisX:(float)x y:(float)y z:(float)z;
+ (ARQuaternion *)quaternionWithRadians:(float)angle axisX:(float)x y:(float)y z:(float)z;

- (BOOL)equalsQuaternion:(ARQuaternion *)quaternion withTolerance:(float)tolerance;
- (ARQuaternion *)addQuaternion:(ARQuaternion *)quaternion;
- (ARQuaternion *)localAddQuaternion:(ARQuaternion *)quaternion;
- (ARQuaternion *)subtractQuaternion:(ARQuaternion *)quaternion;
- (ARQuaternion *)localSubtractQuaternion:(ARQuaternion *)quaternion;
- (ARQuaternion *)multiplyByQuaternion:(ARQuaternion *)quaternion;
- (ARQuaternion *)localMultiplyByQuaternion:(ARQuaternion *)quaternion;
- (ARVector3 *)multiplyByVector:(ARVector3 *)vector;
- (ARVector3 *)localMultiplyByVector:(ARVector3 *)vector;

- (ARQuaternion *)negate;
- (ARQuaternion *)localNegate;
- (float)dotWithQuaternion:(ARQuaternion *)quaternion;
- (ARQuaternion *)normalise;
- (ARQuaternion *)localNormalise;
- (ARQuaternion *)inverse;
- (ARQuaternion *)localInverse;
- (ARQuaternion *)slerpToQuaternion:(ARQuaternion *)quaternion atTime:(float)time;

@property (nonatomic, readonly) float x;
@property (nonatomic, readonly) float y;
@property (nonatomic, readonly) float z;
@property (nonatomic, readonly) float w;

@end
