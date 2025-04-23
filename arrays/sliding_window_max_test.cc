#include "arrays/sliding_window_max.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ElementsAreArray;

TEST(SlidingWindows, Works) {
  EXPECT_THAT(SlidingWindowMax(std::vector<int32_t>{3, 4, 1, 2, 7, 5}, 2),
              ElementsAreArray({4, 4, 2, 7, 7}));
}

}  // namespace
}  // namespace algo