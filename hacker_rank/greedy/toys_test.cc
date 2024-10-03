#include "hacker_rank/greedy/toys.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(MakeContainers, SmokeTestWork) {
  std::vector<int> data{std::vector<int>{1, 2, 3, 4, 5, 10, 11, 12, 13}};
  EXPECT_THAT(MakeContainers(data), 2);
}

TEST(MakeContainers, Example1Work) {
  std::vector<int> data{std::vector<int>{1, 2, 3, 21, 7, 12, 14, 21}};
  EXPECT_THAT(MakeContainers(data), 4);
}

}  // namespace