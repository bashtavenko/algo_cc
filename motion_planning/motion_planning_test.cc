#include "motion_planning/motion_planning.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::DoubleNear;
using ::testing::ElementsAreArray;
using ::testing::Eq;

TEST(WillCollide, Works) {
  auto vehicle = Vehicle{.position = Point2D{.x = 10, .y = 10},
                         .heading = 10,
                         .length = 10,
                         .width = 10};
  auto obstacles = std::vector<Obstacle>{
      {std::vector<Point2D>{{.x = 10, .y = 10}, {.x = 20, .y = 30}}}};
  EXPECT_TRUE(WillCollide(vehicle, obstacles));
}

TEST(MinDistance, Works) {
  auto line = LineSegment{{.x = 10, .y = 100}, {.x = 100, .y = 70}};
  auto point = Point2D{.x = 50, .y = 10};
  EXPECT_THAT(MinDistance(point, line), DoubleNear(72.73, 0.01));
}

TEST(FindClosestPoints, Works) {
  EXPECT_THAT(
      FindKClosestPoints(std::vector<Point2D>{{10, 20}, {20, 30}, {100, 120}},
                         Point2D{.x = 11, .y = 21}, 2),
      ElementsAreArray(
          std::vector<Point2D>{{.x = 10, .y = 20}, {.x = 20, .y = 30}}));
}

TEST(IsPointInConvex, InsideWorks) {
  EXPECT_TRUE(IsPointInConvexPolygon(
      Point2D{.x = 70, .y = 20},
      std::vector<Point2D>{{50, 10}, {100, 5}, {70, 50}, {5, 50}}));
}

TEST(IsPointInConvex, OusideWorks) {
  EXPECT_FALSE(IsPointInConvexPolygon(
      Point2D{.x = 200, .y = 20},
      std::vector<Point2D>{{50, 10}, {100, 5}, {70, 50}, {5, 50}}));
}

TEST(Interpolation, Works) {
  TrajectoryPoint p1 = {.position = {10.0, 20.0}, .time = 1.0};
  TrajectoryPoint p2 = {.position = {30.0, 40.0}, .time = 3.0};

  // Interpolate at time = 2.0s (halfway between p1 and p2)
  EXPECT_THAT(Interpolate(p1, p2, 2.0),
              Eq(TrajectoryPoint{.position = {20.0, 30}, .time = 2.0}));
}

}  // namespace
}  // namespace algo