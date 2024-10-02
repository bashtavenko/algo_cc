#include "dp/knapsack.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>

namespace algo {
namespace {

TEST(OptimumSubjectToCapacity, SuperSimpleWorks) {
  EXPECT_THAT(OptimumSubjectToCapacity(
                  std::vector<Item>{{60, 1}, {100, 2}, {120, 3}}, 5),
              220);
}

TEST(OptimumSubjectToCapacity, AnotherSuperSimpleWorks) {
  EXPECT_THAT(
      OptimumSubjectToCapacity(std::vector<Item>{{10, 4}, {4, 2}, {7, 3}}, 5),
      11);
}

TEST(OptimumSubjectToCapacity, AlsoSimpleWorks) {
  EXPECT_THAT(OptimumSubjectToCapacity(
                  std::vector<Item>{{60, 5}, {50, 3}, {70, 4}, {30, 2}}, 5),
              80);
}

TEST(OptimumSubjectToCapacity, ClockExampleWorks) {
  EXPECT_THAT(OptimumSubjectToCapacity(std::vector<Item>{{65, 20},
                                                         {35, 8},
                                                         {245, 60},
                                                         {195, 55},
                                                         {65, 40},
                                                         {150, 70},
                                                         {275, 85},
                                                         {155, 25},
                                                         {120, 30},
                                                         {320, 65},
                                                         {75, 75},
                                                         {40, 10},
                                                         {200, 95},
                                                         {100, 50},
                                                         {220, 40},
                                                         {99, 10}},
                                       130),
              695);
}

}  // namespace
}  // namespace algo