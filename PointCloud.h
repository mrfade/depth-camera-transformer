#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include "Point.h"

class PointCloud
{
	private:
		Point *points;
		int pointNumber;
		
	public:
		PointCloud(int );
		void setpoint(Point, double, double, double );
		PointCloud operator +(const PointCloud& points);
		PointCloud operator =(const PointCloud& points);


		

		
};

#endif
