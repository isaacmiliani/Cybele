// System includes
#define NOMINMAX
#include "reconstruction.h"
#pragma once
#include <stdexcept>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/poisson.h>
#include <pcl/surface/gp3.h>
#include <pcl/surface/mls.h>
#include <pcl/surface/impl/organized_fast_mesh.hpp> 
#include <pcl/surface/organized_fast_mesh.h>
#include <pcl/features/normal_3d_omp.h> // Marching Squares
#include <pcl/search/kdtree.h>
#include <pcl/surface/marching_cubes_rbf.h>
#include <pcl/surface/marching_cubes.h>
#include <pcl/surface/marching_cubes_hoppe.h>
#include <pcl/surface/grid_projection.h>
#include <pcl/features/integral_image_normal.h> // Normal Estimation for Integral Images

using namespace pcl;
reconstruction::reconstruction()
{

}
reconstruction::~reconstruction(){

}

bool reconstruction::Poisson(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr mesh){
    bool hr = true;
	
	pcl::Poisson<pcl::PointXYZRGBNormal> poisson;
	poisson.setDepth(9);
	poisson.setInputCloud(cloud_with_normals->makeShared());
	poisson.performReconstruction(*mesh);
	//poisson.reconstruct(*mesh);
    return hr;
}
bool reconstruction::PoissonAndNormals(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<pcl::Normal>::Ptr normals, pcl::PointCloud<PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr mesh){
	bool hr = true;
	
	MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB> mls;
	mls.setInputCloud(cloud);
	mls.setSearchRadius(0.03);
	mls.setPolynomialFit(true);
	mls.setPolynomialOrder(2);

	mls.setUpsamplingMethod(MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB>::SAMPLE_LOCAL_PLANE);
	mls.setUpsamplingRadius(0.005);
	mls.setUpsamplingStepSize(0.003);
	
	PointCloud<pcl::PointXYZRGB>::Ptr cloud_smoothed(new PointCloud<pcl::PointXYZRGB>());
	mls.process(*cloud_smoothed);
	
	pcl::NormalEstimationOMP<pcl::PointXYZRGB, pcl::Normal> ne;
	ne.setNumberOfThreads(8);
	ne.setInputCloud(cloud_smoothed);
	ne.setRadiusSearch(0.01);
	Eigen::Vector4f centroid;
	compute3DCentroid(*cloud_smoothed, centroid);
	ne.setViewPoint(centroid[0], centroid[1], centroid[2]);

	PointCloud<pcl::Normal>::Ptr cloud_normals(new PointCloud<pcl::Normal>());
	ne.compute(*cloud_normals);
	for (size_t i = 0; i < cloud_normals->size(); ++i)
	{
		cloud_normals->points[i].normal_x *= -1;
		cloud_normals->points[i].normal_y *= -1;
		cloud_normals->points[i].normal_z *= -1;
	}
	
	PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_smoothed_normals(new PointCloud<PointXYZRGBNormal>());
	concatenateFields(*cloud_smoothed, *cloud_normals, *cloud_smoothed_normals);

	pcl::Poisson<pcl::PointXYZRGBNormal> poisson;
	poisson.setDepth(7);
	poisson.setInputCloud(cloud_smoothed_normals);

	pcl::copyPointCloud<pcl::PointXYZRGBNormal, pcl::PointXYZRGBNormal>(*cloud_smoothed_normals, *cloud_with_normals);

	poisson.reconstruct(*mesh);
	

	return hr;
}

/// <summary>
/// Surface Reconstruction by Greedy Triangulation
/// </summary>
bool reconstruction::GreedyProjectionTriangulation(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr triangles){


    bool hr = true;

    //// Create search tree*
    pcl::search::KdTree<pcl::PointXYZRGBNormal>::Ptr tree2(new pcl::search::KdTree<pcl::PointXYZRGBNormal>);
    tree2->setInputCloud(cloud_with_normals);

    //// Initialize objects
    pcl::GreedyProjectionTriangulation<pcl::PointXYZRGBNormal> gp3;

    //// Set the maximum distance between connected points (maximum edge length)
	gp3.setSearchRadius(0.025);

    // Maximum acceptable distance for a point to be considered,
    // relative to the distance of the nearest point.
    gp3.setMu(2.5);
    // How many neighbors are searched for.
	gp3.setMaximumNearestNeighbors(100);

    // Points will not be connected to the current point
    // if their normals deviate more than the specified angle.
    gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees

    // Minimum and maximum angle there can be in a triangle.
    // The first is not guaranteed, the second is.
    gp3.setMinimumAngle(M_PI / 18); // 10 degrees
    gp3.setMaximumAngle(2 * M_PI / 3); // 120 degrees

    // If false, the direction of normals will not be taken into account
    // when computing the angle between them.
    gp3.setNormalConsistency(false);
	// gp3.setConsistentVertexOrdering(true);
	
    // Get result
    gp3.setInputCloud(cloud_with_normals);
    gp3.setSearchMethod(tree2);
    gp3.reconstruct(*triangles);
	
    // Additional vertex information
    std::vector<int> parts = gp3.getPartIDs();
    std::vector<int> states = gp3.getPointStates();

    return hr;

}

/// <summary>
/// Surface Reconstruction by Organized Fast Mesh
/// </summary>
bool reconstruction::OrganizedFastMesh(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr triangles){

	bool hr = true;

	//// Initialize objects
	pcl::OrganizedFastMesh<pcl::PointXYZRGBNormal> fm;

	// Get result
	fm.setInputCloud(cloud_with_normals);
	fm.setTrianglePixelSize(3);
	fm.setTriangulationType(pcl::OrganizedFastMesh<pcl::PointXYZRGBNormal>::QUAD_MESH);
	fm.reconstruct(*triangles);

	return hr;

}

/// <summary>
/// Compute approximate surface normals on a mesh.
/// </summary>
bool reconstruction::ComputeApproximateNormals(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PolygonMesh::Ptr mesh, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, Eigen::Vector4f centroid){
	bool hr = true;
	int nr_points = static_cast<int>(cloud->points.size());
	int nr_polygons = static_cast<int>(mesh->polygons.size());
	
	cloud_with_normals->width = cloud->width;
	cloud_with_normals->height = cloud->height;
	cloud_with_normals->points.resize(nr_points);

	
	compute3DCentroid(*cloud, centroid);
	

	for (int i = 0; i < nr_points; ++i){
		cloud_with_normals->points[i].getNormalVector3fMap() = Eigen::Vector3f::Zero();
	}
	// NOTE: for efficiency the weight is computed implicitly by using the
	// cross product, this causes inaccurate normals for meshes containing
	// non-triangle polygons (quads or other types)
	for (int i = 0; i < nr_polygons; ++i)
	{
		const int nr_points_polygon = (int)mesh->polygons[i].vertices.size();
		if (nr_points_polygon < 3)	continue;

		// compute normal for triangle
		Eigen::Vector3f vec_a_b = cloud->points[mesh->polygons[i].vertices[0]].getVector3fMap() - cloud->points[mesh->polygons[i].vertices[1]].getVector3fMap();
		Eigen::Vector3f vec_a_c = cloud->points[mesh->polygons[i].vertices[0]].getVector3fMap() - cloud->points[mesh->polygons[i].vertices[2]].getVector3fMap();
		Eigen::Vector3f normal = vec_a_b.cross(vec_a_c);
		pcl::flipNormalTowardsViewpoint(cloud->points[mesh->polygons[i].vertices[0]], centroid[0], centroid[1], centroid[2], normal(0), normal(1), normal(2));

		// add normal to all points in polygon
		for (int j = 0; j < nr_points_polygon; ++j){
			cloud_with_normals->points[mesh->polygons[i].vertices[j]].getNormalVector3fMap() += normal;
		}
	}
	
	for (int i = 0; i < nr_points; ++i)
	{
		//std::cout << "BEFORE. " << cloud_with_normals->points[i].normal_x << "," << cloud_with_normals->points[i].normal_y << "," << cloud_with_normals->points[i].normal_z << std::endl;
		
		//cloud->points[i].rgb = (153, 204, 255);
		cloud_with_normals->points[i].getNormalVector3fMap().normalize();
		pcl::flipNormalTowardsViewpoint(cloud->points[i], centroid[0], centroid[1], centroid[2], cloud_with_normals->points[i].normal_x, cloud_with_normals->points[i].normal_y, cloud_with_normals->points[i].normal_z);

		//std::cout << "* AFTER. " << cloud_with_normals->points[i].normal_x << "," << cloud_with_normals->points[i].normal_y << "," << cloud_with_normals->points[i].normal_z << std::endl;
	}
	std::cout << "* CENTROID " << centroid[0] << "," << centroid[1] << "," << centroid[2] << std::endl;
	for (size_t i = 0; i < cloud_with_normals->size(); ++i)
	{
		cloud_with_normals->points[i].normal_x *= -1;
		cloud_with_normals->points[i].normal_y *= -1;
		cloud_with_normals->points[i].normal_z *= -1;
	}
	
	std::cout << "Total normals. " << cloud_with_normals->size() << std::endl;

	return hr;

}

/// <summary>
/// Point Cloud Normal Estimation
/// </summary>
bool reconstruction::NormalEstimation(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<pcl::Normal>::Ptr normals, pcl::PointCloud<PointXYZRGBNormal>::Ptr cloud_with_normals, Eigen::Vector4f centroid){
    
	bool hr = true;
	// Object for normal estimation.
	pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> normalEstimation;
	// A kd-tree is a data structure that makes searches efficient. More about it later.
	// The normal estimation object will use it to find nearest neighbors.
	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZRGB>);
	kdtree->setInputCloud(cloud);
	//Eigen::Matrix<Scalar, 3, 1, 0, 3, 1> &normal;
	pcl::Normal normal;
	normalEstimation.setInputCloud(cloud);
	normalEstimation.setSearchMethod(kdtree);
	
	//normalEstimation.useSensorOriginAsViewPoint();
	// For every point, use all neighbors in a radius of 3cm.
	normalEstimation.setRadiusSearch(0.03);
	//normalEstimation.setKSearch(20);

	// Calculate the normals.
	normalEstimation.compute(*normals);
	
	
	concatenateFields(*cloud, *normals, *cloud_with_normals);
	
    return hr;

}
/// <summary>
/// Point Cloud Normal Estimation
/// </summary>
bool reconstruction::NormalsKSearch(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud, pcl::PointCloud<pcl::Normal>::Ptr normals, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals){
	bool hr = true;
	// ADD COLOR IN POINT CLOUD
	for (size_t i = 0; i < cloud->size(); ++i)
		cloud->points[i].rgb = (153, 149, 249);
	
	pcl::search::KdTree<pcl::PointXYZRGBNormal>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGBNormal>());
	tree->setInputCloud(cloud);
	pcl::NormalEstimation<pcl::PointXYZRGBNormal, pcl::Normal> normal_estimator;
	normal_estimator.setInputCloud(cloud);
	normal_estimator.setSearchMethod(tree);
	normal_estimator.setKSearch(50);
	normal_estimator.compute(*normals);
	concatenateFields(*normals, *cloud, *cloud_with_normals);
	return hr;
 }

/// <summary>
/// Point Cloud Normal Estimation
/// </summary>
bool reconstruction::NormalEstimationOMP(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<pcl::Normal>::Ptr normals, pcl::PointCloud<PointXYZRGBNormal>::Ptr cloud_with_normals){
	bool hr = true;
	
	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>);

	pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGBNormal> mls;
	mls.setInputCloud(cloud);
	mls.setPolynomialFit(true);
	mls.setSearchMethod(tree);
	mls.setSearchRadius(0.03);
	
	pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_smoothed(new pcl::PointCloud<pcl::PointXYZRGBNormal>());
	mls.process(*cloud_with_normals);
		
	pcl::NormalEstimationOMP<pcl::PointXYZRGBNormal, pcl::Normal> ne;
	ne.setNumberOfThreads(8);
	ne.setInputCloud(cloud_with_normals);
	ne.setRadiusSearch(0.03);
	Eigen::Vector4f centroid;
	//compute3DCentroid(*cloud, centroid);
	ne.setViewPoint(0.0f, 0.0f, 0.0f);
	
	ne.compute(*normals);
	/*
	for (size_t i = 0; i < normals->size(); ++i)
	{
			normals->points[i].normal_x *= -1;
			normals->points[i].normal_y *= -1;
			normals->points[i].normal_z *= -1;
	}
	*/

	//concatenateFields(*cloud_smoothed, *normals, *cloud_with_normals);

	pcl::copyPointCloud<pcl::PointXYZRGBNormal, pcl::PointXYZRGB>(*cloud_with_normals, *cloud);
	return hr;

}
/// <summary>
/// Point Cloud Normal Estimation for Integral Images
/// </summary>
bool reconstruction::IntegralImageNormalEstimation(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointcloud, pcl::PointCloud<pcl::Normal>::Ptr normals){
    bool hr = true;

    // estimate normals
    pcl::IntegralImageNormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne;
    ne.setNormalEstimationMethod(ne.AVERAGE_3D_GRADIENT);
    ne.setMaxDepthChangeFactor(0.02f);
    ne.setNormalSmoothingSize(10.0f);
    ne.setInputCloud(pointcloud);
    ne.compute(*normals);

    return hr;

}

/// <summary>
/// Marching Squares Reconstruction
//  Implemented by Greg Borenstein https://github.com/atduskgreg/pcl-marching-squares-example/blob/master/marching_cubes.cpp
/// </summary>
/// <param name="cloud">Pointer to input pointCloud</param>
/// <returns>indicates success or failure</returns>
bool reconstruction::MarchingSquares(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, float isoLevel, float offSurfaceDisplacement, float gridResolution, pcl::PolygonMesh::Ptr triangles){
    bool hr= true;

    // Create search tree*
    pcl::search::KdTree<pcl::PointXYZRGBNormal>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGBNormal>);
    tree->setInputCloud(cloud_with_normals);

    // begin marching cubes reconstruction
    pcl::MarchingCubesRBF<pcl::PointXYZRGBNormal> mc;
    mc.setInputCloud(cloud_with_normals);
    mc.setSearchMethod(tree);
    mc.setIsoLevel(isoLevel);
	mc.setGridResolution(gridResolution, gridResolution, gridResolution);
	mc.setOffSurfaceDisplacement(offSurfaceDisplacement);
    mc.voxelizeData();
    mc.reconstruct(*triangles);

    return hr;
}

bool reconstruction::MarchingCubes(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, double leafSize, double isoLevel, pcl::PolygonMesh::Ptr triangles){
    bool hr = true;

	// Create search tree*
	search::KdTree<PointXYZRGBNormal>::Ptr tree(new search::KdTree<PointXYZRGBNormal>);
	tree->setInputCloud(cloud_with_normals);

	cout << "Begin marching cubes reconstruction" << endl;
	
	MarchingCubesHoppe<PointXYZRGBNormal> mc;

	//PolygonMesh::Ptr triangles(new PolygonMesh);
	mc.setInputCloud(cloud_with_normals);
	mc.setSearchMethod(tree);
	mc.setPercentageExtendGrid(leafSize); //.setLeafSize 
	mc.setIsoLevel(isoLevel);
	mc.reconstruct(*triangles);
	
	return hr;
}

bool reconstruction::GridProjection(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, pcl::PolygonMesh::Ptr triangles){
	bool hr = true;

	// Create search tree*
	pcl::search::KdTree<pcl::PointXYZRGBNormal>::Ptr tree2(new pcl::search::KdTree<pcl::PointXYZRGBNormal>);
	tree2->setInputCloud(cloud_with_normals);

	// Initialize objects
	pcl::GridProjection<pcl::PointXYZRGBNormal> gbpolygon;
	
	// Set parameters
	gbpolygon.setResolution(0.005);
	gbpolygon.setPaddingSize(3);
	gbpolygon.setNearestNeighborNum(100);
	gbpolygon.setMaxBinarySearchLevel(10);

	// Get result
	gbpolygon.setInputCloud(cloud_with_normals);
	gbpolygon.setSearchMethod(tree2);
	gbpolygon.reconstruct(*triangles);

	return hr;
}
