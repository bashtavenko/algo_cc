#include "hacker_rank/arrays/new_year_chaos.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(MinimumSwaps, BasicCase) {
  Result result;
  result = MinimumSwaps(std::vector<int>{1, 2, 3, 5, 4, 6, 7, 8});
  EXPECT_THAT(result.bribes, 1);
  EXPECT_FALSE(result.too_chaotic);

  result = MinimumSwaps(std::vector<int>{2, 1, 5, 3, 4});
  EXPECT_THAT(result.bribes, 3);
  EXPECT_FALSE(result.too_chaotic);

  result = MinimumSwaps(std::vector<int>{2, 5, 1, 3, 4});
  EXPECT_THAT(result.bribes, 3);
  EXPECT_TRUE(result.too_chaotic);
}
