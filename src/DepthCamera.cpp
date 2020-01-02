#include"DepthCamera.h"
#include<iostream>
#include<fstream>
using namespace std;

//! reads files without transforming
PointCloud DepthCamera :: capture() { 
	PointCloud points;
	double x, y, z;
	ifstream file;

    //! open file for read
	file.open(fileName);

	//! read entire file
	while (!file.eof())
	{
        //! get points
		file >> x >> y >> z;

		//! set points
		points.addPoint(x, y, z);

	}

	file.close();
	return points;
}//! end of capture

//! sets filename
void DepthCamera::setfileName(string fName) 
{
    //! set file name
	fileName = fName;
}//! end of setfileName()

//! returns filename
string DepthCamera::getfileName() {
    //! return filename
	return fileName;
}//!end of getfilename()

//! reads file, filter and then transforms each point
PointCloud DepthCamera::captureFor() {
    PointCloud points;
    double x, y, z;
    ifstream file;

    //! open file for read
    file.open(fileName);

    //! read entire file
    while (!file.eof())
    {
        //! get points
        file >> x >> y >> z;

        //!set points
        points.addPoint(x, y, z);

    }

    //! filters out
    filterpipe.filterout(points);

    //! set Tranlation vector
    transform.setTranslation();
    //! set rotation angles
    transform.setRotation();
    //! initialize them to matrix
    transform.initialize();
    //! transform point cloud
    transform.doTransform(points);


    file.close();
    return points;
}//! end of capturefor()