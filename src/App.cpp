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
	//! Init camera
	DepthCamera camera1, camera2;
	//! Set fileNames
	camera1.setfileName("camera1.txt");
	camera2.setfileName("camera2.txt");

	//! Init PointClouds
	PointCloud pc1, pc2;
	//! Take data from camera
	pc1 = camera1.Capture();
	pc2 = camera2.Capture();

	//! Init RadiusFilter
	RadiusOutlierFilter rof;
	//! Set the radius
	rof.setRadius(25.0);

	//! Filter the data
	rof.filter(pc1);
	rof.filter(pc2);

	//! Init ConstraitFilter
	PassThroughFilter filter1, filter2;
	//! Set upper lower boundaries for Camera1
	filter1.setlowerLimitX(0.0);
	filter1.setupperLimitX(400.0);
	filter1.setlowerLimitY(0.0);
	filter1.setupperLimitY(400.0);
	filter1.setlowerLimitZ(-45.0);
	filter1.setupperLimitZ(45.0);
	
	//! Set upper lower boundaries for Camera2
	filter2.setlowerLimitX(0.0);
	filter2.setupperLimitX(500.0);
	filter2.setlowerLimitY(0.0);
	filter2.setupperLimitY(500.0);
	filter2.setlowerLimitZ(-45.0);
	filter2.setupperLimitZ(45.0);

	//! Filter the data
	filter1.filter(pc1);
	filter2.filter(pc2);

	//! Init Transform
	Transform tr1, tr2;

	//! Declare the angles and coordinates for translation
	double angles1[3] = {0, 0, -90};
	double angles2[3] = {0, 0, 90};
	double trans1[3] = {100, 500, 50};
	double trans2[3] = {550, 150, 50};

	//! Set data for Camera1
	tr1.setRotation(angles1);
	tr1.setTranslation(trans1);
	//! Initialize the transform matrix
	tr1.initialize();

	//! Set data for Camera2
	tr2.setRotation(angles2);
	tr2.setTranslation(trans2);
	//! Initialize the transform matrix
	tr2.initialize();

	//! DO TRANSFORM
	pc1 = tr1.doTransform(pc1);
	pc2 = tr2.doTransform(pc2);

	//! Merge the points to one PointCloud
	PointCloud pc3;
	pc3 = pc1 + pc2;

	//! Init the FileRecorder
	PointCloudRecorder recorder;
	//! Set output fileName
	recorder.setFileName("cloud.txt");

	//! Save data
	recorder.save(pc3);

	//! EXIT
	return 0;
}