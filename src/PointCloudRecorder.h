/**
 * @file PointCloudRecorder.h
 * @author Enes Solak (enessolak99@gmail.com)
 * @date December, 2019
 */

#ifndef POINTCLOUDRECORDER_H
#define POINTCLOUDRECORDER_H

#include <string>
#include <vector>
#include <fstream>
#include "Point.h"
#include "PointCloud.h"

class PointCloudRecorder
{
private:
	std::string fileName;
public:
	PointCloudRecorder();
	PointCloudRecorder(std::string);
	~PointCloudRecorder();

	void setFileName(std::string);
	std::string getFileName();

	bool save(const PointCloud&);
};

#endif POINTCLOUDRECORDER_H
