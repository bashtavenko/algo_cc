#include "arrays/longest_binary_subarray.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(LongestBinarySubarray, Example1) {
  EXPECT_THAT(LongestBinarySubarray(std::vector<int32_t>{1, 1, 0, 1}), 3);
}

TEST(LongestBinarySubarray, Example2) {
  EXPECT_THAT(
      LongestBinarySubarray(std::vector<int32_t>{0, 1, 1, 1, 0, 1, 1, 0, 1}),
      5);
}

}  // namespace
}  // namespace algo