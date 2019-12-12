#include "PointCloudRecorder.h"

PointCloudRecorder::PointCloudRecorder()
{
}

PointCloudRecorder::PointCloudRecorder(std::string fileName)
{
	this->fileName = fileName;
}

PointCloudRecorder::~PointCloudRecorder()
{
}

void PointCloudRecorder::setFileName(std::string fileName) {
	this->fileName = fileName;
}

std::string PointCloudRecorder::getFileName() {
	return fileName;
}

bool PointCloudRecorder::save(const PointCloud& pc) {
	std::vector<Point> points = pc.getPoints();
	int pointNumber = pc.getPointNumber();

	std::ofstream file(fileName);

	if (file.is_open())
		for (int i = 0; i < pointNumber; i++)
			file << points[i].get_x() << " " << points[i].get_y() << " " << points[i].get_z();

}
