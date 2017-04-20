#import <Foundation/Foundation.h>
#import <KudanAR/KudanAR.h>
#import <KudanAR/ARCameraView.h>

/**
 The ARCameraViewController is a subclass of the UIViewController, used for displaying AR content. It handles the initialisation and setup of the camera and viewports.
 Make sure any View Controllers in your storyboard used to display AR content are a subclass of ARCameraViewController.
 */
@interface ARCameraViewController : UIViewController

/**
 The ARCameraView associated with this view controller.
 */
@property (nonatomic) ARCameraView *cameraView;

/**
 Empty method called when an ARCameraViewController is loaded. This must be overriden in user-defined subclass in order to setup AR content.
 **/
- (void)setupContent;

/**
 Method called when the camera starts. Calls setupContent if it hasn't all ready been called.
 **/
- (void)doInitialContentSetup;

@end
