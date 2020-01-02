/**
 * @file PointCloudFilter.h
 * @author Ibrahim Ertan Yýlmaz (ibrahimertanylmz@gmail.com)
 * @date January, 2020
 */

#ifndef POINTCLOUDFILTER_H
#define POINTCLOUDFILTER_H

#include"PointCloud.h"

class PointCloudFilter
{
private:

public:
	virtual void filter(PointCloud& points);//!pure virtual function for filters
};

#endif POINTCLOUDFILTER_H
