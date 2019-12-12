/**
 * @file PointCloud.h
 * @author Nora Iseni
 * @date December, 2019
 */

#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include "Point.h"
#include <vector>

class PointCloud
{
private:
	std::vector<Point> points;
	int pointNumber = 0;

public:
	PointCloud();

	void addPoint(double, double, double);
	void addPoint(Point);
	void removePoint(int);
	std::vector<Point> getPoints() const;
	int getPointNumber() const;

	PointCloud operator+(const PointCloud &);
	PointCloud& operator=(const PointCloud &);
};

#endif POINTCLOUD_H
