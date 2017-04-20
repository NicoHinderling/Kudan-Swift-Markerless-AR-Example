#import <Foundation/Foundation.h>

@class UIImage;

/**
 Texture filtering modes:
 */
typedef enum {
    /**
     ARTextureFilterNearest - No filtering, use 'Nearest Neighbour'.
     */
    ARTextureFilterNearest,
    
    /**
     ARTextureFilterLinear - Use Linear Interpolation.
     */
    ARTextureFilterLinear,
} ARTextureFilter;

/**
 An ARTexture is a class representing a 2D texture. Textures cannot exceed 2048x2048 pixels in size.
 */
@interface ARTexture : NSObject
{
    NSData *_rawImage;
}

/**
 Texture name in OpenGL.
 **/
@property (nonatomic) unsigned textureID;

/**
 The width of the texture, in pixels.
 */
@property (nonatomic) unsigned long width;

/**
 The height of the texture, in pixels.
 */
@property (nonatomic) unsigned long height;

/**
 Create a texture from a UIImage.
 
 Example of use:
 @code
 ARTexture *texture = [[ARTexture alloc] initWithUIImage:[UIImage imageNamed:@"example.jpg"]];
 @endcode
 
 @param image The UIImage to create the texture from.
 */
- (instancetype)initWithUIImage:(UIImage *)image;

/**
 Create an empty texture to be loaded with an image later.
 
 Example of use:
 @code
 ARTexture *texture = [[ARTexture alloc] initWithEmpty];
 @endcode
 */
- (instancetype)initWithEmpty;


//+ (id)textureWithUIImage:(UIImage *)image;
//+ (id)textureWithUIImage:(UIImage *)image normalMap:(BOOL)normalMap;

- (instancetype)initWithExistingTextureID:(unsigned)textureID;

/**
 Generates texture names using texure id.
 **/
- (void)generateTexture;

/**
 Uploads texture to OpenGL.
 */
- (void)uploadTexture;

/**
 Loads image data into rawimage, sets image width and height, sets pixel format.
 
 @param image Image to generate texture from.
 @param reverseLines  Whether to read pixels from top(YES) or bottom.
 */
- (void)loadTextureFromUIImage:(UIImage *)image reverseLines:(BOOL)reverseLines;

- (void)uploadBGRATexture:(unsigned char *)data width:(float)width height:(float)height;
- (void)uploadBGRATextureSub:(unsigned char *)data width:(float)width height:(float)height;


/**
 Method called just before this texture is rendered.
 
 @return BOOL Whether or not to proceed with rendering.
 */
- (BOOL)preRender;

/**
 Method called just after this texture has been used in rendering.
 */
- (void)postRender;

@property (nonatomic) BOOL isPowerOfTwo;

/**
 The filtering type used for minification. ARTextureFilterLinear is recommended for less aliasing.
 */
@property (nonatomic) ARTextureFilter minificationFilter;

/**
 The filtering type used for magnification. ARTextureFilterLinear is recommended for less aliasing.
 */
@property (nonatomic) ARTextureFilter magnificationFilter;

@end
