#include "PointCloudGenerator.h"

//! constructor
PointCloudGenerator::PointCloudGenerator() {}

//! destructor
PointCloudGenerator::~PointCloudGenerator() {
    delete filterpipe;
}

//! pure virtual function to get PointClouds
PointCloud PointCloudGenerator::capture() {}

//! pure virtual function to get,filter and transform PointClouds
PointCloud PointCloudGenerator::captureFor() {}

//! sets filer
void PointCloudGenerator::setFilterPipe(FilterPipe *filter) {
    filterpipe = filter;
}

