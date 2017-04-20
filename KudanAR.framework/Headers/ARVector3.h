#ifndef __ARVector3_h
#define __ARVector3_h

#import <Foundation/Foundation.h>

@class ARQuaternion;

@interface ARVector3 : NSObject <NSCoding, NSCopying>

+ (ARVector3 *)vectorWithZero;
+ (ARVector3 *)vectorWithValuesX:(float)x y:(float)y z:(float)z;
+ (ARVector3 *)vectorWithValues:(float)v;
+ (ARVector3 *)vectorWithVector:(ARVector3 *)vec;

@property (nonatomic) float x;
@property (nonatomic) float y;
@property (nonatomic) float z;

- (BOOL)equalsVector:(ARVector3 *)vector withTolerance:(float)tolerance;
- (ARVector3 *)addVector:(ARVector3 *)vector;
- (ARVector3 *)localAddVector:(ARVector3 *)vector;
- (ARVector3 *)subtractVector:(ARVector3 *)vector;
- (ARVector3 *)localSubtractVector:(ARVector3 *)vector;
- (ARVector3 *)multiplyByVector:(ARVector3 *)vector;
- (ARVector3 *)localMultiplyByVector:(ARVector3 *)vector;
- (ARVector3 *)divideByVector:(ARVector3 *)vector;
- (ARVector3 *)localDivideByVector:(ARVector3 *)vector;
- (ARVector3 *)multiplyByScalar:(double)scalar;
- (ARVector3 *)divideByScalar:(double)scalar;
- (float)distanceToVector:(ARVector3 *)vector;
- (float)dotProductWithVector:(ARVector3 *)vector;
- (ARVector3 *)normalise;
- (ARVector3 *)localNormalise;
- (ARVector3 *)negate;
- (ARVector3 *)crossProductWithVector:(ARVector3 *)vector;
- (ARVector3 *)localCrossProductWithVector:(ARVector3 *)vector;

- (ARQuaternion *)rotationTo:(ARVector3 *)vector;
- (ARVector3 *)lerpTo:(ARVector3 *)vector atTime:(float)time;

@property (nonatomic, readonly) float length;

- (void)setX:(float)x y:(float)y z:(float)z;

- (void)setModifyObserverWithDelegate:(id)delegate selector:(SEL)selector;

@end

#endif
