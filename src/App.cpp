#include <iostream>
#include "DepthCamera.h"
#include "PointCloud.h"
#include "PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
#include "PointCloudRecorder.h"

using namespace std;

int main()
{
	DepthCamera camera1, camera2;
	camera1.setfileName("camera1.txt");
	camera2.setfileName("camera2.txt");

	PointCloud pc1, pc2;
	pc1 = camera1.Capture();
	pc2 = camera2.Capture();

	RadiusOutlierFilter rof;
	rof.setRadius(25);

	rof.filter(pc1);
	rof.filter(pc2);

	PassThroughFilter filter1, filter2;
	filter1.setlowerLimitX(0);
	filter1.setupperLimitX(400);
	filter1.setlowerLimitY(0);
	filter1.setupperLimitY(400);
	filter1.setlowerLimitZ(-45);
	filter1.setupperLimitZ(45);
	
	filter2.setlowerLimitX(0);
	filter2.setupperLimitX(500);
	filter2.setlowerLimitY(0);
	filter2.setupperLimitY(500);
	filter2.setlowerLimitZ(-45);
	filter2.setupperLimitZ(45);

	filter1.filter(pc1);
	filter2.filter(pc2);

	// TRANSFORM

	PointCloud pc3;
	pc3 = pc1 + pc2;

	PointCloudRecorder recorder;
	recorder.setFileName("cloud.txt");

	recorder.save(pc3);

	return 0;
}