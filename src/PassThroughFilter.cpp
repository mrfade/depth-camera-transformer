#include"PassThroughFilter.h"
#include<vector>
#include<iostream>
#include"PointCloud.h"
#include"Point.h"

void PassThroughFilter::filter(PointCloud& points)
{
	std::vector <Point> point = points.getPoints(); //keeps points in a vector
	int i;
	for (i = 0; i < points.getPointNumber(); i++)
	{
		if (point[i].get_x() > upperLimitX || point[i].get_x() < lowerLimitX || point[i].get_y() > upperLimitY || point[i].get_y() < lowerLimitY || point[i].get_z() > upperLimitZ || point[i].get_z() < lowerLimitZ)
		{
			points.removePoint(i); // checks if the x,y,z values are bigger than upper limits or smaller than lower limits and deletes unnecessary points  
		}
	}
}

void PassThroughFilter::setupperLimitX(int xmax)
{
	upperLimitX = xmax;
}
void PassThroughFilter::setupperLimitY(int ymax)
{
	upperLimitY = ymax;
}
void PassThroughFilter::setupperLimitZ(int zmax)
{
	upperLimitZ = zmax;
}
void PassThroughFilter::setlowerLimitX(int xmin)
{
	lowerLimitX = xmin;
}
void PassThroughFilter::setlowerLimitY(int ymin)
{
	lowerLimitY = ymin;
}
void PassThroughFilter::setlowerLimitZ(int zmin)
{
	upperLimitZ = zmin;
}

