#include"PointCloud.h"

class RadiusOutlierFilter
{
private:

	double radius;

public:

	RadiusOutlierFilter() //constructor
	{
		radius = 25;
	}

	void filter(PointCloud& points); //filter function for unnecessary points

	void setRadius(int rad); //sets radius value
};

