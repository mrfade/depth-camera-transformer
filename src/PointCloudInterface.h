/**
 * @file PointCloudInterface.h
 * @author Nora Iseni
 * @date January, 2020
 */
#pragma once
#include"PointCloud.h"
#include"PointCloudRecorder.h"
#include"PointCloudGenerator.h"
#include<vector>
class PointCloudInterface
{
	PointCloud pointCloud;
	PointCloud patch;
	std::vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;

public:
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool record();
};
