#include "arrays/max_subarray.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using ::testing::Eq;

TEST(MaxSubarray, TreeWorks) {
  EXPECT_THAT(MaxSubarray(std::vector<int32_t>{4, -1, 2}),
              Eq(Result{.lo = 0, .hi = 2, .sum = 5}));
}

TEST(MaxSubarray, TwoWorks) {
  EXPECT_THAT(MaxSubarray(std::vector<int32_t>{3, -2}),
              Eq(Result{.lo = 0, .hi = 0, .sum = 3}));

  EXPECT_THAT(MaxSubarray(std::vector<int32_t>{2, 3}),
              Eq(Result{.lo = 0, .hi = 1, .sum = 5}));
}

TEST(MaxSubarray, Works) {
  EXPECT_THAT(
      MaxSubarray(std::vector<int32_t>{13, -3, -25, 20, -3, -16, -23, 18, 20,
                                       -7, 12, -5, -22, 15, -4, 7}),
      Eq(Result{.lo = 7, .hi = 10, .sum = 43}));
}

}  // namespace
}  // namespace algo