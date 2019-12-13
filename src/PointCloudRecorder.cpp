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
	std::vector<Point> points = pc.getPoints();
	int pointNumber = pc.getPointNumber();

	std::ofstream file(fileName);

	if (file.is_open()) {
		for (int i = 0; i < pointNumber; i++)
			file << points[i].get_x() << " " << points[i].get_y() << " " << points[i].get_z() << "\n";
		return true;
	}
	else
		return false;
}
