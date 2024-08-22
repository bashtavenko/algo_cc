#include "heaps/sorted_arrays.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(MergeSorted, Works) {
  const std::vector<std::vector<int32_t>> data = {
      {3, 5, 7}, {0, 6}, {0, 6, 28}};
  const std::vector<int32_t> want = {0, 0, 3, 5, 6, 6, 7, 28};
  EXPECT_THAT(MergeSortedArrays(data), want);
}

}  // namespace
}  // namespace algo