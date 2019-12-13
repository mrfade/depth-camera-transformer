#include "gtest/gtest.h"
#include "../src/DepthCamera.h"

TEST(DepthCameraTest, Capture)
{
    PointCloud pc;

    DepthCamera camera;
    camera.setfileName("test.txt");

    pc = camera.Capture();

    EXPECT_EQ(5, pc.getPointNumber());
}

TEST(DepthCameraTest, setGetFileName)
{
    DepthCamera camera;
    camera.setfileName("test.txt");

    EXPECT_STREQ("test.txt", camera.getfileName());
}
