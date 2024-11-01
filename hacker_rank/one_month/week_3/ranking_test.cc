#include "hacker_rank/one_month/week_3/ranking.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using ::testing::Eq;

TEST(Rank, Works) {
  EXPECT_THAT(
      Rank(std::vector<int>{100, 90, 90, 80}, std::vector<int>{70, 80, 105}),
      Eq(std::vector<int>{4, 3, 1}));
}
}  // namespace