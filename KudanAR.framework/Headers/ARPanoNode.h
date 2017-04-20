#import <Foundation/Foundation.h>
#import <KudanAR/ARNode.h>

/**
 This node represents a cube panorama that can be added to the gyro controller. By moving the device around, it is possible to look around a 360 image.
 The node is created by using a taking a set of images and arranging them in a cube formation.
 */
@interface ARPanoNode : ARNode

/**
 Initialises an instance of the ARPanoNode and sets up a cube of images around the node. The set of image names used must be arranged in the correct order, or they will be out of place.
 The positions of the images cannot be altered once they have been loaded. The array of images names should be arranged as follows:
 Element 0 - Front.
 Element 1 - Back.
 Element 2 - Left.
 Element 3 - Right.
 Element 4 - Top.
 Element 5 - Bottom.
 
 @param images NSArray of 6 image names or paths to the image.
 @return ARPanoNode

 */
- (instancetype)initWithImages:(NSArray *)images;

@end
