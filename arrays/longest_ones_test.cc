#include "arrays/longest_ones.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(LongestOnes, Example1) {
  EXPECT_THAT(
      LongestOnes(std::vector<int32_t>{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2), 6);
}

TEST(LongestOnes, Example2) {
  EXPECT_THAT(LongestOnes(std::vector<int32_t>{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1,
                                               1, 0, 0, 0, 1, 1, 1, 1},
                          3),
              10);
}

}  // namespace
}  // namespace algo
