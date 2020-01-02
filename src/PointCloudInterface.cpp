#include "PointCloudInterface.h"

void PointCloudInterface::addGenerator(PointCloudGenerator*gen)
{
	generators.push_back(gen);
}

void PointCloudInterface::setRecorder(PointCloudRecorder* rec)
{
	recorder = rec;
}

bool PointCloudInterface::generate()
{
	PointCloud tmp(0);
    for(int i=0;i<generators.size();i++)
    	{
		    tmp = generators[i]->captureFor();
	    	pointCloud = pointCloud + tmp;	
    	}

	return true;
}

bool PointCloudInterface::record()
{
	if (recorder->save(pointCloud))
		return true;
	else
		return false;
}
