#include "gtest/gtest.h"
#include "../src/Point.h"

TEST(PointTest, Construct)
{
	Point p(1, 2, 3);
	EXPECT_EQ(1.0, p.get_x());
	EXPECT_EQ(2.0, p.get_y());
	EXPECT_EQ(3.0, p.get_z());
}

TEST(PointTest, Distance)
{
	Point p1(11, 12, 13);
	Point p2(21, 22, 23);
	EXPECT_EQ(17.32, p1.distance(p2));
}

TEST(PointTest, EqualsTrue)
{
	Point p1(11, 12, 13);
	Point p2(11, 12, 13);
	EXPECT_TRUE(p1 == p2);
}

TEST(PointTest, EqualsFalse)
{
	Point p1(11, 12, 13);
	Point p2(21, 22, 23);
	EXPECT_FALSE(p1 == p2);
}