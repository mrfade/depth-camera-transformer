/**
 * @file PointCloudGenerator.h
 * @author Ersan Tzampaz Chatip (hatipersan@gmail.com)
 * @date December, 2019
 *
 * /brief Generator that gets point cloud.
 *          Either passes point cloud as is or
 *          filters and transforms point cloud.
 *
 * Details
 * If user uses capture() it takes each point and returns it.
 * If the user chooses captureFor() it takes each point, filters them
 * and then transforms each point. Once the program shuts down or the
 * user deletes PointCloudGenerator destructor frees memory held by the
 * filterPipe pointer.
**/
#ifndef OOP_PROJECT_MASTER_POINTCLOUDGENERATOR_H
#define OOP_PROJECT_MASTER_POINTCLOUDGENERATOR_H

#pragma once
#include "PointCloud.h"
#include "Transform.h"
#include "FilterPipe.h"

class PointCloudGenerator
{
protected:
    Transform transform;
    FilterPipe *filterpipe;
public:
    //!constructor
    PointCloudGenerator();
    //! destructor
    ~PointCloudGenerator();
    //! virtual function to collect points
    virtual PointCloud capture() = 0;
    //! virtual function to collect points, filter them and then transform
    virtual PointCloud captureFor() = 0;
    //! function to set filter
    /**
     * @param FilterPipe
     **/
    void setFilterPipe(FilterPipe *);

};


#endif //OOP_PROJECT_MASTER_POINTCLOUDGENERATOR_H
