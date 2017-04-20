#import <Foundation/Foundation.h>
#import <KudanAR/ARRenderTarget.h>
#import <UIKit/UIKit.h>

@class UIView;

/**
 A render target representing the main view. Backing provided by the OS.
 */
@interface ARRenderTargetMain : ARRenderTarget

/**
 Initialise with an existing view, which is responsible for the backing.
 
 Example of use:
 @code
 ARRenderTargetMain *renderTargetMain = [[ARRenderTargetMain alloc] initWithView:self.view];
 @endcode
 
 @param view The UIView to use for backing.
 
 @return The initialised render target.
 */
- (instancetype)initWithView:(UIView *)view;

/**
 The UIView that backs this render target.
 */
@property (nonatomic, weak) UIView *view;

/**
 Whether this render target renders at retina resolution.
 */
@property (nonatomic, readonly) BOOL isRetina;

/**
 Touch was received on this render target.
 
 @param point The coordinates in the render target of the touch location.
 */
- (void)didReceiveTouch:(CGPoint)point;

@end
