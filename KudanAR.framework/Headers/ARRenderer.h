#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreVideo/CoreVideo.h>

@class ARMatrix4;
@class ARTexture;
@class ARVector3;
@class ARRenderTarget;
@class ARRenderer;

/**
 Delegates related to rendering. There are currently 4 available methods for use.
 */
@protocol ARRendererDelegate <NSObject>

@required
@optional
/**
 Method called just prior to rendering each frame.
 */
- (void)rendererPreRender;

/**
 Method called just after rendering each frame.
 */
- (void)rendererPostRender;

/**
 Method called when the renderer has been paused. This can be used to shut down other subsystems.
 */
- (void)rendererDidPause;

/**
 Method called when the renderer resumes after being paused.
 */
- (void)rendererDidResume;

@end

/**
 Polygon Face culling modes. These are useful for improving performance by not rendering certain types of polygon when they aren't visible. Available modes are:
 */
typedef enum {
    /**
      ARFaceCullModeDisabled - Don't cull any polygons.
     */
    ARFaceCullModeDisabled,
    
    /**
      ARFaceCullModeBack - Cull only back-facing polygons.
     */
    ARFaceCullModeBack,
    
    /**
      ARFaceCullModeFront - Cull only front-facing polygons.
     */
    ARFaceCullModeFront,
    
    /**
      ARFaceCullModeFrontAndBack - Cull all polygons.
     */
    ARFaceCullModeFrontAndBack,
} ARFaceCullMode;

/**
 Blending modes for transparency. Different modes will provide greater graphical fidelity at the cost of performance. Available modes are:
 */
typedef NS_ENUM(NSInteger, ARBlendMode) {
    /**
      ARBlendModeDisabled - Disable Blending, no transparency.
     */
    ARBlendModeDisabled,
    
    /**
      ARBlendModeAdditive - Additive Blending.
     */
    ARBlendModeAdditive,
    
    /**
      ARBlendModeAlphaAdditive - Alpha Additive Blending.
     */
    ARBlendModeAlphaAdditive,
    
    /**
      ARBlendModePreMultiplyAlpha - Premultiplied Alpha Blending.
     */
    ARBlendModePreMultiplyAlpha,
};

/**
 The current state of the renderer. Possible states are:
 */
typedef NS_ENUM(NSInteger, ARRendererState) {
    /**
      ARRendererStateUninitialised - The renderer has not yet been initialised and is unusable.
     */
    ARRendererStateUninitialised,
    
    /**
      ARRendererStatePaused - The renderer is paused and will not render new frames.
     */
    ARRendererStatePaused,
    
    /**
      ARRendererStateRunning - The renderer is active and will draw frames.
     */
    ARRendererStateRunning,
};

/**
 A class used for rendering the camera image and AR content on screen. 
 **/
@interface ARRenderer : NSObject

/**
 Get the ARRenderer singleton.
 
 Example of use:
 @code
 ARRenderer *renderer = [ARRenderer getInstance];
 @endcode
 
 @return The singleton instance.
 */
+ (ARRenderer *)getInstance;

/**
 The current renderer state (Uninitialised, Paused or Running).
 */
@property (nonatomic) ARRendererState rendererState;

/**
 The time, in seconds, of the current frame.
 */
@property (nonatomic, readonly) NSTimeInterval currentFrameTime;

/**
 Use this renderer's OpenGL context. This should be called if you intend to modify content (textures, meshes, materials) from a new thread.
 
 Example of use:
 @code
 [[ARRenderer getInstance] useContext];
 @endcode
 */
- (void)useContext;

/**
 Add a delegate for rendering event notifications.
 
 Example of use:
 @code
 [[ARRenderer getInstance] addDelegate:self];
 @endcode
 
 @param delegate The delegate to add.
 */
- (void)addDelegate:(id <ARRendererDelegate>)delegate;

/**
 Remove a delegate for rendering event notifications.
 
 Example of use:
 @code
 [[ARRenderer getInstance] removeDelegate:self];
 @endcode
 
 @param delegate The delegate to remove.
 */
- (void)removeDelegate:(id <ARRendererDelegate>)delegate;

/**
 Add a render target to the renderer. This is required if render targets are to be automatically drawn each frame.
 
 Example of use:
 @code
 // self.renderTarget - A previously created ARRenderTarget.
 [[ARRenderer getInstance] addRenderTarget:self.renderTarget];
 @endcode
 
 @param renderTarget The render target to add.
 */
- (void)addRenderTarget:(ARRenderTarget *)renderTarget;

/**
 Remove a render target from the renderer.
 
 Example of use:
 @code
 [[ARRenderer getInstance] removeRenderTarget:renderTarget];
 @endcode
 
 @param renderTarget The render target to remove.
 */
- (void)removeRenderTarget:(ARRenderTarget *)renderTarget;

/**
 The list of ARRenderTarget objects registered with the renderer.
 */
@property (nonatomic, readonly) NSArray *renderTargets;

/**
 Initialise the renderer. This should be called automatically. It is not recommended to call this method manually.
 
 Example of use:
 @code
 [[ARRenderer getInstance] initialise];
 @endcode
 */
- (void)initialise;

/**
 Deinitialise the renderer. This is usually called automatically. It is not recommended to call this method manually.
 Changes the ARRendererState to ARRendererStateUninitialised.
 
 Example of use:
 @code
 [[ARRenderer getInstance] deinitialise];
 @endcode
 */
- (void)deinitialise;

/**
 Pause all rendering operations. Changes the ARRendererState to ARRendererStatePaused. Any delegates implementing rendererDidPause will be called at this time.
 
 Example of use:
 @code
 [[ARRenderer getInstance] pause];
 @endcode
 */
- (void)pause;

/**
 Resume rendering operations. Changes the ARRendererState to ARRendererStateRunning. Any delegates implementing rendererDidResume will be called this time.
 
 Example of use:
 @code
 [[ARRenderer getInstance] resume];
 @endcode
 */
- (void)resume;

@end
