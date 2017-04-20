#import <Foundation/Foundation.h>
#import <KudanAR/ARMeshNode.h>

@class ARTexture;
@class UIImage;
/**
 A single mesh node used for rendering images. This displays imported images in the AR world.
 **/
@interface ARImageNode : ARMeshNode

/**
 The texture used for rendering the image. Created during the initialisation process. 
 **/
@property (nonatomic) ARTexture *texture;

/**
 @param image UIimage to be displayed.
 Initialises ARImageNode using a UIImage.
 **/
- (instancetype)initWithImage:(UIImage *)image NS_DESIGNATED_INITIALIZER;

/**
 @param path Full path of image file.
 Initialises ARImageNode using an NSString that holds the full path of an image file.
 **/
- (instancetype)initWithImagePath:(NSString *)path;

/**
 @param file Name of bundled file with extension.
 Initialises ARImageNode using an NSString that holds the file name and extension of a bundled file.
 **/
- (instancetype)initWithBundledFile:(NSString *)file;

@end
