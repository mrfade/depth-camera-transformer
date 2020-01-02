#include"FilterPipe.h"
#include<vector>

void FilterPipe::addFilter(PointCloudFilter* filter)
{
	filters.push_back(filter);//!adds filter to the filters vector
}

void FilterPipe::filterOut(PointCloud& points)
{
	for (int i = 0; i < filters.size(); i++)
	{
		filters[i]->filter(points);//!filters pointcloud with using filters at vector
	}
}