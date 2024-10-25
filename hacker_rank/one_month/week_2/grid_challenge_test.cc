#include "hacker_rank/one_month/week_2/grid_challenge.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace {

TEST(GridChallenge, Works) {
  auto grid =
      std::vector<std::string>{"ebacd", "fghij", "olmkn", "trpqs", "xywuv"};
  //  EXPECT_TRUE(GridChallenge(grid));
  //
  //  // mpxz
  //  // abcd
  //  // flmw
  //  grid = std::vector<std::string>{"mpxz", "abcd", "wlmf"};
  //  EXPECT_FALSE(GridChallenge(grid));

  // abc
  // hjk
  // mpg
  // rtv
  grid = std::vector<std::string>{"abc", "hjk", "mpq", "rtv"};
  EXPECT_TRUE(GridChallenge(grid));
}
}  // namespace