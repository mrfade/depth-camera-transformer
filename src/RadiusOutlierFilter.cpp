#include"RadiusOutlierFilter.h"
#include<math.h>
#include"PointCloud.h"
#include"Point.h"

void RadiusOutlierFilter::filter(PointCloud& points)
{
	std::vector <Point> point = points.getPoints(); //!keep points in a vector

	int j = points.getPointNumber(); 
	int sayac = 0;
	for (int i = 0; i < j; i++) 
	{
		for (int k = 0; k < j; k++)
		{
			if (k != i)
			{
				if (point[i].distance(point[k]) < radius) 
				{
					sayac++; //!even if only one point's distance is smaller than radius, the point won't be deleted. 
				}
			}
		}
		if (sayac == 0) 
		{
			points.removePoint(i);//!else the point will be deleted.
		}
		sayac = 0;
	}

void RadiusOutlierFilter::setRadius(int rad)
{
	radius = rad;
}