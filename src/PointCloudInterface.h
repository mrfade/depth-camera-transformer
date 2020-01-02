#pragma once
#include"PointCloud.h"
#include"PointCloudRecorder.h"
#include"PointCloudGenerator.h"
#include<vector>
class PointCloudInterface
{
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;

public:
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool record();
};
