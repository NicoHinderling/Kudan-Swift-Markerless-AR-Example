#import <KudanAR/ARTexture.h>

/**
 An ARTextureCube is a texture representing a cube for use in environment mapping.
 */
@interface ARTextureCube : ARTexture

/**
 Initialise with an array of UIImage images.
 The array must be in the correct order for the mapping to work properly.
 The order of images cannot be altered once initialised.
 The correct order of images is as follows:
 Element 0 - Back.
 Element 1 - Front.
 Element 2 - Left.
 Element 3 - Right.
 Element 4 - Top.
 Element 5 - Bottom.
 
 Example of use:
 @code
 UIImage backImage = [UIImage imageNamed:@"backImage.jpg"];
 UIImage frontImage = [UIImage imageNamed:@"frontImage.jpg"];
 UIImage leftImage = [UIImage imageNamed:@"leftImage.jpg"];
 UIImage rightImage = [UIImage imageNamed:@"rightImage.jpg"];
 UIImage topImage = [UIImage imageNamed:@"topImage.jpg"];
 UIImage bottomImage = [UIImage imageNamed:@"bottomImage.jpg"];
 NSArray *array = @[backImage, frontImage, leftImage, rightImage, topImage, bottomImage];
 ARTextureCube *textureCube = [[ARTextureCube alloc] initWithUIImages:array];
 @endcode
 
 @param images An array of UIImage objects to load into the cube map.
 */
- (instancetype)initWithUIImages:(NSArray *)images;

/**
 Initialise with an array of strings, each of which is a file path relative to the main bundle, pointing to image files.
 The array must be in the correct order for the mapping to work properly.
 The order of images cannot be altered once initialised.
 The correct order of images is as follows:
 Element 0 - Back.
 Element 1 - Front.
 Element 2 - Left.
 Element 3 - Right.
 Element 4 - Top.
 Element 5 - Bottom.
 
 Example of use:
 @code
 NSArray *array = @[@"backImage.jpg", @"frontImage.jpg", @"leftImage.jpg", @"rightImage.jpg", @"topImage.jpg", @"bottomImage.jpg"];
 ARTextureCube *textureCube = [[ARTextureCube alloc] initWithBundledFiles:array];
 @endcode
 
 @param images An array of image file names relative to the main bundle.
 */
- (instancetype)initWithBundledFiles:(NSArray *)bundledFiles;

@end
