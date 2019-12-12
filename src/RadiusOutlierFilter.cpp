#include"RadiusOutlierFilter.h"
#include<math.h>
#include"PointCloud.h"
#include"Point.h"

void RadiusOutlierFilter::filter(PointCloud& points)
{
	std::vector <Point> point = points.getPoints(); //keep points in a vector

	for (int i = 0; i < points.getPointNumber(); i++) 
	{
		for (int k = i; k < points.getPointNumber(); k++)
		{
			if (k != i)
			{
				if (sqrt(pow(point[i].get_x() - point[k].get_x(), 2.0) + pow(point[i].get_y() - point[k].get_y(), 2.0) + pow(point[i].get_z() - point[k].get_z(), 2.0)) > radius) 
				{
					points.removePoint(i); //checks if distance between points greater than radius and deletes the unnecessary point
				}
			}
		}
	}
}

void RadiusOutlierFilter::setRadius(int rad)
{
	radius = rad;
}