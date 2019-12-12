#include "PointCloud.h"

PointCloud::PointCloud()
{
}

void PointCloud::addPoint(double _x, double _y, double _z)
{
    Point pt(_x, _y, _z);
    points.push_back(pt);
}

void PointCloud::removePoint(int index)
{
    points.erase(points.begin() + index);
}

std::vector<Point> PointCloud::getPoints() const
{
    return points;
}

int PointCloud::getPointNumber() const
{
    return pointNumber;
}

PointCloud PointCloud::operator+(const PointCloud &p)
{
    std::vector<Point> pts = p.getPoints();
    for (int i = 0; i < pts.size(); i++)
        points.push_back(pts.at(i));
}
PointCloud PointCloud::operator=(const PointCloud &p)
{
    points = p.getPoints();
    pointNumber = p.getPointNumber();
}
