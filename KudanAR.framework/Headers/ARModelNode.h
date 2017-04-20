#import <Foundation/Foundation.h>
#import <Kudanar/ARNode.h>

@class ARModelNode;
@class ARMeshNode;

/**
 A protocol for animation related events.
 */
@protocol ARAnimationDelegate <NSObject>

@optional

/**
 Event method called when the animation attached to this model finishes.
 
 @param modelNode Reference to this model node, the one the animation is attached to.
 */
- (void)animationDidFinish:(ARModelNode *)modelNode;

/**
 Event method called each frame the animation attached to this model renders.
 
 @param modelNode Reference to this model node, the one the animation is attached to.
 @param time The amount of time, in seconds, since the start of the animation.
 */
- (void)animationDidRender:(ARModelNode *)modelNode time:(NSTimeInterval)time;

@end


/**
 The ARModelNode is a node that represents an imported 3D model. It is capable of displaying animations and is the channel for controlling these animations.
 */
@interface ARModelNode : ARNode

@property (nonatomic) NSArray *nodes;

/**
 A list of all the meshes that construct and are rendered by the model node.
 */
@property (nonatomic) NSArray *meshNodes;

/**
 Finds mesh node with a given name belonging to this model node.
 
 @param name Mesh node name.
 @return ARMeshNode
 */
- (ARMeshNode *)findMeshNode:(NSString *)name;

/**
 Whether or not this animation should loop automatically once it ends.
 If YES, the animation will reset and start from the beginning after it renders the final frame.
 If NO, the last frame of the animation will be continually rendered on the model once it finishes.
 */
@property (nonatomic) BOOL shouldLoop;

/**
 Model animation channels.
 */
@property (nonatomic) NSMutableArray *channels;

/**
 Model blend animation channels.
 */
@property (nonatomic) NSMutableArray *blendChannels;

/**
 The delegate object to receive ARAnimationDelegate protocol messages.
 */
@property (nonatomic, weak) id delegate;

/**
 Starts the animation. Resumes from the current play time.
 
 Example of use:
 @code
 // self.modelNode - Model Node imported earlier using the ARModelImporter.
 [self.modelNode start];
 @endcode
 */
- (void)start;

/**
 Stops the animation. The current play time remains the same.
 
 Example of use:
 @code
 // self.modelNode - Model Node imported earlier using the ARModelImporter.
 [self.modelNode stop];
 @endcode
 */
- (void)stop;

/**
 Resets the play time of the animation to 0. This will cause the animation to play from the beginning.
 This can be called whether the animation is playing or has stopped, but if the animation is stopped, it will maintain the frame it stopped at until it is resumed,
 at which point it will start from the beginning.
 
 Example of use:
 @code
 // self.modelNode - Model Node imported earlier using the ARModelImporter.
 [self.modelNode reset];
 */
- (void)reset;

/**
 The current animation time, in seconds.
 Setting this value will change the animation position.
 */
@property (nonatomic) NSTimeInterval currentAnimationTime;

/**
 The amount of time, in seconds, to wait until resetting the animation.
 Only applies if this node isn't being rendered.
 */
@property (nonatomic) NSTimeInterval resetThreshold;

@end
