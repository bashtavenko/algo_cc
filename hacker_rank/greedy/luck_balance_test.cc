#include "hacker_rank/greedy/luck_balance.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>

namespace {

TEST(LuckBalance, Works) {
  std::vector<std::vector<int>> contests{{5, 1}, {1, 1}, {4, 0}};
  EXPECT_THAT(LuckBalance(2, contests), 10);
  EXPECT_THAT(LuckBalance(1, contests), 8);
}

TEST(LuckBalance, ExampleWorks) {
  std::vector<std::vector<int>> contests{{5, 1}, {2, 1},  {1, 1},
                                         {8, 1}, {10, 0}, {5, 0}};
  EXPECT_THAT(LuckBalance(3, contests), 29);
}

}  // namespace