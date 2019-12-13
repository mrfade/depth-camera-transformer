#include "Point.h"

Point::Point() : x(0.0), y(0.0), z(0.0) {} //NO-ARG (Default) constructor

Point::Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {} //Overloaded constructor

Point::~Point()
{
}

void Point::set_x(double _x) //Sets a value for x coordinate
{
	x = _x;
}

double Point::get_x() const //Gets the x coordinate
{
	return x;
}

void Point::set_y(double _y) //Sets a value for y coordinate
{
	y = _y;
}

double Point::get_y() const //Gets the y coordinate
{
	return y;
}

void Point::set_z(double _z) //Sets a value for z coordinate
{
	z = _z;
}

double Point::get_z() const //Gets the z coordinate
{
	return z;
}

bool Point::operator==(const Point &point) //Compares two points coordinates if they are equal or not
{
	return (point.x == this->x) && (point.y == this->y) && (point.z == this->z);
}

double Point::distance(const Point &point)
{
	return pow((pow(point.get_x() - x, 2) + pow(point.get_y() - y, 2) + pow(point.get_z() - z, 2)), 1.0 / 2.0);
}
