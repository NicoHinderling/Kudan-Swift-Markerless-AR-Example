#import <Foundation/Foundation.h>
#import <KudanAR/ARRenderTarget.h>

@class ARTexture;

/**
 A render target backed by a texture that can be used in further rendering.
 */
@interface ARRenderTargetTexture : ARRenderTarget

/**
 The ARTexture this render target renders to.
 */
@property (nonatomic) ARTexture *texture;

/**
 Initialise this render target texture with the given dimensions.
 
 Example of use:
 @code
 ARRenderTargetTexture *renderTargetTexture = [[ARRenderTargetTexture alloc] initWithWidth:100 height:100];
 @endcode
 
 @param width The width of the texture.
 @param height The height of the texture.
 
 @return The initialised render target texture.
 */
- (instancetype)initWithWidth:(float)width height:(float)height;

@end
