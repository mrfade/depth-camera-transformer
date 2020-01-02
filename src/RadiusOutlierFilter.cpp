#include"RadiusOutlierFilter.h"
#include<math.h>
#include"PointCloud.h"
#include"Point.h"

RadiusOutlierFilter::RadiusOutlierFilter()
{
}

void RadiusOutlierFilter::filter(PointCloud& points)
{
	std::list <Point> point = points.getPoints(); //!keep points in a vector
	std::list <Point> ::iterator it1, it2;

	int sayac = 0;
	for (it1 = point.begin(); it1 != point.end(); it1++)
	{
		for (it2 = point.begin(); it2 != point.end(); it2++)
		{
			if (it2 != it1)
			{
				if (it1->distance(*it2) < radius)
				{
					sayac++; //!even if only one point's distance is smaller than radius, the point won't be deleted. 
				}

			}
		}
		if (sayac == 0)
		{
			points.removePoint(*it1);//!else the point will be deleted.
		}
		sayac = 0;
	}

}

void RadiusOutlierFilter::setRadius(double rad)
{
	radius = rad;
}