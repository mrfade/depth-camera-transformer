/**
 * @file RadiusOutlierFilter.h
 * @author Ibrahim Ertan Yýlmaz (ibrahimertanylmz@gmail.com)
 * @date December, 2019
 */

#ifndef RADIUSOUTLIERFILTER_H
#define RADIUSOUTLIERFILTER_H

#include"PointCloud.h"

class RadiusOutlierFilter
{
private:

	double radius;

public:

	RadiusOutlierFilter() //!constructor
	{
		radius = 25;
	}

	void filter(PointCloud& points); //!filter function for unnecessary points

	void setRadius(int rad); //!sets radius value
};

#endif RADIUSOUTLIERFILTER_H
