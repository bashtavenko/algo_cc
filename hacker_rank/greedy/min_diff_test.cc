#include "hacker_rank/greedy/min_diff.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(MinimumAbsoluteDif, BasicWorks) {
  EXPECT_THAT(MinimumAbsoluteDif(std::vector<int>{-2, 2, 4}), 2);
  EXPECT_THAT(MinimumAbsoluteDif(std::vector<int>{3, -7, 0}), 3);
  EXPECT_THAT(MinimumAbsoluteDif(std::vector<int>{-59, -36, -13, 1, -53, -92,
                                                  -2, -96, -54, 75}),
              1);
  EXPECT_THAT(MinimumAbsoluteDif(std::vector<int>{1, -3, 71, 68, 17}), 3);
}

}  // namespace