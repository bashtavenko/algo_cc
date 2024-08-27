#include "dp/bootcamp.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <unordered_map>

namespace algo {
namespace {

TEST(FibonacciBasic, Works) { EXPECT_THAT(FibonacciBasic(5), 5); }

TEST(FibonacciCached, Works) {
  std::unordered_map<int32_t, int32_t> cache;
  EXPECT_THAT(FibonacciCached(5, &cache), 5);
}

TEST(FibonacciIterative, Works) { EXPECT_THAT(FibonacciIterative(5), 5); }

TEST(FindMaximumSubarray, Works) {
  EXPECT_THAT(FindMaximumSubarray(std::vector<int32_t>{904, 40, 523, 12, -335,
                                                       -385, -124, 481, -31}),
              1479);
}

}  // namespace
}  // namespace algo