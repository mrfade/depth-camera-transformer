/**
 * @file PassThrougFilter.h
 * @author Ibrahim Ertan Yýlmaz (ibrahimertanylmz@gmail.com)
 * @date December, 2019
 */

#ifndef PASSTHROUGHFILTER_H
#define PASSTHROUGHFILTER_H

#include"PointCloud.h"
class PassThroughFilter
{
private:

	double upperLimitX;
	double lowerLimitX;
	double upperLimitY;
	double lowerLimitY;
	double upperLimitZ;
	double lowerLimitZ;


public:

	void filter(PointCloud& points); //!filter function for unnecessary points
	void setupperLimitX(double xmax); //!sets maximum value for x
	void setupperLimitY(double ymax); //!sets maximum value for y 
	void setupperLimitZ(double zmax); //!sets maximum value for z
	void setlowerLimitX(double xmin); //!sets minimum value for x
	void setlowerLimitY(double ymin); //!sets minimum value for y
	void setlowerLimitZ(double zmin); //!sets minimum value for z

};

#endif PASSTHROUGHFILTER_H
