#include <iostream>
#include "DepthCamera.h"
#include "PointCloud.h"
#include "PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
#include "PointCloudRecorder.h"
#include "Transform.h"

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
	rof.setRadius(25.0);

	rof.filter(pc1);
	rof.filter(pc2);

	PassThroughFilter filter1, filter2;
	filter1.setlowerLimitX(0.0);
	filter1.setupperLimitX(400.0);
	filter1.setlowerLimitY(0.0);
	filter1.setupperLimitY(400.0);
	filter1.setlowerLimitZ(-45.0);
	filter1.setupperLimitZ(45.0);
	
	filter2.setlowerLimitX(0.0);
	filter2.setupperLimitX(500.0);
	filter2.setlowerLimitY(0.0);
	filter2.setupperLimitY(500.0);
	filter2.setlowerLimitZ(-45.0);
	filter2.setupperLimitZ(45.0);

	filter1.filter(pc1);
	filter2.filter(pc2);

	// TRANSFORM
	Transform tr1, tr2;

	double angles1[3] = {0, 0, -90};
	double angles2[3] = {0, 0, 90};
	double trans1[3] = {100, 500, 50};
	double trans2[3] = {550, 150, 50};

	tr1.setRotation(angles1);
	tr1.setTranslation(trans1);
	tr1.initialize();

	tr2.setRotation(angles2);
	tr2.setTranslation(trans2);
	tr2.initialize();

	pc1 = tr1.doTransform(pc1);
	pc2 = tr2.doTransform(pc2);

	PointCloud pc3;
	pc3 = pc1 + pc2;

	PointCloudRecorder recorder;
	recorder.setFileName("cloud.txt");

	recorder.save(pc3);

	return 0;
}