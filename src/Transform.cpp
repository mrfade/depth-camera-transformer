#include "Transform.h"

Transform::Transform()
{
}

Transform::~Transform()
{
}

void Transform::setRotation(double ang[])
{
    for (int i = 0; i < 3; i++)
        this->angles[i] = ang[i];
}

void Transform::setTranslation(double tr[])
{
    for (int i = 0; i < 3; i++)
        this->trans[i] = tr[i];
}

void Transform::initialize() {

	double a = angles[2] * PI / 180.0;
	double b = angles[1] * PI / 180.0;
	double y = angles[0] * PI / 180.0;

	double rotationMatrix[3][3];

	rotationMatrix[0][0] = cos(a) * cos(b);
	rotationMatrix[0][1] = cos(a) * sin(b) * sin(y) - sin(a) * cos(y);
	rotationMatrix[0][2] = cos(a) * sin(b) * cos(y) + sin(a) * sin(y);
	rotationMatrix[1][0] = sin(a) * cos(b);
	rotationMatrix[1][1] = sin(a) * sin(b) * sin(y) + cos(a) * cos(y);
	rotationMatrix[1][2] = sin(a) * sin(b) * cos(y) - cos(a) * sin(y);
	rotationMatrix[2][0] = -sin(b);
	rotationMatrix[2][1] = cos(b) * sin(y);
	rotationMatrix[2][2] = cos(b) * cos(y);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			transMatrix[i][j] = rotationMatrix[i][j];

	transMatrix[0][3] = trans[0];
	transMatrix[1][3] = trans[1];
	transMatrix[2][3] = trans[2];
	transMatrix[3][0] = 0;
	transMatrix[3][1] = 0;
	transMatrix[3][2] = 0;
	transMatrix[3][3] = 1;
}

Point Transform::doTransform(Point p) {
	double pa[4], pb[4];

	for (int i = 0; i < 4; i++)
		pa[i] = 0.0;

	pb[0] = p.get_x();
	pb[1] = p.get_y();
	pb[2] = p.get_z();
	pb[3] = 1;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			pa[i] += transMatrix[i][j] * pb[j];

	return Point(pa[0], pa[1], pa[2]);
}

PointCloud Transform::doTransform(PointCloud pc) {
	PointCloud pcl;

	std::vector <Point> points = pc.getPoints();
	int pcsNumber = pc.getPointNumber();

	for (int i = 0; i < pcsNumber; i++)
		pcl.addPoint(doTransform(points.at(i)));

	return pcl;
}
