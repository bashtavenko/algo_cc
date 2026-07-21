#include "comp_geometry/geometry.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace geometry {
namespace {

// CRLS, third edition, p.1019
TEST(SegmentIntersection, Straddle) {
  Point p1(10, 10);
  Point p2(100, 100);
  Point p3(20, 150);
  Point p4(150, 2);
  EXPECT_TRUE(SegmentIntersect(p1, p2, p3, p4));
}

TEST(SegmentIntersection, NoStraddle) {
  Point p1(10, 10);
  Point p2(20, 5);
  Point p3(12, 200);
  Point p4(200, 2);
  EXPECT_FALSE(SegmentIntersect(p1, p2, p3, p4));
}

TEST(SegmentIntersection, NoStraddle2) {
  Point p1(10, 10);
  Point p2(100, 100);
  Point p4(500, 2);
  Point p3(600, 600);
  EXPECT_FALSE(SegmentIntersect(p1, p2, p3, p4));
}

TEST(AnySegmentsIntersection, NoIntersection) {
  std::vector segments = {
      Line(Point(50, 50), Point(120, 10)),    // a
      Line(Point(150, 60), Point(175, 50)),   // b
      Line(Point(125, 80), Point(100, 150)),  // c
      Line(Point(200, 55), Point(250, 100)),  // d
  };

  EXPECT_FALSE(AnySegmentsIntersect(segments));
}

TEST(AnySegmentsIntersection, Intersect) {
  // Event points of 300 intersect
  // CRLS Figure 33.5, p.1026
  std::vector segments = {
      Line(Point(50, 25), Point(200, 35)),   // a
      Line(Point(100, 85), Point(900, 20)),  // b
      Line(Point(120, 60), Point(300, 40)),  // c
      Line(Point(180, 25), Point(850, 45)),  // d
      Line(Point(250, 20), Point(800, 35)),  // e
      Line(Point(320, 55), Point(650, 80)),  // f
  };

  EXPECT_TRUE(AnySegmentsIntersect(segments));
}

}  // namespace
}  // namespace geometry