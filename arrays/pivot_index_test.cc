#include "arrays/pivot_index.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(PivotIndex, Example1) {
  EXPECT_THAT(PivotIndex(std::vector<int32_t>{1, 7, 3, 6, 5, 6}), 3);
}

TEST(PivotIndex, Example2) {
  EXPECT_THAT(PivotIndex(std::vector<int32_t>{1, 2, 3}), -1);
}

TEST(PivotIndex, Example3) {
  EXPECT_THAT(PivotIndex(std::vector<int32_t>{2, 1, -1}), 0);
}

}  // namespace
}  // namespace algo