#include "PointCloudGenerator.h"

//! constructor
PointCloudGenerator::PointCloudGenerator() {}

//! destructor
PointCloudGenerator::~PointCloudGenerator() {}

//! sets filter
void PointCloudGenerator::setFilterPipe(FilterPipe *filter) {
    filterpipe = filter;
}

// !sets transform
void PointCloudGenerator::setTransform(Transform *tr) {
    transform = tr;
}

