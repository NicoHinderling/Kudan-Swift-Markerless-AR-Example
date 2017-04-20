#import <KudanAR/ARNode.h>

@class ARImageTrackable;

/**
 An ARMultiTrackableNode is a type of ARNode that reparents itself to different trackable worlds.
 This allows different markers to display the same content without having to duplicate that content.
 */
@interface ARMultiTrackableNode : ARNode

/**
 Adds a trackable to the list of trackables that this node will attach itself to when detected.
 This method adds one trackable at a time.

 Example of use:
 @code
 ARImageTrackable *trackable1 = [[ARImageTrackable alloc] initWithBundledFile:@"example1.jpg"];
 ARImageTrackable *trackable2 = [[ARImageTrackable alloc] initWithBundledFile:@"example2.jpg"];
 ARMultiTrackableNode *multiNode = [[ARMultiTrackableNode alloc] init];
 [multiNode addTrackable:trackable1];
 [multiNode addTrackable:trackable2];
 @endcode
 
 @param trackable The trackable to add.
 */
- (void)addTrackable:(ARImageTrackable *)trackable;

/**
 Removes a trackable from the list of trackables and no longer reparents itself to it once detected.
 This method removes one trackable at a time.

 Example of use:
 @code
 [multiNode removeTrackable:trackable2];
 @endcode
 
 @param trackable The trackable to remove.
 */
- (void)removeTrackable:(ARImageTrackable *)trackable;

/**
 The list of all trackables this node follows.
 */
@property (nonatomic) NSArray *trackables;

@end
