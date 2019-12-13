#include "gtest/gtest.h"
#include "../src/PointCloudRecorder.h"

TEST(PointCloudRecorderTest, Filter)
{
    PointCloud pc;
    pc.addPoint(1, 2, 3);
    pc.addPoint(20, 30, 40);
    pc.addPoint(300, 400, 500);

    PointCloudRecorder recorder;
    recorder.setFileName("recordertest.txt");

    EXPECT_TRUE(recorder.save(pc));
}

TEST(PointCloudRecorderTest, setGetFileName)
{
    PointCloudRecorder recorder;
    recorder.setFileName("test.txt");

    EXPECT_STREQ("test.txt", recorder.getFileName());
}
