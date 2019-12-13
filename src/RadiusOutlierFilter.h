/**
 * @file RadiusOutlierFilter.h
 * @author Ibrahim Ertan Y�lmaz (ibrahimertanylmz@gmail.com)
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

	RadiusOutlierFilter(); //!constructor

	void filter(PointCloud& points); //!filter function for unnecessary points

	void setRadius(double rad); //!sets radius value
};

#endif RADIUSOUTLIERFILTER_H
