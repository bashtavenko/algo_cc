#include "dp/longest_nondecreasing.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(LongestNonDecreasingSubsequenceLength, Works) {
  EXPECT_THAT(LongestNonDecreasingSubsequenceLength(
                  std::vector<int32_t>{0, 8, 4, 12, 2, 10, 6, 14, 1, 9}),
              4);
}

}  // namespace
}  // namespace algo