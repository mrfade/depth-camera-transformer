#ifndef POINT_H
#define POINT_H


class Point
{
	private:
		//member datas
		double x, y, z;
	public:
		//member methods
		Point();                                //NO-ARG (Default) constructor
		Point(double _x, double _y, double _z); //Overloaded constructor
		void set_x(double _x);                  //Sets a value for x coordinate
		double get_x();                         //Gets the x coordinate
	    void set_y(double _y);                  //Sets a value for y coordinate
	    double get_y();                         //Gets the y coordinate
	    void set_z(double _z);                  //Sets a value for z coordinate
	    double get_z();                         //Gets the z coordinate
	    bool operator ==(const Point& point);   //Compares two points coordinates if they are equal or not
	    double distance(const Point& );                          //Calculates the distance between...
};

#endif
