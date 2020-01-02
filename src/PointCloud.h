/**
 * @file PointCloud.h
 * @author Nora Iseni
 * @date December, 2019
 * @edited_by Onur Nafi Guzel (ongguzel@gmail.com)
 */


#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include "Point.h"
#include <list>
#include <algorithm>

class PointCloud
{
private:
	std::list<Point> points;
	int pointNumber = 0;

public:
	PointCloud();

	void addPoint(double, double, double);
	void addPoint(Point);
	void removePoint(Point);
	std::list<Point> getPoints() const;
	int getPointNumber() const;

	PointCloud operator+(const PointCloud &);
	PointCloud& operator=(const PointCloud &);
};

#endif POINTCLOUD_H
