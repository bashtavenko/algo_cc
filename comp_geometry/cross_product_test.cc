#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "comp_geometry/geometry.h"
#include "absl/log/log.h"

namespace geometry {
namespace {
// Assuming origin is in the top left corner of the screen
//  (0,0) ----> x
//    |
//    | y
TEST(CrossProduct, CounterClockwize) {
  Point p0(100, 100);
  Point p1(150, 50);
  Point p2(100, 10);
  LOG(INFO) << p0;
  EXPECT_THAT(p0.CrossProduct(p1, p2), -4500);;
}

TEST(CrossProduct, Clockwize) {
  Point p0(100, 100);
  Point p1(50, 50);
  Point p2(100, 10);
  EXPECT_THAT(p0.CrossProduct(p1, p2), 4500);;
}

TEST(CrossProduct, Colinear) {
  Point p0(100, 100);
  Point p1(100, 50);
  Point p2(100, 10);
  EXPECT_THAT(p0.CrossProduct(p1, p2), 0);;
}

} // namespace
} // namespace geometry