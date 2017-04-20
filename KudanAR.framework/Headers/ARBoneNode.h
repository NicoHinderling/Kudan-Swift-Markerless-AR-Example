#import <Foundation/Foundation.h>
#import <KudanAR/ARNode.h>

@class ARMatrix4;

/**
 An ARBoneNode is a type of ARNode that represents a bone in a model's mesh.
 They are structures that describe how certain parts of a mesh deform with the movement of a scene node.
 The node describes the current pose of the skeleton.
 These are imported automatically by the Model Importer and are used for skeletal animations.
 */
@interface ARBoneNode : ARNode

/**
 The bone's offset matrix describes the transformation from mesh space to local bone space.
 The node's current transformation in concatenation with its parents describes the inverse transformation.
 Together they form the bone's transformation matrix which can be used to deform vertices.
 */
@property (nonatomic) ARMatrix4 *offsetMatrix;

@end
