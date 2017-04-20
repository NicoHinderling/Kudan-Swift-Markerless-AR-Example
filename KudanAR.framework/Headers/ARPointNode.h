#import <KudanAR/ARMeshNode.h>

@class ARTexture;

/**
 A class used to represent points sprites.
 **/
@interface ARPointNode : ARMeshNode

/**
 Initialise point sprite with texture.
 
 @param texture Point sprite texture.
 **/
- (instancetype)initWithTexture:(ARTexture *)texture;

/**
 Sets mesh vertex data using points and sets number of points.
 
 @param points Points vertex data.
 **/
- (void)setPoints:(NSData *)points;

/**
 Point size default is texture width.
 **/
@property (nonatomic) NSUInteger pointSize;
/**
 Number of points to be rendered.
 **/
@property (nonatomic, readonly) NSUInteger numberOfPoints;

@end
