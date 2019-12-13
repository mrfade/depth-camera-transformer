/**
 * @file Transform.h
 * @author Enes Solak (enessolak99@gmail.com)
 * @date December, 2019
 */

#ifndef TRANSFORM_H
#define TRANSFORM_H

#define PI 3.14159265359

#include <cmath>
#include "Point.h"
#include "PointCloud.h"

class Transform
{
private:
    double angles[3];
    double trans[3];
    double transMatrix[4][4];

public:
	Transform();
	~Transform();
	void initialize();
	void setRotation(double[]);
	void setTranslation(double[]);
	Point doTransform(Point);
	PointCloud doTransform(PointCloud);
};

#endif TRANSFORM_H
