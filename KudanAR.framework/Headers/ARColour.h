#import <Foundation/Foundation.h>
#import <KudanAR/ARVector3.h>

/**
 Wrapper for an ARVector3 that allows initialisation with full (0..255) RGB values and handles the conversion to the range 0..1.
 */
@interface ARColour : ARVector3

/**
 Initialise the vector with red, green and blue values in the 0..255 range.
 
 Example of use:
 @code
 ARColour *colour = [[ARColour alloc] initWithRed:225 green:32 blue:64];
 @endcode
 */
- (instancetype)initWithRed:(float)red green:(float)green blue:(float)blue;

@end
