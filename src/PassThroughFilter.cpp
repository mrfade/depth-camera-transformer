#include"PassThroughFilter.h"
#include<vector>
#include"PointCloud.h"
#include"Point.h"

void PassThroughFilter::filter(PointCloud& points)
{
	std::vector <Point> point = points.getPoints(); //!keeps points in a vector
	int i,j= points.getPointNumber();
	for (i = 0; i < j; i++)
	{
		if (point[i].get_x() > upperLimitX || point[i].get_x() < lowerLimitX || point[i].get_y() > upperLimitY || point[i].get_y() < lowerLimitY || point[i].get_z() > upperLimitZ || point[i].get_z() < lowerLimitZ)
		{
			points.removePoint(i); //!checks if the x,y,z values are bigger than upper limits or smaller than lower limits and deletes unnecessary points  
		}
	}
}

void PassThroughFilter::setupperLimitX(double xmax)
{
	upperLimitX = xmax;
}
void PassThroughFilter::setupperLimitY(double ymax)
{
	upperLimitY = ymax;
}
void PassThroughFilter::setupperLimitZ(double zmax)
{
	upperLimitZ = zmax;
}
void PassThroughFilter::setlowerLimitX(double xmin)
{
	lowerLimitX = xmin;
}
void PassThroughFilter::setlowerLimitY(double ymin)
{
	lowerLimitY = ymin;
}
void PassThroughFilter::setlowerLimitZ(double zmin)
{
	lowerLimitZ = zmin;
}

