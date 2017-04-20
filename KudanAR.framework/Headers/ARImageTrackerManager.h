#import <Foundation/Foundation.h>

@class ARImageTrackable;
@class ARImageTrackableSet;
@class ARNode;

/**
 Manager singleton for the image tracker. The image tracker is capable of detecting pre-registered 2D images within the camera stream.
 */
@interface ARImageTrackerManager : NSObject

/**
 Get the Image Tracker singleton.
 
 Example of use:
 @code
 ARImageTrackerManager *imageTracker = [ARImageTrackerManager getInstance];
 @endcode
 
 @return The singleton instance.
 */
+ (ARImageTrackerManager *)getInstance;

/**
 Initialise the Image Tracker. This method should only be called once during setup.
 When the Image Tracker is initialised, it performs the following:
 * A new ARNode is created to become the tracker's base node.
 * An empty list of trackables is created.
 * A reference to the native ImageTracker interface is made and the the interface is initialised.
 
 Example of use:
 @code
 [[ARImageTrackerManager getInstance] initialise];
 @endcode
 */
- (void)initialise;

/**
 Deinitialise the Image Tracker. This method should only be called once during cleanup, ideally when the AR View Controller is being dismissed.
 When the Image Tracker is denitialised, it performs the following:
 * The native ImageTracker interface is deinitialised.
 * The list of trackables is emptied.
 * The list of detected trackables is emptied, meaning any markers currently being detected will be lost, and any nodes that are currently visible will stop being rendered.
 * The base node is reset with a new ARNode.

 Example of use:
 @code
 [[ARImageTrackerManager getInstance] deinitialise];
 @endcode
 */
- (void)deinitialise;

/**
 Add a trackable to the image tracker so that it may be detected. The trackable's name must be unique compared to the currently added trackables.
 
 Example of use:
 @code
 ARImageTrackable *trackable = [[ARImageTrackable alloc] initWithImage:[UIImage imageNamed:@"example.jpg"] name:"Example Marker"];
 [[ARImageTrackerManager getInstance] addTrackable:trackable];
 @endcode
 
 @param trackable The trackable to add.
 
 @return YES if the marker was successfully created and added to the tracker, NO otherwise.
 */
- (BOOL)addTrackable:(ARImageTrackable *)trackable;

/**
 Remove a trackable from the image tracker. This trackable will no longer be detected.
 
 Example of use:
 @code
 [[ARImageTrackerManager getInstance] removeTrackable:trackable];
 @endcode
 
 @param trackable The trackable to remove.
 */
- (void)removeTrackable:(ARImageTrackable *)trackable;

/**
 Add a set of trackables to the image tracker so they may be detected.
 
 Example of use:
 @code
 ARImageTrackableSet *trackableSet = [[ARImageTrackableSet alloc] initWithBundledFile:@"example.KARMarker"];
 [[ARImageTrackerManager getInstance] addTrackableSet:trackableSet];
 @endcode
 
 @param set The set of trackables to add. This must be in the .KARMarker format.
 */
- (void)addTrackableSet:(ARImageTrackableSet *)set;

/**
 The list of all registered trackables. The order of the list will be the order they were added in, with the most recently added trackable being the last element.
 */
@property (readonly) NSArray *trackables;

/**
 The number of trackables detected in the last processed frames.
 */
@property (readonly) int numberOfDetectedTrackables;

/**
 The list of detected ARImageTrackable objects from the last processed frame.
 */
@property (readonly) NSArray *detectedTrackables;

/**
 Find a trackable registered with the tracker by its name.
 
 Example of use:
 @code
 ARImageTrackable *trackable =  [[ARImageTrackerManager getInstance] imageTracker findTrackableByName:@"example"];
 @endcode
 
 @param name The name of the trackable to find.
 
 @return The matching trackable, or nil if not found.
 */
- (ARImageTrackable *)findTrackableByName:(NSString *)name;

/**
 Passes Camera data to KudanCV for processing. This is called everyframe.
 @param data Camera data.
 @param width Camera width.
 @param height Camera height.
 @param padding Camera padding.
 **/
- (void)process:(NSData *)data width:(int)width height:(int)height padding:(int)padding;

/**
 This node is the parent of all trackable worlds. It can be used to toggle visibility of all markers or as a touch target to receive touches on any marker.
 */
@property (nonatomic) ARNode *baseNode;

/**
 Whether the tracker is initialised or not.
 */
@property (nonatomic) BOOL isInitialised;

/**
 Start the Image Tracker. The Image Tracker must have first been initialised before starting, or it will not work.
 
 Example of use:
 @code
 [[ARImageTrackerManager getInstance] start];
 @endcode
 */
- (void)start;

/**
 Stop the Image Tracker. Any visible objects on-screen will stop rendering at this time.
 
 Example of use:
 @code
 [[ARImageTrackerManager getInstance] stop];
 @endcode
 */
- (void)stop;

/** 
 Set the maximum number of trackables which can be tracked at the same time.
 If the maximum number of markers is already being tracked, further markers will not be detected.
 This does not affect the number of trackables which can be loaded at the same time.
 Set to a value of 0 for an unlimited number of concurrent tracked markers. This is the default value.
 
 Example of use:
 @code
 [[ARImageTrackerManager getInstance] setMaximumSimultaneousTracking:3];
 @endcode
 
 @param maxToTrack The maximum numbers of trackables which can be tracked simultaneously.
 */
- (void)setMaximumSimultaneousTracking:(int)maxToTrack;


/**
 Set whether recovery mode is enabled, for all trackables. This can be overridden on a per-trackable basis by using the force- and prohibit- functions of KudanImageTrackable.
 
 Example of use:
 @code
 [[ARImageTrackerManager getInstance] setRecoveryMode:YES];
 @endcode
 
 @param doRecovery Whether recovery mode is used (YES) or not (NO).
 */
- (void)setRecoveryMode:(BOOL)doRecovery;

/**
 Query whether recovery mode is on, for all trackables in general. This could be overridden for individual trackables.
 
 Example of use:
 @code
 BOOL recoveryStatus = [[ARImageTrackerManager getInstance] imageTracker queryRecoveryMode];
 @endcode
 
 @return Whether recovery mode is used (YES) or not (NO).
 */
- (BOOL)queryRecoveryMode;

/**
 Prohibit recovery mode for all trackables (ignoring the global setting).
 
 Example of use:
 @code
 [[ARImageTrackerManager getInstance] prohibitRecoveryMode];
 @endcode
 */
- (void)prohibitRecoveryMode;

/**
 For an individual trackable, query whether it is able to use recovery mode (depends on the global setting and the trackable's own setting).
 
 Example of use:
 @code
 ARImageTrackerManager *imageTracker = [ARImageTrackerManager getInstance];
 ARImageTrackable *trackable = [[ARImageTrackable alloc] initWithImage:[UIImage imageNamed:@"example.jpg"] name:@"Example Marker"];
 [imageTracker setRecoveryMode:NO];
 [trackable forceRecoveryMode];
 BOOL globalRecoveryEnabled = [imageTracker queryRecoveryMode];
 BOOL exampleMarkerRecoveryEnabled = [imageTracker queryRecoveryMode:trackable];
 @endcode
 
 globalRecoveryEnabled will return NO.
 exampleMarkerRecoveryEnabled will return YES.
 
 @param trackable The trackable for which recovery mode is being queried.
 
 @return Whether recovery mode is used (YES) or not (NO) for this one trackable.
 */
- (BOOL)queryRecoveryMode:(ARImageTrackable *)trackable;


/**
 Set whether marker detection is parallelised (for simultaneous detection of multiple trackables) or not.
 The number of threads is not controllable but set automatically for the device.
 
 Example of use:
 @code
 [[ARImageTrackerManager getInstance] toggleParallelDetection:YES];
 @endcode
 
 @param isParallel Set whether detection can run in parallel (YES) or not (NO).
 */
-(void) toggleParallelDetection:(bool)isParallel;

/**
 Query whether marker detection is parallelised (for simultaneous detection of multiple trackables) or not.
 
 Example of use:
 @code
 BOOL isParallel = [[ARImageTrackerManager getInstance] isDetectorParallel];
 @endcode
 
 @return Boolean indicating whether detection can run in parallel or not.
*/
-(BOOL) isDetectorParallel;


@end
