#import <Foundation/Foundation.h>
#import <KudanAR/ARNode.h>
#import <KudanAR/ARModelNode.h>

/**
 The ARModelImporter Class imports 3D models from the binary format. Models must be in the .armodel format.
 .fbx, .obj and .dae model files can be converted to .armodel via the Kudan AR Toolkit, available at https://www.kudan.eu/download-kudan-ar-sdk/.
 */
@interface ARModelImporter : NSObject

/**
 Initialises the importer with a full path name pointing to a .armodel file. The file path is absolute.
 
 Example of use:
 @code
 NSString *filePath = [[[NSBundle mainBundle] resourcePath] stringByAppendingString:@"example.armodel"];
 ARModelImporter *modelImporter = [[ARModelImporter alloc] initWithPath:filePath];
 @endcode
 
 @param path The full pathname of the model file's location, including file extension.
 
 @return The initialised model importer.
 */
- (instancetype)initWithPath:(NSString *)path;

/**
 Initialises the importer with a .armodel file located in the app bundle. The file path is relative to the app bundle.
 
 Example of use:
 @code
 ARModelImporter *modelImporter = [[ARModelImporter alloc] initWithBundled:@"Assets/example.armodel"];
 @endcode
 
 @param path The filename relative to the app's main bundle, including file extension. For example, such a path might be:
 "Assets/example.armodel"
 
 @return The initialised model importer.
 */
- (instancetype)initWithBundled:(NSString *)file;

/**
 Gets the node representing the model imported from the file. If all textures from the model are included in the main bundle, they will automatically be applied to the model's meshes.
 
 Example of use:
 @code
 ARModelImporter *modelImporter = [[ARModelImporter alloc] initWithBundled:@"example.armodel"];
 ARModelNode *modelNode = [modelImporter getNode];
 @endcode
 
 @return The a Node representing the imported model.
 */
- (ARModelNode *)getNode;

/**
 The complete list of all ARMeshNodes imported from the model file.
 */
@property () NSMutableArray *meshNodes;

@end
