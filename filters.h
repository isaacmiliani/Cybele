#ifndef FILTERS_H
#define FILTERS_H

#pragma once

#include <pcl/visualization/pcl_visualizer.h>
typedef pcl::PointXYZI PointTypeIO;
typedef pcl::PointXYZINormal PointTypeFull;

class filters
{
public:
    filters();

    ~filters();


    /// <summary>
    /// Downsampling a PointCloud
    /// </summary>
    bool VoxelGrid(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double leafSize);

    /// <summary>
    /// Removing outliers using a StatisticalOutlierRemoval filter
    /// </summary>
    bool StatisticalOutlierRemoval(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, int meanK);

	/// <summary>
	/// Removing outliers using a StatisticalRadiusRemoval filter
	/// </summary>
	bool StatisticalRadiusRemoval(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double radius, double neighbors);

    /// <summary>
    /// Filtering a PointCloud using a PassThrough filter
    /// </summary>
	bool PassThrough(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, std::string fieldName, pcl::PointXYZRGB min, pcl::PointXYZRGB max);

    /// <summary>
    /// A bilateral filter implementation for point cloud data
    /// <summary>
	bool Bilateral(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double sigmaR, double sigmaS);

    /// <summary>
    /// A Fast bilateral filter implementation for point cloud data
    /// <summary>
    bool FastBilateral(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double sigmaR, double sigmaS);

    /// <summary>
    /// Moving Least Squares as http://www.pointclouds.org/documentation/tutorials/resampling.php
    /// </summary>
	bool MovingLeastSquares(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloud_with_normals, double searchRadius);

	/// <summary>
	/// Upsampling with Moving Least Squares 
	/// </summary>
	bool Upsampling_MLS(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double searchRadius, double upsamplingRadius, double stepSize, std::string upsamplingMethod);

    /// <summary>
    /// Crop Box is a filter that allows the user to filter all the data inside of a given box
    /// </summary>
	bool CropBox(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointXYZRGB min, pcl::PointXYZRGB max);

    /// <summary>
    /// Crop Box is a filter that allows the user to filter all the data inside of a given box
    /// </summary>
    bool MarchingSquares(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud);

	/// <summary>
	/// Uniform Sampling outputs the indices of the points that survived the process
	/// </summary>
	bool UniformSampling(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<int>::Ptr keypointIndices, double radius);

	/// <summary>
	/// Bilateral Sampling takes in a colored organized point cloud (i.e. PointXYZRGBRGB or PointXYZRGBRGBA), that might contain nan values for the depth information, and it will return an upsampled version of this cloud
	/// </summary>
	bool BilateralUpsampling(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double sigmaColor, double sigmaDepth);

	/// <summary>
	/// Bilateral Sampling takes in a colored organized point cloud (i.e. PointXYZRGBRGB or PointXYZRGBRGBA), that might contain nan values for the depth information, and it will return an upsampled version of this cloud
	/// </summary>
	bool ClusterExtraction(pcl::PointCloud<pcl::PointXYZI>::Ptr cloud);


	bool enforceIntensitySimilarity(const PointTypeFull& point_a, const PointTypeFull& point_b, float squared_distance);
	bool enforceCurvatureOrIntensitySimilarity(const PointTypeFull& point_a, const PointTypeFull& point_b, float squared_distance);
	//bool customRegionGrowing(const PointTypeFull& point_a, const PointTypeFull& point_b, float squared_distance);

	bool MovingLeastSquaresOPENNI(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr smoothedCloud, double searchRadius);

	bool ScaleCloud(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, double scaleFactor);

	bool ExtractIndices(pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, const pcl::IndicesPtr indices);
};

#endif // FILTERS_H
