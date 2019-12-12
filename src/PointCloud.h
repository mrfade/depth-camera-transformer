/**
 * @file PointCloud.h
 * @author Nora Iseni
 * @date December, 2019
 */

#include "Point.h"
#include <vector>

class PointCloud
{
private:
	std::vector<Point> points;
	int pointNumber;

public:
	PointCloud();

	void addPoint(double, double, double);
	void removePoint(int);
	std::vector<Point> getPoints() const;
	int getPointNumber() const;

	PointCloud operator+(const PointCloud &points);
	PointCloud operator=(const PointCloud &points);
};
