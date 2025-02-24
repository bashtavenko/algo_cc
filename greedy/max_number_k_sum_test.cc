#include "greedy/max_number_k_sum.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(MaxOperations, Works1) {
  auto nums = std::vector<int32_t>{1, 2, 3, 4};
  EXPECT_THAT(MaxOperations(nums, 5), 2);
}

TEST(MaxOperations, Works2) {
  auto nums = std::vector<int32_t>{3, 1, 3, 4, 3};
  EXPECT_THAT(MaxOperations(nums, 6), 1);
}

}  // namespace
}  // namespace algo