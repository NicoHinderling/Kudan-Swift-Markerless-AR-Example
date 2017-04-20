#import <Foundation/Foundation.h>

@class ARRenderer;
@class ARVertexBuffer;
@class ARMeshNode;

/**
 A class representing the geometry and mapping of a mesh.
 */
@interface ARMesh : NSObject

/**
 The vertex buffer used by the mesh.
 */
@property (nonatomic) ARVertexBuffer *vertexBuffer;

/**
 The index buffer used by the mesh.
 */
@property (nonatomic) unsigned indexBuffer;

/**
 The total number of triangles in this mesh. A good number of triangles to aim for is 100,000.
 */
@property (nonatomic, readonly) NSUInteger numberOfIndices;

/**
 The total number of vertices in this mesh. 
 During the model conversion process in the Kudan AR Toolkit, any meshes exceeding 65535 (2^16 - 1) vertices will be split into multiple separate meshes.
 */
@property (nonatomic) unsigned numberOfVertices;

/**
 The size of each vertex in this mesh.
 */
@property (nonatomic) unsigned vertexStride;

/**
 Prepares the renderer for drawing the mesh.
 */
- (void)prepareRenderer:(ARRenderer *)renderer meshNode:(ARMeshNode *)meshNode;

/**
 Creates a 10x10 flat mesh.
 */
+ (id)testMesh;

/**
 Creates a 100x100 flat mesh and UV map with coordinates in range(0..1,0..1).
 */
+ (id)testMeshWithUV;

/**
 Whether the mesh has normals in its vertex data.
 */
@property (nonatomic) BOOL hasNormals;

/**
 Whether this mesh has tangents in its vertex data.
 */
@property (nonatomic) BOOL hasTangents;

/**
 Whether the mesh has UVs in its vertex data. If it doesn't, materials with textures shouldn't be used.
 */
@property (nonatomic) BOOL hasUVs;

/**
 Whether the mesh has bones in its vertex data.
 */
@property (nonatomic) BOOL hasBones;

/**
 Whether this mesh has blend shape deformers.
 */
@property (nonatomic) BOOL hasBlendShapes;

/**
 Creates a flat mesh with UV map with coordinates in range(0..1,0..1).
 
 @param width Mesh width.
 @param height Mesh height.
 */
+ (instancetype)texturedMeshWidth:(float)width height:(float)height;

/**
 Creates a flat mesh.
 
 @param width Mesh width.
 @param height Mesh height.
 */
+ (instancetype)meshWithWidth:(float)width height:(float)height;

/**
 Initialises mesh from vertex and index data. Also sets mesh parameters.
 
 @param vertexData Mesh vertex data.
 @param indexData Mesh indicies.
 @param hasNormals If the mesh has vertex normals in its vertex data.
 @param hasUVs If the mesh has a UVs in its vertex data.
 @return ARMesh.
 */
- (instancetype)initWithVertexData:(NSData *)vertexData indexData:(NSData *)indexData hasNormals:(BOOL)hasNormals hasUVs:(BOOL)hasUVs;


/**
 Initialises mesh from vertex and index data. Also sets mesh parameters.
 
 @param vertexData Mesh vertex data.
 @param indexData Mesh index data.
 @param hasNormals If the mesh has vertex normals.
 @param hasUVs If the mesh has a UVs in its vertex data.
 @param hasUVs2 If the mesh has a two sets of UVs in its vertex data.
 @param hasTangents If the mesh has vertex tangents in its vertex data.
 @param maxBones The maximum number of bones in the mesh.
 @return ARMesh
 */
- (instancetype)initWithVertexData:(NSData *)vertexData indexData:(NSData *)indexData hasNormals:(BOOL)hasNormals hasUVs:(BOOL)hasUVs hasUVs2:(BOOL)hasUVs2 hasTangents:(BOOL)hasTangents maxBones:(unsigned)maxBones;

/**
 Initialises mesh from vertex and index data. Also sets mesh parameters.
 
 @param vertexData Mesh vertex data.
 @param indexData Mesh indicies.
 @param hasNormals If the mesh has vertex normals in its vertex data.
 @param hasUVs If the mesh has a UVs in its vertex data.
 @param maxBones The maximum number of bones in the mesh.
 @return ARMesh
 */
- (instancetype)initWithVertexData:(NSData *)vertexData indexData:(NSData *)index12Data hasNormals:(BOOL)hasNormals hasUVs:(BOOL)hasUVs maxBones:(unsigned)maxBones;

/**
 Initialises mesh with indicies, normals, UVs and indicies.
 
 @param vertices Mesh verticies.
 @param normals Mesh normals.
 @param UVs Mesh's UV map.
 @param indices Mesh vertices.
 @return ARMesh
 */
- (instancetype)initWithVertices:(NSData *)vertices normals:(NSData *)normals UVs:(NSData *)UVs indices:(NSData *)indices;

/**
 Creates vertex data from verticies, UVs and indicies.
 
 @param vertices Mesh vertices.
 @param UVs Mesh UV map.
 @param indices Mesh indicies.
 @return NSData
 */

- (NSData *)createVertexDataWithVertices:(NSData *)vertices UVs:(NSData *)UVs indices:(NSData *)indices;

/**
 Initialises mesh with empty vertex buffer.
 
 @return ARMesh
 */
- (instancetype)initWithEmpty;

/**
 Set mesh vertex data.
 
 @param vertexData Mesh vertex data.
 */
- (void)setVertexData:(NSData *)vertexData;

/**
 Initialises flat mesh with UV map with coordinates in range(0..1,0..1).
 
 @param width Mesh width.
 @param height Mesh height.
 */
- (instancetype)initWithTestMeshWithUV:(float)width height:(float)height;

/**
 Initialises flat mesh with UV map with coordinates in range(0..u,0...v).
 
 @param width Mesh width.
 @param height Mesh height.
 @param u UV map width.
 @param v UV map height.
 */
- (instancetype)initWithTestMeshWithUV:(float)width height:(float)height u:(float)u v:(float)v;

/**
 The list of ARBoneNodes that are part of this mesh. There is a limit of 64 bones per mesh.
 */
@property (nonatomic) NSMutableArray *bones;

@end
