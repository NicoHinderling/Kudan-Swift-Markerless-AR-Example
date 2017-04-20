#import <Foundation/Foundation.h>

/**
 An ARVector4 is a 4-Dimensional vector consisting of an X, Y, Z and W component. Generally used for graphical shading.
 */
@interface ARVector4 : NSObject

/**
 Create a vector with all 4 components set to 0.
 
 Example of use:
 @code
 ARVector4 *vector = [ARVector4 vectorWithZero];
 @endcode
 
 @return A vector with (0, 0, 0, 0)
 */
+ (ARVector4 *)vectorWithZero;

/**
 Create a vector with the specified component values.
 
 Example of use:
 @code
 ARVector4 *vector = [ARVector4 vectorWithValuesX:1 y:0 z:1 w:0];
 @endcode
 
 @param x The x component of the vector.
 @param y The y component of the vector.
 @param z The z component of the vector.
 @param w The w component of the vector.
 
 @return A vector with components set to the specified values.
 */
+ (ARVector4 *)vectorWithValuesX:(float)x y:(float)y z:(float)z w:(float)w;

/**
 The x value of the vector.
 */
@property (nonatomic) float x;

/**
 The y value of the vector.
 */
@property (nonatomic) float y;

/**
 The z value of the vector.
 */
@property (nonatomic) float z;

/**
 The w value of the vector.
 */
@property (nonatomic) float w;

/**
 Add this vector to another vector and return the result.
 
 @param vector The vector to add to this vector.
 
 @return The sum of the vectors.
 */
- (ARVector4 *)addVector:(ARVector4 *)vector;

/**
 Add this vector to another vector and store the result in this vector.
 
 @param vector The vector to add to this vector.
 
 @return This vector, now the sum of the two vectors.
 */
- (ARVector4 *)localAddVector:(ARVector4 *)vector;
- (ARVector4 *)subtractVector:(ARVector4 *)vector;
- (ARVector4 *)localSubtractVector:(ARVector4 *)vector;
- (ARVector4 *)multiplyByVector:(ARVector4 *)vector;
- (ARVector4 *)localMultiplyByVector:(ARVector4 *)vector;
- (ARVector4 *)divideByVector:(ARVector4 *)vector;
- (ARVector4 *)localDivideByVector:(ARVector4 *)vector;
- (float)dotProductWithVector:(ARVector4 *)vector;

- (void)setX:(float)x y:(float)y z:(float)z w:(float)w;

- (void)setModifyObserverWithDelegate:(id)delegate selector:(SEL)selector;

@end
