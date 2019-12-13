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

/*!
	Writes the PointCloud to a file point by point
 */
class PointCloudRecorder
{
private:
	std::string fileName;
public:
	//! Constructor
	PointCloudRecorder();
	//! Overloaded constructor that takes fileName
	PointCloudRecorder(std::string);
	//! Destructor
	~PointCloudRecorder();

	//! Sets the fileName
	void setFileName(std::string);
	//! Returns the filename
	std::string getFileName();

	//! Saves the PointCloud to the given file
	bool save(const PointCloud&);
};

#endif POINTCLOUDRECORDER_H
