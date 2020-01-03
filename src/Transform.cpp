#include "Transform.h"

//! Default Constructor
Transform::Transform()
{
}

//! Default Destructor
Transform::~Transform()
{
}

/*!
	\param ang an array that stores angles
*/
void Transform::setRotation(double ang[])
{
    for (int i = 0; i < 3; i++)
        this->angles[i] = ang[i];
}

/*!
	\param ang an array that stores angles
*/
void Transform::setRotation(Eigen::Vector3d ang)
{
	this->angles = ang;
}

/*!
	\param tr an array that stores coordinates for translation
*/
void Transform::setTranslation(double tr[])
{
    for (int i = 0; i < 3; i++)
        this->trans[i] = tr[i];
}

/*!
	\param tr an array that stores coordinates for translation
*/
void Transform::setTranslation(Eigen::Vector3d tr)
{
	this->trans = tr;
}

/*!
	No param, Initializes the transMatrix
*/
void Transform::initialize()
{

	double a = angles.z() * PI / 180.0;
	double b = angles.y() * PI / 180.0;
	double y = angles.x() * PI / 180.0;

	transMatrix(0, 0) = cos(a) * cos(b);
	transMatrix(0, 1) = cos(a) * sin(b) * sin(y) - sin(a) * cos(y);
	transMatrix(0, 2) = cos(a) * sin(b) * cos(y) + sin(a) * sin(y);
	transMatrix(1, 0) = sin(a) * cos(b);
	transMatrix(1, 1) = sin(a) * sin(b) * sin(y) + cos(a) * cos(y);
	transMatrix(1, 2) = sin(a) * sin(b) * cos(y) - cos(a) * sin(y);
	transMatrix(2, 0) = -sin(b);
	transMatrix(2, 1) = cos(b) * sin(y);
	transMatrix(2, 2) = cos(b) * cos(y);

	transMatrix(0, 3) = trans.x();
	transMatrix(1, 3) = trans.y();
	transMatrix(2, 3) = trans.z();
	transMatrix(3, 0) = 0;
	transMatrix(3, 1) = 0;
	transMatrix(3, 2) = 0;
	transMatrix(3, 3) = 1;
}

/*!
	\param p an Point
	\return The translated Point
*/
Point Transform::doTransform(Point p)
{
	Eigen::Vector4d pa, pb;

	for (int i = 0; i < 4; i++)
		pa[i] = 0.0;

	pb[0] = p.get_x();
	pb[1] = p.get_y();
	pb[2] = p.get_z();
	pb[3] = 1;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			pa[i] += transMatrix(i, j) * pb[j];

	return Point(pa[0], pa[1], pa[2]);
}

/*!
	\param pc an PointCloud
	\return The translated PointCloud
*/
PointCloud Transform::doTransform(PointCloud pc)
{
	PointCloud pcl;

	std::list <Point> points = pc.getPoints();
	std::list <Point> ::iterator it;

	for (it = points.begin(); it != points.end(); it++)
		pcl.addPoint(doTransform(*it));

	return pcl;
}
