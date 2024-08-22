#include "sorting/merge_two_sorted.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(Merge, Works) {
  const std::vector<int32_t> a{5, 13, 17, 20};
  const std::vector<int32_t> b{3, 7, 11, 19, 20};
  const std::vector<int32_t> want{3, 5, 7, 11, 13, 17, 19, 20, 20};
  EXPECT_THAT(MergeTwoSorted(a, b), want);
}

}  // namespace
}  // namespace algo