#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ARViewPort;
@class UIImage;

/**
 Render target events.
 */
@protocol ARRenderTargetDelegate <NSObject>

/**
 Delegate method called just before rendering this render target.
 */
- (void)preRender;

/**
 Delegate method called just after rendering this render target.
 */
- (void)postRender;

@end

/**
 A render target represents a target buffer for rendering.
 */
@interface ARRenderTarget : NSObject

/**
 The list of ARViewPort objects that this render target contains. These are rendered based on viewport z-order.
 */
@property (nonatomic) NSArray *viewPorts;

/**
 The number of viewports contained by this render target.
 */
@property (nonatomic, readonly) NSUInteger numberOfViewPorts;

/**
 Add a viewport to this render target.
 
 Example of use:
 @code
 ARViewPort *viewPort = [[ARViewPort alloc] initWithOffsetX:0 y:0 height:100 width:100];
 ARRenderTarget *renderTarget = [[ARRenderTarget alloc] initWithWidth:100 height:100];
 [renderTarget addViewPort:viewPort];
 @endcode
 
 @param viewPort The viewport to add.
 */
- (void)addViewPort:(ARViewPort *)viewPort;

/**
 Add a viewport to this render target and set its z-order.
 
 Example of use:
 @code
 ARViewPort *viewPort = [[ARViewPort alloc] initWithOffsetX:0 y:0 height:100 width:100];
 ARRenderTarget *renderTarget = [[ARRenderTarget alloc] initWithWidth:100 height:100];
 [renderTarget addViewPort:viewPort zOrder:-10];
 @endcode
 
 @param viewPort The viewport to add.
 @param zOrder The render priority of this viewport. Any value is fine, lower values are rendered first.
 */
- (void)addViewPort:(ARViewPort *)viewPort zOrder:(NSInteger)zOrder;

/**
 Remove a viewport from this render target.
 
 Example of use:
 @code
 [rederTarget removeViewPort:viewPort];
 @endcode
 
 @param viewPort The viewport to remove.
 */
- (void)removeViewPort:(ARViewPort *)viewPort;

/**
 Remove all viewports from this render target.
 
 Example of use:
 @code
 [renderTarget clearViewPorts];
 @endcode
 */
- (void)clearViewPorts;

/**
 The width, in pixels, of this render target.
 */
@property (nonatomic) float width;

/**
 The height, in pixels, of this render target.
 */
@property (nonatomic) float height;

/**
 Initialise an ARRenderTarget using the given width and height.
 
 Example of use:
 @code
 ARRenderTarget *renderTarget = [[ARRenderTarget alloc] initWithWidth:100 height:100];
 @endcode
 
 @param width The width, in pixels, of the render target.
 @param height The height, in pixels, of the render target.
 */
- (instancetype)initWithWidth:(float)width height:(float)height;

/**
 Creates a default viewport with dimensions matching the resolution of this render target and no offset.
 
 Example of use:
 @code
 ARRenderTarget *renderTarget = [[ARRenderTarget alloc] initWithWidth:100 height:100];
 ARViewPort *viewPort = [renderTarget createDefaultViewPort];
 @endcode
 
 @return The new viewport.
 */
- (ARViewPort *)createDefaultViewPort;

/**
 Add a delegate to receive rendering events for this render target.
 
 Example of use:
 @code
 ARRenderTarget *renderTarget = [[ARRenderTarget alloc] initWithWidth:100 height:100];
 [renderTarget addDelegate:self];
 @endcode
 
 @param delegate ARRenderTargate delegate.
 */
- (void)addDelegate:(id <ARRenderTargetDelegate>)delegate;

/**
 The list of all added delegates.
 */
@property (nonatomic, readonly) NSArray *delegates;

/**
 The priority of this render target relative to other render targets. Any value is fine. Lower is rendered first.
 */
@property (nonatomic) NSInteger priority;

/**
 Take a screenshot of this render target. Resolution of the image is the same as the resolution of the render target.
 
 Example of use:
 @code
 ARRenderTarget *renderTarget = [[ARRenderTarget alloc] initWithWidth:100 height:100];
 UIImage screenshot = [renderTarget screenshot];
 @endcode
 
 @return The screenshot.
 */
- (UIImage *)screenshot;

/**
 Whether this render target has a depth buffer.
 */
@property (nonatomic) BOOL hasDepth;

/**
 Whether this render target has a stencil buffer.
 */
@property (nonatomic) BOOL hasStencil;

/**
 Whether this render target is drawn automatically each frame, or whether it has to be drawn explicitly. Default NO - drawn automatically.
 */
@property (nonatomic) BOOL manualDraw;

/**
 Check frame buffer status.
 **/
- (BOOL)checkFBO;

/**
 Binds frame buffer objects for use in OpenGL.
 **/
- (void)bindBuffer;

/**
 Binds capture frame buffer. Used for touch detection.
 **/
- (void)bindCaptureBuffer;

/**
 Draws render target to screen.
 **/
- (void)draw;

- (void)drawForCapture;

@property (nonatomic) NSDictionary *captureColourToNode;

/**
 Whether the screen has been touched.
 **/
@property (nonatomic) BOOL touchEventReceived;

/**
 Coordinates for where the screen was touched.
 **/
@property (nonatomic) CGPoint touchPoint;



@end
