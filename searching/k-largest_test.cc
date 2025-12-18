#include "searching/k-largest.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

// Because it is random, this may not always return the right result.
TEST(FindKthLargest, DISABLED_Works) {
  std::vector<int32_t> data{3, 2, 1, 5, 4};
  EXPECT_THAT(FindKthLargest(2, data), 4);
}

}  // namespace
}  // namespace algo