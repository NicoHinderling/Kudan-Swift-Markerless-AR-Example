#import <Foundation/Foundation.h>
#import <KudanAR/ARMaterial.h>

@class ARVideoTexture;

/**
 A material used to render alpha videos as an ARVideoTexture. Alpha Videos are videos specially created using the Kudan AR Toolkit.
 They are a series of images that are in two halves, with the left half containing the colour frames of the image on a white background 
 and the right half containing an alpha mask.
 When these frames are encoded using the Kudan AR Toolkit, the resulting video is a .mp4 file playing the frames at the specified frame rate.
 When rendered using the framework, the two halves are combined together and the resulting video with transparency is displayed on its associated node.
 */
@interface ARAlphaVideoMaterial : ARMaterial

/**
 The ARVideoTexture associated with this material. This is the video that will be played when the material is rendered.
 */
@property (nonatomic) ARVideoTexture *texture;

/**
 Initialises an ARAlphaVideoMaterial object using an ARVideoTexture.
 
 Example of use:
 @code
 ARAlphaVideoMaterial *videoMaterial = [[ARAlphaVideoMaterial alloc] initWithTexture:texture];
 @endcode
 
 @param texture The ARVideoTexture to initialise the class with.
 */
- (instancetype)initWithTexture:(ARVideoTexture *)texture;

/**
 Class method that initialises and returns an instance of an ARAlphaVideoMaterial object.
 The difference between this method and initWithTexture is that you must create an instance to initialise using initWithTexture, whereas you do not using materialwithTexture.
 
 Example of use:
 @code
 ARAlphaVideoMaterial *videoMaterial = [ARAlphaVideoMaterial materialwithTexture:texture];
 @endcode
  */
+ (instancetype)materialwithTexture:(ARVideoTexture *)texture;
@end
