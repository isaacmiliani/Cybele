#ifndef RECONSTRUCTION_H
#define RECONSTRUCTION_H

#pragma once
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_types.h>

class reconstruction
{
public:
    /// <summary>
    /// Constructor
    /// </summary>
    reconstruction();

    /// <summary>
    /// Destructor
    /// </summary>
    ~reconstruction();

    /// <summary>
    /// Poisson Surface Reconstruction
    /// </summary>
	bool Poisson(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr mesh);

	/// <summary>
	/// Poisson Surface Reconstruction
	/// </summary>
	bool PoissonAndNormals(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<pcl::Normal>::Ptr normals, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr mesh);
    
	/// <summary>
    /// Greedy Triangulation Reconstruction
    /// </summary>
	bool GreedyProjectionTriangulation(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr triangles);

    /// <summary>
    /// Point Cloud Normal Estimation
    /// </summary>
	bool NormalEstimation(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointcloud, pcl::PointCloud<pcl::Normal>::Ptr normals, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, Eigen::Vector4f centroid);

	/// <summary>
	/// Point Cloud Normal Estimation
	/// </summary>
	bool NormalEstimationOMP(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<pcl::Normal>::Ptr normals, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals);

    /// <summary>
    /// Point Cloud Normal Estimation for Integral Images
    /// </summary>
    bool IntegralImageNormalEstimation(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointcloud, pcl::PointCloud<pcl::Normal>::Ptr normals);

    /// <summary>
    /// Marching Squares Reconstruction
    // Implemented by Greg Borenstein https://github.com/atduskgreg/pcl-marching-squares-example/blob/master/marching_cubes.cpp
    /// </summary>
	bool MarchingSquares(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, float isoLevel, float offSurfaceDisplacement, float gridResolution, pcl::PolygonMesh::Ptr triangles);

    /// <summary>
    /// Marching Cubes  Reconstruction
    // Post in http://www.pcl-users.org/Marching-cubes-td3407519.html
    /// </summary>
	bool MarchingCubes(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, double leafSize, double isoLevel, pcl::PolygonMesh::Ptr triangles);

	/// <summary>
	///Grid Projection
	// Post in http://www.pcl-users.org/Surface-construction-with-grid-projection-td3567834.html
	/// </summary>
	bool GridProjection(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr triangles);

	/// <summary>
	///Normals KdTree
	// Post in https://books.google.co.ve/books?id=JWngSz0L_AEC&pg=PA162&lpg=PA162&dq=point+cloud+normals+kinect+PCL&source=bl&ots=AYFOF3zPdm&sig=aAkfxGENfXetrnrk0V6XLriVNdY&hl=es-419&sa=X&ved=0ahUKEwjLl6XlmdXLAhWCKz4KHREbDHQQ6AEIRjAF#v=onepage&q=point%20cloud%20normals%20kinect%20PCL&f=false
	/// </summary>
	bool NormalsKSearch(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud, pcl::PointCloud<pcl::Normal>::Ptr normals, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals);

	/// <summary>
	/// Compute approximate surface normals on a mesh.
	// Post in http://docs.pointclouds.org/trunk/namespacepcl_1_1features.html#a8ddefbc073fdcbbafc592b2c50361156
	/// </summary>
	bool ComputeApproximateNormals(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PolygonMesh::Ptr mesh, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, Eigen::Vector4f centroid);

	/// <summary>
	/// OrganizedFastMesh
	// Post in http://docs.pointclouds.org/trunk/classpcl_1_1_organized_fast_mesh.html
	/// </summary>
	bool OrganizedFastMesh(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr triangles);
};

#endif // RECONSTRUCTION_H
