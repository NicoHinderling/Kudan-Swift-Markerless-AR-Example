#import <Foundation/Foundation.h>
#import <KudanAR/ARNode.h>

@class ARMaterial;
@class ARMesh;
@class ARTexture;

/**
 An ARMeshNode is a subclass of ARNode that represents a drawable mesh. The geometry to be used, as well as its shading, is specified via this node.
 */
@interface ARMeshNode : ARNode

/**
 The mesh geometry to use. Meshes can be shared between ARMeshNode objects.
 */
@property (nonatomic) ARMesh *mesh;

/**
 The material to use for shading the mesh attached to this node. nil materials will not be drawn. Materials can be shared between ARMeshNode objects.
 
 Example of how to set a material:
 @code
 ARModelImporter *importer = [[ARModelImporter alloc] initWithBundled:@"example.armodel"];
 ARModelNode *modelNode = [importer getNode];
 
 ARLightMaterial *lightMaterial = [[ARLightMaterial alloc] init];
 lightMaterial.ambient.value = [ARVector3 vectorWithValues:0.7];
 lightMaterial.colour.value = [ARVector3 vectorWithValuesX:0.6 y:0.6 z:0.6];
 
 for (ARMeshNode *meshNode in modelNode.meshNodes)
 {
    meshNode.material = lightMaterial;
 }
 @endcode
 */
@property (nonatomic) ARMaterial *material;
/**
 Creates a square test mesh with a RGB colour material and dimensions of 10x10.
 
 @param red Colour value between 0..1.
 @param green Colour value between 0..1.
 @param blue Colour value between 0..1.
 @return ARMeshNode
 **/
+ (instancetype)testMeshNodeWithRed:(float)red green:(float)green blue:(float)blue;

/**
 Creates a square test mesh with dimensions of 100x100.
 
 @param texture The texture used to colour the mesh.
 @return ARMeshNode
 **/
+ (instancetype)testMeshNodeWithTexture:(ARTexture *)texture;

/**
 Creates a mesh with a textured material and dimensions of Width x Height.
 .
 @param texture The texture used to colour the mesh
 @param width Mesh width.
 @param height Mesh height.
 @return ARMeshNode
**/ 
+ (instancetype)meshNodeWithTexture:(ARTexture *)texture width:(float)width height:(float)height;

/**
 Creates a mesh with a RGB colour material and dimensions of Width x Height.
 @param red Colour value between 0..1.
 @param green Colour value between 0..1.
 @param blue Colour value between 0..1.
 @param width Mesh width.
 @param height Mesh height.
 @return ARMeshNode
 **/
+ (instancetype)meshNodeWithRed:(float)red green:(float)green blue:(float)blue width:(float)width height:(float)height;

/**
 Sets facet culling. The type of facet culling is set in ARMaterial. Default is NO.
 **/
@property (nonatomic) BOOL cull;

@end
