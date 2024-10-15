#include "hacker_rank/greedy/greedy_florist.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(GetMinimumCost, BasicWorks) {
  EXPECT_THAT(GetMinimumCost(3, std::vector<int>{2, 5, 6}), 13);
  EXPECT_THAT(GetMinimumCost(3, std::vector<int>{1, 2, 3, 4}), 11);
}
TEST(GetMinimumCost, Example1Works) {
  EXPECT_THAT(GetMinimumCost(2, std::vector<int>{2, 5, 6}), 15);
}

TEST(GetMinimumCost, Example2Works) {
  EXPECT_THAT(GetMinimumCost(3, std::vector<int>{1, 3, 5, 7, 9}), 29);
}

}  // namespace