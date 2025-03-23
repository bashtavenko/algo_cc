#include "arrays/max_min_pairs.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(MinMaxPairs, Example1) {
  std::vector<int32_t> nums = {1, 4, 3, 2};
  EXPECT_EQ(MinMaxPairs(nums), 4);
}

TEST(MinMaxPairs, Example2) {
  std::vector<int32_t> nums = {6, 2, 6, 5, 1, 2};
  EXPECT_EQ(MinMaxPairs(nums), 9);
}

}  // namespace
}  // namespace algo