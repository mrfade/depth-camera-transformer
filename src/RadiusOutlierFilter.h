/**
 * @file RadiusOutlierFilter.h
 * @author Ibrahim Ertan Yýlmaz (ibrahimertanylmz@gmail.com)
 * @date January, 2020
 */

#ifndef RADIUSOUTLIERFILTER_H
#define RADIUSOUTLIERFILTER_H

#include"PointCloud.h"
#include"PointCloudFilter.h"
class RadiusOutlierFilter : public PointCloudFilter
{
private:

	double radius;

public:

	RadiusOutlierFilter(); //!constructor

	void filter(PointCloud& points); //!filter function for unnecessary points

	void setRadius(double rad); //!sets radius value
};

#endif RADIUSOUTLIERFILTER_H
