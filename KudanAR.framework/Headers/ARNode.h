#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ARMatrix4;
@class ARVector3;
@class ARQuaternion;
@class ARRenderer;

/**
 An ARNode represents the base object of the scene-graph. It is responsible for the spatial layout of content, and is the node type from which all other nodes derive.
 */
@interface ARNode : NSObject <NSCopying>

/**
 Different transformation spaces that the various transformation methods can act in.
 */
typedef NS_ENUM(NSInteger, TransformSpace) {
    /**
     Transform is applied relative to the existing local transform. Translations take the local rotation into account.
     If, for example, an object rotated at 45 degrees were translated to move up in its own local space, it would move diagonally relative to the camera, following the trajectory of the rotation.
     */
    ARNodeTransformSpaceLocal,
    /**
     Transform is applied relative to the parent's transform. Translations are unaffected by the local scale and rotation.
     If, for example, an object rotated at 45 degrees were translated to move up in its parent space, it would move upwards relative to the camera.
     */
    ARNodeTransformSpaceParent,
    /**
     Transform is applied relative to the node's closest ARWorld grandparent. This is useful for moving around in world space.
     If, for example, an object and its child were both rotated 45 degrees, and they were translated both translated upwards in world space, both objects would move upwards relative to the camera.
     */
    ARNodeTransformSpaceWorld,
};

/**
 The name of this node. The name should be unique so that the tracker can find it when using findChildByName.
 */
@property (nonatomic) NSString *name;

/**
 This node's parent node. If it's parent is a root node, this returns nil.
 */
@property (nonatomic, weak) ARNode *parent;

/**
 Array containing all direct child nodes of this node.
 This returns only nodes added to this node as children. Any nodes added to those nodes will not be listed here.
 */
@property (nonatomic, readonly) NSArray<ARNode *> *children;

/**
 Array containing all child nodes of this node.
 This returns nodes added to this node and any nodes added to them, and so on, checking the entire graph. 
 If this is the root node of the graph, this will return all nodes in the graph.
 */
@property (nonatomic, readonly) NSArray *descendants;

/**
 This node's position relative to its parent in the form (X, Y, Z).
 */
@property (nonatomic) ARVector3 *position;

/**
 This node's scale relative to its parent in the form (X, Y, Z).
 */
@property (nonatomic) ARVector3 *scale;

/**
 This node's orientation relative to its parent in the form (X, Y, Z, W).
 */
@property (nonatomic) ARQuaternion *orientation;

/**
 The combination of the local position, scale and orientation of this node.
 */
@property (nonatomic, readonly) ARMatrix4 *localTransform;

/**
 The transformation of the nearest ARWorld that this node descends from.
 */
@property (nonatomic, readonly) ARMatrix4 *worldTransform;

/**
 The full transformation of this node in eye space.
 */
@property (nonatomic, readonly) ARMatrix4 *fullTransform;

/**
 The full orientation of this node in eye space.
 */
@property (nonatomic, readonly) ARQuaternion *fullOrientation;

/**
 The orientation of this node in the space of the nearest ARWorld this node descends from.
 */
@property (nonatomic, readonly) ARQuaternion *worldOrientation;

/**
 The scale of this node in the space of the nearest ARWorld this node descends from.
 */
@property (nonatomic, readonly) ARVector3 *worldScale;

/**
 The position of this node in the space of the nearest ARWorld this node descends from.
 */
@property (nonatomic, readonly) ARVector3 *worldPosition;

/**
 The full orientation of this node in eye space.
 */
@property (nonatomic, readonly) ARVector3 *fullPosition;


/**
 The ARWorld this node descends from.
 */
@property (nonatomic) ARNode *world;

/**
 Adds a node as a child of this node. Any transformations applied to a node also apply to all its children.
 
 Example of use:
 @code
 ARNode *parentNode = [ARNode nodeWithName:@"parentNode"];
 ARNode *childNode = [ARNode nodeWithName:@"childNode"];
 [parentNode addChild:childNode];
 @endcode
 
 @param child The node to be added.
 */
- (void)addChild:(ARNode *)child;

/**
 Add a list of nodes as children of this node.
 
 Example of use:
 @code
 ARNode *parentNode = [ARNode nodeWithName:@"parentNode"];
 ARNode *child1Node = [ARNode nodeWithName:@"child1Node"];
 ARNode *child2Node = [ARNode nodeWithName:@"child2Node"];
 NSArray *childNodes = @[child1Node, child2Node];
 [parentNode addChildren:childNodes];
 @endcode
 
 @param children The array of nodes to be added.
 */
- (void)addChildren:(NSArray *)children;

/**
 Remove a node from this node's children.
 
 Example of use:
 @code
 [parentNode removeChild:childNode];
 @endcode
 
 @param child The node to be removed.
 */
- (void)removeChild:(ARNode *)child;

/**
 Remove all children from this node.
 
 Example of use:
 @code
 [parentNode removeAllChildren];
 @endcode
 */
- (void)removeAllChildren;

/**
 Remove this node from its parent node.
 
 Example of use:
 @code
 [childNode remove];
 @endcode
 */
- (void)remove;

/**
 Find a child of this node with the given name. 
 If there are multiple child nodes with the same name, they cannot be found using this method, as it will always return the first one.
 In order to be able to find all child nodes, they must all have unique names.
 
 Example of use:
 @code
 [parentNode findChildWithName:@"childNode"];
 @endcode
 
 @param name The name of the node to search for.
 
 @return The first ARNode in the list with the given name, or nil if no Node with the given name is found.
 */
- (ARNode *)findChildWithName:(NSString *)name;

/**
 The number of direct children this node has. This is the number of elements in the children array.
 */
@property (nonatomic, readonly) NSUInteger childCount;

- (void)markWorldTransformAsDirty;

/**
 Translate the position of this node by a number of units in each axis in local space.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node translateByX:10 y:20 z:30];
 @endcode
 
 @param x units to translate along the x-axis.
 @param y units to translate along the y-axis.
 @param z units to translate along the z-axis.
 */
- (void)translateByX:(float)x y:(float)y z:(float)z;

/**
 Translate the position of this node by a number of units in each axis, relative to the given transform space.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node translateByX:10 y:20 z:30 transformSpace:ARNodeTransformSpaceParent];
 @endcode
 
 @param x Units to translate along the x-axis.
 @param y Units to translate along the y-axis.
 @param z Units to translate along the z-axis.
 @param transformSpace The specified TransformSpace determines the coordinate system of the units.
 Local space to translate the node relative to its own transform.
 Parent space to translate the node relative to its parent's transform.
 World space to translate the node relative to the nearest ARWorld's transform.
 */
- (void)translateByX:(float)x y:(float)y z:(float)z transformSpace:(TransformSpace)transformSpace;

/**
 Translate the position of this node by the given vector in local space.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 ARVector3 *vector = [ARVector3 vectorWithValuesX:10 y:20 z:30];
 [node translateByVector:vector];
 @endcode
 
 @param translation A vector containing the x, y and z units to translate by.
 */
- (void)translateByVector:(ARVector3 *)translation;

/**
 Translate the position of this node by the given vector, relative to the given transform space.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 ARVector3 *vector = [ARVector3 vectorWithValuesX:10 y:20 z:30];
 [node translateByVector:vector transformSpace:ARNodeTransformSpaceParent];
 @endcode
 
 @param translation A vector containing the x, y and z units to translate by.
 @param transformSpace the specified TransformSpace determines the coordinate system of the units.
 */
- (void)translateByVector:(ARVector3 *)translation transformSpace:(TransformSpace)transformSpace;

/**
 Scales the node uniformly across each axis. This does not set the scale, but rather adds to the existing scales by the given amount.
 For example, if you scale a node by 2, then by 4, its overall scale will be 8 times bigger. Likewise, if you scale by 0.5, then by 0.5 again, the overall scale will be 0.25 times bigger, or 4 times smaller.
 Scaling occurs in the node's local space.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node scaleByUniform:2];
 @endcode
 
 @param scale The amount to scale by.
 */
- (void)scaleByUniform:(float)scale;

/**
 Scales the node separately along each axis. Scale can be non-uniform.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node scaleByX:1 y:2 z:3];
 @endcode
 
 @param x The amount to scale in the x-axis.
 @param y The amount to scale in the y-axis.
 @param z The amount to scale in the z-axis.
 */
- (void)scaleByX:(float)x y:(float)y z:(float)z;

/**
 Scale this node separately along each axis using values taken from a vector. Scale can be non-uniform. Scaling occurs in the node's local space.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node scaleByVector:[ARVector3 vectorWithValuesX:1 y:2 z:3]];
 @endcode
 
 @param scale A vector containing the x, y and z scale factors.
*/
- (void)scaleByVector:(ARVector3 *)scale;

/**
 Rotate this node by the given number of degrees around each noted axis.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node rotateByDegrees:90 axisX:1 y:0 z:1];
 @endcode
 
 @param angle The angle, in degrees, to rotate by.
 @param x Whether or not to rotate about this node's X axis. 0 for no, 1 for yes.
 @param y Whether or not to rotate about this node's Y axis. 0 for no, 1 for yes.
 @param z Whether or not to rotate about this node's Z axis. 0 for no, 1 for yes.
 */
- (void)rotateByDegrees:(float)angle axisX:(float)x y:(float)y z:(float)z;

/**
 Rotate this node by the given number of radians around each noted axis.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node rotateByRadians:M_PI_2 axisX:0 y:1 z:0];
 @endcode
 
 @param angle The angle, in radians, to rotate by.
 @param x Whether or not to rotate about this node's X axis. 0 for no, 1 for yes.
 @param y Whether or not to rotate about this node's Y axis. 0 for no, 1 for yes.
 @param z Whether or not to rotate about this node's Z axis. 0 for no, 1 for yes.
 */
- (void)rotateByRadians:(float)angle axisX:(float)x y:(float)y z:(float)z;

/**
 Multiply this node's orientation by a quaternion. For simple rotations, using rotateByDegrees is recommended instead.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node rotateByQuaternion:[ARQuaternion quaternionWithDegrees:90 axisX:1 y:0 z:0]];
 @endcode
 
 @param rotation The quaternion to rotate this node by.
 */
- (void)rotateByQuaternion:(ARQuaternion *)rotation;

/**
 Whether or not this node and all its children should be drawn. If NO, this node and all of its child nodes will not render, even if the child's visibility is set to YES.
 Default is YES.
 */
@property (nonatomic) BOOL visible;

/**
 Convert an ARVector3 position from this node's local space to the nearest world space.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 ARVector3 *worldPosition = [node positionToWorld:node.position];
 @endcode
 
 @param position The position in this node's local space as a vector.
 
 @return The position in world space as a vector.
 */
- (ARVector3 *)positionToWorld:(ARVector3 *)position;

/**
 Convert an ARVector3 position from this node's local space to eye/camera space.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 ARVector3 *eyePosition = [node positionToWorld:node.position];
 @endcode
 
 @param position The position in this node's local space as a vector.
 
 @return The position in eye space as a vector.
 */
- (ARVector3 *)positionToEye:(ARVector3 *)position;
- (ARQuaternion *)orientationToWorld:(ARQuaternion *)orientation;
- (ARQuaternion *)orientationToEye:(ARQuaternion *)orientation;

/**
 Project a point in this node's coordinate space to its position in the ARViewPort this node is attached to.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 CGPoint viewPortPosition = [node viewPortFromNodePosition:node.position];
 @endcode
 
 @param position The 3D position in this node's coordinate space to project.
 
 @return The 2D position in the ARViewPort.
 */
- (CGPoint)viewPortFromNodePosition:(ARVector3 *)position;

/**
 Method called when this node is being rendered.
 */
- (void)render;

/**
 Method called just before this node is rendered.
 */
- (void)preRender;

/**
 Method called just after this node has been rendered.
 */
- (void)postRender;

/**
 Class method that creates a node with the given name.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 @endcode
 
 @param name The name to give this node. Ideally, this will be unique, so that it will always be found correctly when using findChildWithName.
 */
+ (instancetype)nodeWithName:(NSString *)name;

/**
 Add an action that is triggered whenever this node or one of its children is touched.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node addTouchTarget:self withAction:@selector(wasTouched)];
 
 // Then you can implement
 - (void)wasTouched
 {
    // This code will run whenever the node is touched.
 }
 @endcode
 
 @param target The object to receive the event.
 @param action The method to call on the object.
 */
- (void)addTouchTarget:(id)target withAction:(SEL)action;

/**
 Method called whenever this node or one of its children is touched. 
 This shouldn't be altered, instead simply create a new selector to run your code when the event fires.
 */
- (void)didReceiveTouch;

/**
 Unproject a 2D position in the ARViewPort to this nodes coordinate space.
 
 Example of use:
 @code
 ARNode *node = [ARNode nodeWithName:@"example node"];
 [node translateByX:10 y:10 z:10];
 UITouch *touch = [[event allTouches] anyObject];
 CGPoint touchPosition = [touch locationInView:touch.view];
 ARVector3 *intersect = [node nodeFromViewPort:touchPosition];
 @endcode
 
 @param point The 2D position in the viewport.
 
 @return If the given point intersects with the Node, returns the 3D position where the point intersects this node. If the point does not intersect, returns nil.
 */
- (ARVector3 *)nodeFromViewPort:(CGPoint)point;

@end
