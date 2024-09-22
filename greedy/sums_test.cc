#include "greedy/sums.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(HasTwoSum, Works) {
  const std::vector<int32_t> data = {-2, 1, 2, 4, 7, 11};
  EXPECT_TRUE(HasTwoSum(data, 6));
  EXPECT_TRUE(HasTwoSum(data, 5));
  EXPECT_TRUE(HasTwoSum(data, 0));
  EXPECT_TRUE(HasTwoSum(data, 13));
  EXPECT_FALSE(HasTwoSum(data, 25));
}

TEST(HasTwoSum2, Works) {
  const std::vector<int32_t> data = {2, 3, 5, 7, 11};
  EXPECT_TRUE(HasTwoSum(data, 16));
}

TEST(HasThreeSum, Works) {
  const std::vector<int32_t> data = {11, 2, 5, 7, 3};
  EXPECT_TRUE(HasThreeSum(data, 21));
  EXPECT_FALSE(HasThreeSum(data, 100));
}

TEST(HasUnsortedTwoSum, Works) {
  EXPECT_TRUE(HasUnsortedTwoSum(std::vector<int32_t>{2, 3, 5, 7, 11}, 16));
}

}  // namespace
}  // namespace algo