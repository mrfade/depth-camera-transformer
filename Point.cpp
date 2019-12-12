#include "Point.h"


Point::Point(): x(0.0), y(0.0), z(0.0){}                                        //NO-ARG (Default) constructor

Point::Point (double _x, double _y, double _z) :x(_x), y(_y), z(_z){}            //Overloaded constructor

void Point::set_x(double _x)                                                     //Sets a value for x coordinate
{
	x=_x;
} 

double Point::get_x()                                                            //Gets the x coordinate
{
	return x;	
}

void Point::set_y(double _y)                                                     //Sets a value for y coordinate
{
	y=_y;
} 

double Point::get_y()                                                            //Gets the y coordinate
{
	return y;	
}

void Point::set_z(double _z)                                                     //Sets a value for z coordinate
{
	z=_z;
} 

double Point::get_z()                                                            //Gets the z coordinate
{
	return z;	
}

bool Point:: operator==( const Point& point, const Point& point1)                //Compares two points coordinates if they are equal or not
{
	return (point.x == point1.x) && (point.y == point1.y) && (point.z == point1.z);
}

double Point::distance (const Point& point){
	
}
