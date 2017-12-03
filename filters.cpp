

#define NOMINMAX
#include "filters.h"
#pragma once
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h> // VoxelGrid
#include <pcl/filters/passthrough.h>
#include <pcl/surface/mls.h>
#include <pcl/filters/crop_box.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/statistical_outlier_removal.h> // StatisticalOutlierRemoval
#include <pcl/filters/bilateral.h>
#include <pcl/filters/fast_bilateral.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/keypoints/uniform_sampling.h>
#include <pcl/surface/bilateral_upsampling.h>
#include <pcl/segmentation/conditional_euclidean_clustering.h>
#include <pcl/console/time.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/extract_indices.h>



filters::filters()
{

}
filters::~filters(){

}

bool filters::enforceIntensitySimilarity(const PointTypeFull& point_a, const PointTypeFull& point_b, float squared_distance)
{
	if (fabs(point_a.intensity - point_b.intensity) < 5.0f)
		return (true);
	else
		return (false);
}

bool filters::enforceCurvatureOrIntensitySimilarity(const PointTypeFull& point_a, const PointTypeFull& point_b, float squared_distance)
{
	/*
	Eigen::Map<const Eigen::Vector3f> point_a_normal = point_a.normal, point_b_normal = point_b.normal;
	if (fabs(point_a.intensity - point_b.intensity) < 5.0f)
		return (true);
	if (fabs(point_a_normal.dot(point_b_normal)) < 0.05)
		return (true);
		*/
	return (false);
}

bool customRegionGrowing(const PointTypeFull& point_a, const PointTypeFull& point_b, float squared_distance)
{
	/*
	Eigen::Map<const Eigen::Vector3f> point_a_normal = point_a.normal, point_b_normal = point_b.normal;
	if (squared_distance < 10000)
	{
		if (fabs(point_a.intensity - point_b.intensity) < 8.0f)
			return (true);
		if (fabs(point_a_normal.dot(point_b_normal)) < 0.06)
			return (true);
	}
	else
	{
		if (fabs(point_a.intensity - point_b.intensity) < 3.0f)
		
		return (true);
	}
	*/
	return (false);
}

bool filters::VoxelGrid(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double leafSize)
{
    bool hr = true;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>());
    // Create the filtering object
    pcl::VoxelGrid<pcl::PointXYZRGB> voxel_grid;
	

	voxel_grid.setInputCloud(cloud);
	voxel_grid.setLeafSize(leafSize, leafSize, leafSize);
	voxel_grid.filter(*cloud_filtered);
	
	if (cloud_filtered->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*cloud_filtered, *cloud);
	else
		hr = false;

    return hr;
}
bool filters::ClusterExtraction(pcl::PointCloud<pcl::PointXYZI>::Ptr cloud)
{
	bool hr = true;
	// Data containers used
	pcl::PointCloud<PointTypeIO>::Ptr cloud_in(new pcl::PointCloud<PointTypeIO>), cloud_out(new pcl::PointCloud<PointTypeIO>);
	pcl::copyPointCloud<pcl::PointXYZI, pcl::PointXYZI>(*cloud, *cloud_in);
	pcl::PointCloud<PointTypeFull>::Ptr cloud_with_normals(new pcl::PointCloud<PointTypeFull>);
	pcl::IndicesClustersPtr clusters(new pcl::IndicesClusters), small_clusters(new pcl::IndicesClusters), large_clusters(new pcl::IndicesClusters);
	pcl::search::KdTree<PointTypeIO>::Ptr search_tree(new pcl::search::KdTree<PointTypeIO>);
	pcl::console::TicToc tt;

	// Downsample the cloud using a Voxel Grid class
	std::cerr << "Downsampling...\n", tt.tic();
	pcl::VoxelGrid<PointTypeIO> vg;
	vg.setInputCloud(cloud_in);
	vg.setLeafSize(0.03, 0.03, 0.03);
	vg.setDownsampleAllData(true);
	vg.filter(*cloud_out);
	std::cerr << ">> Done: " << tt.toc() << " ms, " << cloud_out->points.size() << " points\n";

	// Set up a Normal Estimation class and merge data in cloud_with_normals
	std::cerr << "Computing normals...\n", tt.tic();
	pcl::copyPointCloud(*cloud_out, *cloud_with_normals);
	pcl::NormalEstimation<PointTypeIO, PointTypeFull> ne;
	ne.setInputCloud(cloud_out);
	ne.setSearchMethod(search_tree);
	ne.setRadiusSearch(0.03);
	ne.compute(*cloud_with_normals);
	std::cerr << ">> Done: " << tt.toc() << " ms\n";

	// Set up a Conditional Euclidean Clustering class
	std::cerr << "Segmenting to clusters...\n", tt.tic();
	pcl::ConditionalEuclideanClustering<PointTypeFull> cec(true);
	cec.setInputCloud(cloud_with_normals);
	cec.setConditionFunction(&customRegionGrowing);
	cec.setClusterTolerance(500.0);
	cec.setMinClusterSize(cloud_with_normals->points.size() / 1000);
	cec.setMaxClusterSize(cloud_with_normals->points.size() / 5);
	cec.segment(*clusters);
	cec.getRemovedClusters(small_clusters, large_clusters);
	std::cerr << ">> Done: " << tt.toc() << " ms\n";

	// Using the intensity channel for lazy visualization of the output
	for (int i = 0; i < small_clusters->size(); ++i)
		for (int j = 0; j < (*small_clusters)[i].indices.size(); ++j)
			cloud_out->points[(*small_clusters)[i].indices[j]].intensity = -2.0;
	for (int i = 0; i < large_clusters->size(); ++i)
		for (int j = 0; j < (*large_clusters)[i].indices.size(); ++j)
			cloud_out->points[(*large_clusters)[i].indices[j]].intensity = +10.0;
	for (int i = 0; i < clusters->size(); ++i)
	{
		int label = rand() % 8;
		for (int j = 0; j < (*clusters)[i].indices.size(); ++j)
			cloud_out->points[(*clusters)[i].indices[j]].intensity = label;
	}

	if (cloud_out->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZI, pcl::PointXYZI>(*cloud_out, *cloud);
	else
		hr = false;

	return hr;
}
bool filters::StatisticalOutlierRemoval(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, int meanK){

    bool hr = true;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>());
    // Create the filtering object
    pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> sor;
    sor.setInputCloud(cloud);
    sor.setMeanK(meanK);
    sor.setStddevMulThresh(1.0);
    sor.filter(*cloud_filtered);

    //sor.setNegative(true);
    sor.filter(*cloud_filtered);

	if (cloud_filtered->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*cloud_filtered, *cloud);
	else
		hr = false;

    return hr;
}

bool filters::StatisticalRadiusRemoval(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double radius, double neighbors){

	bool hr = true;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>());
	// Filter object.
	pcl::RadiusOutlierRemoval<pcl::PointXYZRGB> filter;
	filter.setInputCloud(cloud);
	// Every point must have 10 neighbors within 15cm, or it will be removed.
	filter.setRadiusSearch(radius);
	filter.setMinNeighborsInRadius(neighbors);

	filter.filter(*cloud_filtered);

	if (cloud_filtered->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*cloud_filtered, *cloud);
	else
		hr = false;
	
	
	return hr;
	
	
}

bool filters::PassThrough(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, std::string fieldName, pcl::PointXYZRGB minPoint, pcl::PointXYZRGB maxPoint){
    bool hr = true;

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>());
    // Filter object.
    pcl::PassThrough<pcl::PointXYZRGB> filter;
    filter.setInputCloud(cloud);


    // Filter out all points in fieldName coordinate and not in the [0-maxLimit] range.
    filter.setFilterFieldName(fieldName);

	if (fieldName=="x")
		filter.setFilterLimits(minPoint.x, maxPoint.x);
	else if(fieldName=="y")
		filter.setFilterLimits(minPoint.y, maxPoint.y);
	else
		filter.setFilterLimits(minPoint.z, maxPoint.z);
		
    filter.filter(*cloud_filtered);

	if (cloud_filtered->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*cloud_filtered, *cloud);
	else
		hr = false;
   
    return hr;
}

bool filters::Bilateral(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double sigma_r, double sigma_s){
	
	bool hr = true;
   
    int pnumber = (int)cloud->size();
    // Set up KDTree

    // Output Cloud = Input Cloud
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
	pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*cloud, *filtered_cloud);

    pcl::KdTreeFLANN<pcl::PointXYZRGB>::Ptr tree(new pcl::KdTreeFLANN<pcl::PointXYZRGB>);
    tree->setInputCloud(cloud);

    // Neighbors containers
    std::vector<int> k_indices;
    std::vector<float> k_distances;

    // Main Loop
    for (int point_id = 0; point_id < pnumber; ++point_id)
    {
        float BF = 0;
        float W = 0;

        tree->radiusSearch(point_id, 2 * sigma_s, k_indices, k_distances);

        // For each neighbor
        for (size_t n_id = 0; n_id < k_indices.size(); ++n_id)
        {
            float id = k_indices.at(n_id);
            float dist = sqrt(k_distances.at(n_id));
            float intensity_dist = abs(cloud->points[point_id].z - cloud->points[id].z);

            float w_a = exp(-(dist*dist) / (2 * sigma_s*sigma_s)); //G(dist, sigma_s);
            float w_b = exp(-(intensity_dist*intensity_dist) / (2 * sigma_r*sigma_r)); // G(intensity_dist, sigma_r);
            float weight = w_a * w_b;

            BF += weight * cloud->points[id].z;
            W += weight;
        }

		filtered_cloud->points[point_id].z = BF / W;
    }

	if (filtered_cloud->points.size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*filtered_cloud, *cloud);
	else
		hr = false;
	
    return hr;
	
	/*
	bool hr = false;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
	pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*cloud, *filtered_cloud);
	pcl::BilateralFilter<pcl::PointXYZI> bilateral;

	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>);

	bilateral.setSearchMethod(tree);
	bilateral.setInputCloud(cloud);
	bilateral.setHalfSize(1.0);
	bilateral.setStdDev(0.2);
	bilateral.applyFilter(*filtered_cloud);

	if (filtered_cloud->size() > 0){
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*filtered_cloud, *cloud);
		hr = true;
	}
	return hr;
	*/
}
/// <summary>
/// A Fast bilateral filter implementation for point cloud data
/// <summary>
bool filters::FastBilateral(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double sigmaR, double sigmaS){

    bool hr = true;
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZRGB>());

    //pcl::BilateralFilter<pcl::PointXYZRGB> bFilter;
    pcl::FastBilateralFilter<pcl::PointXYZRGB> bFastBilateral;

    bFastBilateral.setInputCloud(cloud);
    bFastBilateral.setSigmaR(sigmaR);
    bFastBilateral.setSigmaS(sigmaS);
    bFastBilateral.applyFilter(*filtered_cloud);

	if (filtered_cloud->points.size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*filtered_cloud, *cloud);
	else
		hr = false;
	

    return hr;
}
/// <summary>
/// Moving Lest Square Surface Reconstruction from Point Cloud
/// </summary>
/// <param name="cloud">Pointer to input pointCloud</param>
/// <param name="cloud_smoothed">Pointer to output PointCloud.</param>
/// <returns>indicates success or failure</returns>
bool filters::Upsampling_MLS(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double searchRadius, double upsamplingRadius, double stepSize, std::string upsamplingMethod){
    bool hr = true;

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
	// Filtering object.
	pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB> filter;
	filter.setInputCloud(cloud);
	// Object for searching.
	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr kdtree;
	filter.setSearchMethod(kdtree);
	// Use all neighbors in a radius of 3cm.
	filter.setSearchRadius(searchRadius);
	
	// Upsampling method. Other possibilites are DISTINCT_CLOUD, RANDOM_UNIFORM_DENSITY
	// and VOXEL_GRID_DILATION. NONE disables upsampling. Check the API for details.
	if (upsamplingMethod=="SAMPLE_LOCAL_PLANE")
		filter.setUpsamplingMethod(pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB>::SAMPLE_LOCAL_PLANE);
    else if (upsamplingMethod == "VOXEL_GRID_DILATION")
		filter.setUpsamplingMethod(pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB>::VOXEL_GRID_DILATION);
	else if (upsamplingMethod == "RANDOM_UNIFORM_DENSITY")
		filter.setUpsamplingMethod(pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB>::RANDOM_UNIFORM_DENSITY);
	else
		filter.setUpsamplingMethod(pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGB>::DISTINCT_CLOUD);
	
	// Radius around each point, where the local plane will be sampled.
	filter.setUpsamplingRadius(upsamplingRadius);
	// Sampling step size. Bigger values will yield less (if any) new points.
	filter.setUpsamplingStepSize(stepSize);

	filter.process(*filtered_cloud);

	if (filtered_cloud->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*filtered_cloud, *cloud);
	else
		hr = false;

    return hr;
}

bool filters::MovingLeastSquares(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, double searchRadius ){
	bool hr = true;
	// Create a KD-Tree
	//for (size_t i = 0; i < cloud->size(); ++i)
	//{
	//	cloud->points[i].rgb = (153, 149, 249);
	//}
	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>);
	
	// Init object (second point type is for the normals, even if unused)
	pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGBNormal> mls;

	mls.setComputeNormals(true);
	
	// Set parameters
	mls.setInputCloud(cloud);
	mls.setPolynomialOrder(2);
	mls.setPolynomialFit(true);
	mls.setSearchMethod(tree);
	mls.setSearchRadius(searchRadius);

	//mls.setSqrGaussParam(0.0009);
	
	// Reconstruct
	// Output has the PointXYZRGBNormal type in order to store the normals calculated by MLS
	mls.process(*cloud_with_normals);

	if (cloud_with_normals->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGBNormal, pcl::PointXYZRGB>(*cloud_with_normals, *cloud);
	else
		hr = false;

	return hr;

}

bool filters::MovingLeastSquaresOPENNI(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr smoothedCloud, double searchRadius){
	bool hr = true;
	// Smoothing object (we choose what point types we want as input and output).
	pcl::MovingLeastSquares<pcl::PointXYZRGB, pcl::PointXYZRGBNormal> filter;
	filter.setInputCloud(cloud);
	// Use all neighbors in a radius of 3cm.
	filter.setSearchRadius(0.03);
	// If true, the surface and normal are approximated using a polynomial estimation
	// (if false, only a tangent one).
	filter.setPolynomialFit(true);
	// We can tell the algorithm to also compute smoothed normals (optional).
	filter.setComputeNormals(true);
	
	// kd-tree object for performing searches.
	pcl::search::KdTree<pcl::PointXYZRGB>::Ptr kdtree;
	filter.setSearchMethod(kdtree);

	filter.process(*smoothedCloud);
	if (smoothedCloud->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGBNormal, pcl::PointXYZRGB>(*smoothedCloud, *cloud);
	else
		hr = false;

	return hr;

}

/// <summary>
/// CropBox is a filter that allows the user to filter all the data inside of a given box
/// </summary>
/// <param name="cloud">Pointer to input pointCloud</param>
/// <returns>indicates success or failure</returns>
bool filters::CropBox(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointXYZRGB min, pcl::PointXYZRGB max){
    bool hr = true;
    Eigen::Vector4f minPoint;
	
    minPoint[0] = min.x;  // define minimum point x
    minPoint[1] = min.y;  // define minimum point y
    minPoint[2] = min.z;  // define minimum point z

    Eigen::Vector4f maxPoint;
    maxPoint[0] = max.x;  // define max point x
    maxPoint[1] = max.y;  // define max point y
    maxPoint[2] = max.z;  // define max point z

    Eigen::Vector3f boxTranslatation;
    boxTranslatation[0] = 0;
    boxTranslatation[1] = 0;
    boxTranslatation[2] = 0;

    Eigen::Vector3f boxRotation;
    boxRotation[0] = 0;  // rotation around x-axis
    boxRotation[1] = 0;  // rotation around y-axis
    boxRotation[2] = 0;  //in radians rotation around z-axis. this rotates your cube 45deg around z-axis.

    Eigen::Affine3f boxTransform;

    pcl::CropBox<pcl::PointXYZRGB> cropFilter;
    cropFilter.setInputCloud(cloud);
    cropFilter.setMin(minPoint);
    cropFilter.setMax(maxPoint);
    //cropFilter.setTranslation(boxTranslatation);
    //cropFilter.setRotation(boxRotation);

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>());

    cropFilter.filter(*cloud_filtered);

	if (cloud_filtered->points.size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*cloud_filtered, *cloud);
	else
		hr = false;

    return hr;

}

bool filters::UniformSampling(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<int>::Ptr keypointIndices, double radius){

	bool hr = true;

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
	// Uniform sampling object.
	pcl::UniformSampling<pcl::PointXYZRGB> filter;
	filter.setInputCloud(cloud);
	// We set the size of every voxel to be 1x1x1cm
	// (only one point per every cubic centimeter will survive).
	filter.setRadiusSearch(radius);

	filter.compute(*keypointIndices);
	pcl::copyPointCloud(*cloud, keypointIndices->points, *filtered_cloud);

	if (filtered_cloud->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*filtered_cloud, *cloud);
	else
		hr = false;

	return hr;
} 

bool filters::BilateralUpsampling(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double sigmaColor, double sigmaDepth){
	bool hr = true;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZRGB>());

	//pcl::BilateralFilter<pcl::PointXYZRGB> bFilter;
	boost::shared_ptr<pcl::BilateralUpsampling<pcl::PointXYZRGB, pcl::PointXYZRGB>> bilateralUpsampling(new pcl::BilateralUpsampling<pcl::PointXYZRGB, pcl::PointXYZRGB>());

	bilateralUpsampling->setInputCloud(cloud);
	bilateralUpsampling->setSigmaColor(sigmaColor);
	bilateralUpsampling->setSigmaDepth(sigmaDepth);
	bilateralUpsampling->process(*filtered_cloud);

	if (filtered_cloud->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*filtered_cloud, *cloud);
	else
		hr = false;
	

	return hr;
}

bool filters::ScaleCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double scaleFactor){
	bool hr = true;
	for (size_t i = 0; i < cloud->points.size(); ++i){
		cloud->points[i].x *= scaleFactor;
		cloud->points[i].y *= scaleFactor;
		cloud->points[i].z *= scaleFactor;
	}
	return hr;
}

bool filters::ExtractIndices(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, const pcl::IndicesPtr indices){
	bool hr = true;
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr filtered_cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
	pcl::ExtractIndices<pcl::PointXYZRGB> eifilter(true); // Initializing with true will allow us to extract the removed indices
	eifilter.setInputCloud(cloud);
	eifilter.setIndices(indices);
	eifilter.setNegative(true);
	eifilter.filter(*filtered_cloud);
	// The resulting cloud_out contains all points of cloud_in that are indexed by indices_in
	//indices_rem = eifilter.getRemovedIndices();
	// The indices_rem array indexes all points of cloud_in that are not indexed by indices_in
	//
	//eifilter.filter(*indices_out);
	// Alternatively: the indices_out array is identical to indices_rem
	//eifilter.setNegative(false);
	//eifilter.setUserFilterValue(1337.0);
	//
	// This will directly modify cloud_in instead of creating a copy of the cloud
	// It will overwrite all fields of the filtered points by the user value: 1337

	if (filtered_cloud->size() > 0)
		pcl::copyPointCloud<pcl::PointXYZRGB, pcl::PointXYZRGB>(*filtered_cloud, *cloud);
	else
		hr = false;

	return hr;

}

