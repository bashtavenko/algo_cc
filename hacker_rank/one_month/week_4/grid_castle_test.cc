#include "hacker_rank/one_month/week_4/grid_castle.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>

namespace {

TEST(MinimumMoves, Works) {
  //  std::vector<std::string>{"2", "2"};
  auto grid = std::vector<std::string>{".X.", ".X.", "..."};
  EXPECT_THAT(MinimumMoves(grid, 0, 0, 0, 2), 2);
  EXPECT_THAT(MinimumMoves(grid, 0, 0, 2, 0), 6);
}

}  // namespace