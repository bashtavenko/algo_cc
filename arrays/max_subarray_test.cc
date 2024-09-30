#include "arrays/max_subarray.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(MaxSubarray, TreeWorks) {
  Result want{.lo = 0, .hi = 2, .sum = 5};
  EXPECT_THAT(MaxSubarray(std::vector<int32_t>{4, -1, 2}), want);
}

TEST(MaxSubarray, TwoWorks) {
  Result want{.lo = 0, .hi = 0, .sum = 3};
  EXPECT_THAT(MaxSubarray(std::vector<int32_t>{3, -2}), want);

  want = {.lo = 0, .hi = 1, .sum = 5};
  EXPECT_THAT(MaxSubarray(std::vector<int32_t>{2, 3}), want);
}

TEST(MaxSubarry, Works) {
  Result want{.lo = 7, .hi = 10, .sum = 43};
  EXPECT_THAT(
      MaxSubarray(std::vector<int32_t>{13, -3, -25, 20, -3, -16, -23, 18, 20,
                                       -7, 12, -5, -22, 15, -4, 7}),
      want);
}

}  // namespace
}  // namespace algo