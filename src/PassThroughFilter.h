/**
 * @file PassThrougFilter.h
 * @author Ibrahim Ertan Y�lmaz (ibrahimertanylmz@gmail.com)
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
	void setupperLimitX(int xmax); //!sets maximum value for x
	void setupperLimitY(int ymax); //!sets maximum value for y 
	void setupperLimitZ(int zmax); //!sets maximum value for z
	void setlowerLimitX(int xmin); //!sets minimum value for x
	void setlowerLimitY(int ymin); //!sets minimum value for y
	void setlowerLimitZ(int zmin); //!sets minimum value for z

};

#endif PASSTHROUGHFILTER_H