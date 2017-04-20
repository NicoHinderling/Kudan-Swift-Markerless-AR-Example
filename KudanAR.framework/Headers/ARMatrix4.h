#import <Foundation/Foundation.h>

@class ARVector3;
@class ARVector4;
@class ARQuaternion;

@interface ARMatrix4 : NSObject <NSCoding>


+ (ARMatrix4 *)matrixWithIdentity;
+ (ARMatrix4 *)matrixWithValues:(float *)values;
+ (ARMatrix4 *)matrixWithTranslation:(ARVector3 *)translation rotation:(ARQuaternion *)rotation scale:(ARVector3 *)scale;

+ (ARMatrix4 *)frustumWithFOV:(float)fov aspect:(float)aspect near:(float)near far:(float)far zoom:(float)zoom;
+ (ARMatrix4 *)frustumWithLeft:(float)left right:(float)right bottom:(float)bottom top:(float)top near:(float)near far:(float)far;
+ (ARMatrix4 *)orthoWithLeft:(float)left right:(float)right bottom:(float)bottom top:(float)top near:(float)near far:(float)far;

- (ARMatrix4 *)multiplyByMatrix:(ARMatrix4 *)matrix;
- (ARMatrix4 *)localMultiplyByMatrix:(ARMatrix4 *)matrix;
- (ARVector3 *)multiplyByVector:(ARVector3 *)vector;
- (ARVector3 *)localMultiplyByVector:(ARVector3 *)vector;
- (ARVector4 *)multiplyByVector4:(ARVector4 *)vector;
- (ARVector4 *)localMultiplyByVector4:(ARVector4 *)vector;

- (ARMatrix4 *)transpose;
- (ARMatrix4 *)localTranspose;
- (ARMatrix4 *)inverse;
- (ARMatrix4 *)localInverse;

- (float *)makeGLMatrix:(float *)matrix;
- (float *)makeGLRotationMatrix:(float *)matrix;

- (ARVector3 *)scale;
- (ARVector3 *)translation;
- (ARQuaternion *)orientation;

@end
