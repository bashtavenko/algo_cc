#include "hacker_rank/greedy/max_min.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace {

TEST(MaxMin, VeryBasicWorks) {
  EXPECT_THAT(MaxMin(2, std::vector<int>{1, 4, 7, 2}), 1);
  EXPECT_THAT(MaxMin(3, std::vector<int>{10, 100, 300, 200, 1000, 20, 30}), 20);
}

TEST(MaxMin, Example1Works) {
  EXPECT_THAT(MaxMin(4, std::vector<int>{1, 2, 3, 4, 10, 20, 30, 40, 100, 200}),
              3);
}
TEST(MaxMin, Example2Works) {
  EXPECT_THAT(MaxMin(2, std::vector<int>{1, 2, 1, 2, 1}), 0);
}
}  // namespace