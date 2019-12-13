#include "gtest/gtest.h"
#include "../src/RadiusOutlierFilter.h"

TEST(RadiusFilterTest, Filter)
{
    PointCloud pc;
    pc.addPoint(1, 2, 3);
    pc.addPoint(20, 30, 40);
    pc.addPoint(300, 400, 500);

    RadiusOutlierFilter filter;
    filter.setRadius(25);

    filter.filter(pc);

    EXPECT_EQ(2, pc.getPointNumber());
}
