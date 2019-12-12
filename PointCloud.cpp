#include "Point.h"
#include "PointCloud.h"

PointCloud::PointCloud(int size) : pointNumber(size)
{
	*points=new Point[pointNumber];
}

void PointCloud::setpoint(Point *s ,double _x, double _y, double _z)
{	
	points->set_x(_x);                
	points->set_y(_y);
	points->set_z(_z);
}

PointCloud PointCloud:: operator+(const PointCloud& points)
{
    PointCloud p;
    p.x= this->x + points.x;
    p.y = this->y + points.y
    p.z = this->z + points.z;
    return p;
}
PointCloud PointCloud:: operator=() 
