#include"RadiusOutlierFilter.h"
#include<math.h>
#include"PointCloud.h"
#include"Point.h"

RadiusOutlierFilter::RadiusOutlierFilter() {
}

void RadiusOutlierFilter::filter(PointCloud& points)
{
	std::vector <Point> point = points.getPoints(); //!keep points in a vector

	int sayac = 0;
	int count = point.size();
	for (int i = 0; i < count; i++)
	{
		for (int k = 0; k < count; k++)
		{
			if (k != i)
			{
				if (point.at(i).distance(point.at(k)) < radius)
				{
					sayac++; //!even if only one point's distance is smaller than radius, the point won't be deleted. 
				}
				
			}
		}
		if (sayac == 0)
		{
			points.removePoint(point.at(i));//!else the point will be deleted.
		}
		sayac = 0;
	}

}

void RadiusOutlierFilter::setRadius(double rad)
{
	radius = rad;
}