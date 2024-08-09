#include "heaps/almost_sorted.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>

namespace algo {
namespace {

TEST(AlmostSorted, Works) {
  const std::vector<int32_t> data{3, -1, 2, 6, 4, 5, 8};
  const std::vector<int32_t> want{-1, 2, 3, 4, 5, 6, 8};
  EXPECT_THAT(SortAlmost(2, data.cend(), data.cbegin()), want);
}

}  // namespace
}  // namespace algo
