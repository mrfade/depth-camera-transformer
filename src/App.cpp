#include <Eigen/Dense>
#include "DepthCamera.h"
#include "PointCloud.h"
#include "PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
#include "PointCloudRecorder.h"
#include "PointCloudInterface.h"
#include "Transform.h"

using namespace std;

int main()
{

	//! Init Recorder
	PointCloudRecorder pclRecorder;
	//! Set the fileName
	pclRecorder.setFileName("cloud.txt");

	//! Init camera
	DepthCamera camera1, camera2;
	//! Set fileNames
	camera1.setfileName("camera1.txt");
	camera2.setfileName("camera2.txt");

	//! Init RadiusFilter
	RadiusOutlierFilter rof;
	//! Set the radius
	rof.setRadius(25.0);

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

	//! Init FilterPipe
	FilterPipe fp1, fp2;
	//! Add filters
	fp1.addFilter(&rof);
	fp1.addFilter(&filter1);

	//! Add filters
	fp2.addFilter(&rof);
	fp2.addFilter(&filter2);

	//! Assign filters to DepthCameras
	camera1.setFilterPipe(&fp1);
	camera2.setFilterPipe(&fp2);

	//! Init Transform
	Transform tr1, tr2;

	//! Declare the angles and coordinates for translation
	Eigen::Vector3d angles1(0, 0, -90);
	Eigen::Vector3d angles2(0, 0, 90);
	Eigen::Vector3d trans1(100, 500, 50);
	Eigen::Vector3d trans2(550, 150, 50);

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

	//! Assign transform object to DepthCameras
	camera1.setTransform(&tr1);
	camera2.setTransform(&tr2);

	//! Init PointCloudInterfase
	PointCloudInterface pci1;
	//! Add generators
	pci1.addGenerator(&camera1);
	pci1.addGenerator(&camera2);
	//! Set recorder
	pci1.setRecorder(&pclRecorder);

	//! Generate result
	pci1.generate();

	//! Record result using given recorder
	pci1.record();

	//! EXIT
	return 0;
}