#include "sorting/interval_non_overlap.h"
#include "include/gmock/gmock-matchers.h"
#include "include/gtest/gtest.h"

namespace algo {
namespace {

TEST(EraseOvelapIntervals, Example1) {
  std::vector<std::vector<int32_t>> intervals = {
      {1, 2}, {2, 3}, {3, 4}, {1, 3}};
  EXPECT_THAT(EraseOvelapIntervals(intervals), 1);
}

TEST(EraseOvelapIntervals, Example2) {
  std::vector<std::vector<int32_t>> intervals = {{1, 2}, {1, 2}, {1, 2}};
  EXPECT_THAT(EraseOvelapIntervals(intervals), 2);
}

TEST(EraseOvelapIntervals, Example3) {
  std::vector<std::vector<int32_t>> intervals = {{1, 2}, {2, 3}};
  EXPECT_THAT(EraseOvelapIntervals(intervals), 0);
}

}  // namespace
}  // namespace algo