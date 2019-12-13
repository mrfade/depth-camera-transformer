#include "gtest/gtest.h"
#include "../src/PointCloud.h"
#include <vector>

TEST(PointCloudTest, AddPoint1) {
	PointCloud pc;
	pc.addPoint(1, 2, 3);
	pc.addPoint(2, 3, 4);
	pc.addPoint(3, 4, 5);
	EXPECT_EQ(3, pc.getPointNumber());
}

TEST(PointCloudTest, AddPoint2) {
	Point p1(1, 2, 3), p2(2, 3, 4), p3(3, 4, 5);
	PointCloud pc;
	pc.addPoint(p1);
	pc.addPoint(p2);
	pc.addPoint(p3);
	EXPECT_EQ(3, pc.getPointNumber());
}

TEST(PointCloudTest, OperatorPlusAndEqual) {
	PointCloud pc1, pc2, pc3;
	pc1.addPoint(1, 2, 3);
	pc1.addPoint(2, 3, 4);
	pc1.addPoint(3, 4, 5);
	pc2.addPoint(4, 5, 6);
	pc2.addPoint(5, 6, 7);
	pc2.addPoint(6, 7, 8);

	pc3 = pc1 + pc2;
	
	std::vector<Point> expected_pts = {
		Point(1, 2, 3),
		Point(2, 3, 4),
		Point(3, 4, 5),
		Point(4, 5, 6),
		Point(5, 6, 7),
		Point(6, 7, 8)
	};

	std::vector<Point> points = pc3.getPoints();
	for (int i = 0; i < pc3.getPointNumber(); i++)
	{
		EXPECT_EQ(expected_pts[i].get_x(), points[i].get_x());
		EXPECT_EQ(expected_pts[i].get_y(), points[i].get_y());
		EXPECT_EQ(expected_pts[i].get_z(), points[i].get_z());
	}
}
