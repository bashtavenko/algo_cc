#include "hacker_rank/greedy/largest_permutation.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using ::testing::Eq;

TEST(LargestPermutation, BasicWorks) {
  EXPECT_THAT(LargestPermutation(std::vector<int>{2, 1, 3}, 1),
              Eq(std::vector<int>{3, 1, 2}));
  EXPECT_THAT(LargestPermutation(std::vector<int>{2, 1}, 1),
              Eq(std::vector<int>{2, 1}));
}

TEST(LargestPermutation, FourDigitsWorks) {
  EXPECT_THAT(LargestPermutation(std::vector<int>{1, 2, 3, 4}, 1),
              Eq(std::vector<int>{4, 2, 3, 1}));
}

TEST(LargestPermutation, FiveDigitsWorks) {
  EXPECT_THAT(LargestPermutation(std::vector<int>{4, 2, 3, 5, 1}, 1),
              Eq(std::vector<int>{5, 2, 3, 4, 1}));
}

}  // namespace