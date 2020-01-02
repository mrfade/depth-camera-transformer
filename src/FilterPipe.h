/**
 * @file FilterPipe.h
 * @author Ibrahim Ertan Y�lmaz (ibrahimertanylmz@gmail.com)
 * @date January, 2020
 */

#ifndef FILTERPIPE_H
#define FILTERPIPE_H

#include<vector>
#include"PointCloudFilter.h"
#include"PointCloud.h"
class FilterPipe
{
private:
	std::vector <PointCloudFilter*> filters;

public:
	void addFilter(PointCloudFilter* filter);
	void filterOut(PointCloud& points);
};
#endif FILTERPIPE_H