#include "heaps/k_largest.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(FindKthLargest, Example1) {
  EXPECT_THAT(FindKthLargest(std::vector<int32_t>{3, 2, 1, 5, 6, 4}, 2), 5);
}

TEST(FindKthLargest, Example2) {
  EXPECT_THAT(
      FindKthLargest(std::vector<int32_t>{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4), 4);
}

}  // namespace
}  // namespace algo
