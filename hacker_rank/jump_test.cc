#include "hacker_rank/jump.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(JumpOnClouds, WorksBasics) {
  EXPECT_THAT(JumpOnClouds(std::vector<int>{0, 1, 0, 0, 0, 1, 0}), 3);
}

TEST(JumpOnClouds, Works) {
  EXPECT_THAT(JumpOnClouds(std::vector<int>{0, 0, 1, 0, 0, 1, 0}), 4);
}