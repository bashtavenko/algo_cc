#include "hacker_rank/arrays/minimum_swap.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>

TEST(MinimumSwap, BasicWorks) {
  std::vector<int> arr{4, 3, 1, 2};
  EXPECT_THAT(MinimumSwap(arr), 3);

  arr = {7, 1, 3, 2, 4, 5, 6};
  EXPECT_THAT(MinimumSwap(arr), 5);

  arr = {7, 1, 3, 2, 4, 5, 6};
  EXPECT_THAT(MinimumSwap(arr), 5);
}