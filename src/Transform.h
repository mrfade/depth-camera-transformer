/**
 * @file Transform.h
 * @author Enes Solak (enessolak99@gmail.com)
 * @date December, 2019
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H

 //! PI number
#define PI 3.14159265359

#include <Eigen/Dense>
#include <cmath>
#include "Point.h"
#include "PointCloud.h"

/*!
	Does transform for points
 */
class Transform
{
private:
	//! Rotation angles
    Eigen::Vector3d angles;
	//! Translation coordinates
	Eigen::Vector3d trans;
	//! Matrix for transform
	Eigen::Matrix4d transMatrix;

public:
	//! Constructor
	Transform();
	//! Destructor
	~Transform();
	//! Initializes the transform matrix
	void initialize();
	//! Sets the rotation angles
	void setRotation(double[]);
	//! Sets the rotation angles
	void setRotation(Eigen::Vector3d);
	//! Sets the translation coordinates
	void setTranslation(double[]);
	//! Sets the translation coordinates
	void setTranslation(Eigen::Vector3d);
	//! Does the transform for one point
	Point doTransform(Point);
	//! Does the transform for the PointCloud
	PointCloud doTransform(PointCloud);
};

#endif TRANSFORM_H
