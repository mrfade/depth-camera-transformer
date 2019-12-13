/**
 * @file Transform.h
 * @author Enes Solak (enessolak99@gmail.com)
 * @date December, 2019
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H

 //! PI number
#define PI 3.14159265359

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
    double angles[3];
	//! Translation coordinates
    double trans[3];
	//! Matrix for transform
    double transMatrix[4][4];

public:
	//! Constructor
	Transform();
	//! Destructor
	~Transform();
	//! Initializes the transform matrix
	void initialize();
	//! Sets the rotation angles
	void setRotation(double[]);
	//! Sets the translation coordinates
	void setTranslation(double[]);
	//! Does the transform for one point
	Point doTransform(Point);
	//! Does the transform for the PointCloud
	PointCloud doTransform(PointCloud);
};

#endif TRANSFORM_H
