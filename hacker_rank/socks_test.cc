#include "hacker_rank/socks.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(GetSocksPairs, Works) {
  EXPECT_THAT(
      GetSocksPairs(std::vector<int>{10, 20, 20, 10, 10, 30, 50, 10, 20}), 3);
}
