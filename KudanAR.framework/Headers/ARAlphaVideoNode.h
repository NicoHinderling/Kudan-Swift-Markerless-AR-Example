#import <Foundation/Foundation.h>
#import <KudanAR/ARMeshNode.h>

@class ARVideoTexture;

/**
 An ARAlphaVideoNode is a subclass of ARNode that renders a supplied alpha video file on a flat mesh in the scene.
 It can be initialised using either a video file bundled in your app or with an ARVideoTexture containing an Alpha Video. 
 Other than the fact it plays Alpha Videos, it behaves like any other node.
 */
@interface ARAlphaVideoNode : ARMeshNode

/**
 The ARVideoTexture used by this Alpha Video Node. This is the video that will be played when then node becomes active and visible.
 */
@property (nonatomic) ARVideoTexture *videoTexture;

/**
 Initialises an ARAlphaVideoNode using an ARVideoTexture.
 
 Example of use:
 @code
 ARAlphaVideoNode *alphaVideoNode = [[ARAlphaVideoNode alloc] initWithVideoTexture: videoTexture];
 @endcode
 
 @param videoTexture The ARVideoTexture to initialise the object with.
 */
- (instancetype)initWithVideoTexture:(ARVideoTexture *)videoTexture NS_DESIGNATED_INITIALIZER;

/**
 Initialises an ARAlphaVideoNode using a video file at the specified path. The Kudan AR Toolkit generates Alpha Videos in the .mp4 format, so this is the extension you need to use.
 
 Example of use:
 @code
 ARAlphaVideoNode *alphaVideoNode = [[ARAlphaVideoNode alloc] initWithBundledFile:“Assets/example.mp4”];
 @endcode
 
 @param file This string will be the file path of the video relative to the rest of your project, including the file extension.
 */
- (instancetype)initWithBundledFile:(NSString *)file;

@end
