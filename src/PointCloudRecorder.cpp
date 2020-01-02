#include "PointCloudRecorder.h"

//! Default constructor
PointCloudRecorder::PointCloudRecorder()
{
}

/*!
	\param fileName a string
*/
PointCloudRecorder::PointCloudRecorder(std::string fileName)
{
	this->fileName = fileName;
}

//! Default destructor
PointCloudRecorder::~PointCloudRecorder()
{
}

/*!
	\param fileName a string
*/
void PointCloudRecorder::setFileName(std::string fileName)
{
	this->fileName = fileName;
}

/*!
	\return The fileName
*/
std::string PointCloudRecorder::getFileName()
{
	return fileName;
}

/*!
	\param pc& a reference of PointCloud that is going to be written to a file.
	\return Whether the points is wrote
*/
bool PointCloudRecorder::save(const PointCloud& pc)
{
	std::list<Point> points = pc.getPoints();
	std::list<Point> ::iterator it;

	std::ofstream file(fileName);

	if (file.is_open()) {
		for (it = points.begin(); it != points.end(); it++)
			file << it->get_x() << " " << it->get_y() << " " << it->get_z() << "\n";
		return true;
	}
	else
		return false;
}
