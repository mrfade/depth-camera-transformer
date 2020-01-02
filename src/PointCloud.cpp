#include "PointCloud.h"

PointCloud::PointCloud()
{
}

void PointCloud::addPoint(double _x, double _y, double _z)
{
    Point pt(_x, _y, _z);
    points.push_back(pt);
	this->pointNumber++;
}

void PointCloud::addPoint(Point p)
{
    points.push_back(p);
	this->pointNumber++;
}

void PointCloud::removePoint(Point p)
{
	points.erase(std::remove(points.begin(), points.end(), p), points.end());
	this->pointNumber--;
}

std::list<Point> PointCloud::getPoints() const
{
    return points;
}

int PointCloud::getPointNumber() const
{
    return pointNumber;
}

PointCloud PointCloud::operator+(const PointCloud &p)
{
	PointCloud pc;
    std::list<Point> pts = p.getPoints();
    for (int i = 0; i < pts.size(); i++)
        pc.addPoint(pts.at(i));
	for (int i = 0; i < points.size(); i++)
        pc.addPoint(points.at(i));
	return pc;
}
PointCloud& PointCloud::operator=(const PointCloud &p)
{
    points = p.getPoints();
    pointNumber = p.getPointNumber();
	return *(this);
}
