#include"PassThroughFilter.h"
#include<list>
#include"PointCloud.h"
#include"Point.h"

void PassThroughFilter::filter(PointCloud& points)
{
	std::list <Point> point = points.getPoints(); //!keeps points in a list
	std::list <Point> ::iterator it;
	for (it = point.begin(); it != point.end(); it++)
	{
		if (it->get_x() > upperLimitX || it->get_x() < lowerLimitX || it->get_y() > upperLimitY || it->get_y() < lowerLimitY || it->get_z() > upperLimitZ || it->get_z() < lowerLimitZ)
		{
			points.removePoint(*it); //!checks if the x,y,z values are bigger than upper limits or smaller than lower limits and deletes unnecessary points  
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

