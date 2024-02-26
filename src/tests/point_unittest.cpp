#include "pointlib/point.h"
#include "gtest/gtest.h"

TEST(PointTest, DistanceCalculation) {
  Point p1(1, 2);
  Point p2(4, 6);
  EXPECT_DOUBLE_EQ(p1.distance(p2), 5.0);
}

TEST(LineTest, Intersection) {
  Point p1(1, 1);
  Point p2(4, 4);
  Point p3(1, 4);
  Point p4(4, 1);
  Line line1(p1, p2);
  Line line2(p3, p4);
  Point intersection_point = line1.intersection(line2);
  EXPECT_DOUBLE_EQ(intersection_point.x, 2.5);
  EXPECT_DOUBLE_EQ(intersection_point.y, 2.5);
}

TEST(LineTest, Perpendicular) {
  Point p1(1, 1);
  Point p2(4, 4);
  Line line1(p1, p2);
  Point p3(2, 1);
  Line perpendicular_line = line1.perpendicular(p3);

  EXPECT_DOUBLE_EQ(perpendicular_line.a, -1.0);
  EXPECT_DOUBLE_EQ(perpendicular_line.b, -1.0);
  EXPECT_DOUBLE_EQ(perpendicular_line.c, 3.0);
}
