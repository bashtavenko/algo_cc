#include "hacker_rank/dp/max_subset_sum.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(MaxSubsetSum, BasicWorks) {
  EXPECT_THAT(MaxSubsetSum(std::vector<int>{-2, 1, 3, -4, 5}), 8);
  EXPECT_THAT(MaxSubsetSum(std::vector<int>{-2, -3, -1}), 0);
  EXPECT_THAT(MaxSubsetSum(std::vector<int>{3, 7, 4, 6, 5}), 13);
  EXPECT_THAT(MaxSubsetSum(std::vector<int>{2, 1, 5, 8, 4}), 11);
  EXPECT_THAT(MaxSubsetSum(std::vector<int>{3, 5, -7, 8, 10}), 15);
}
}  // namespace