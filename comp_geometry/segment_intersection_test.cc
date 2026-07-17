#include "comp_geometry/geometry.h"
#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"

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

} // namespace
} // namespace geometry