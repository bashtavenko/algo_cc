#include "arrays/diagonal.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(RunDiagonally, Works) {
  const std::vector<std::vector<int32_t>> data{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  const std::vector<int32_t> want{1, 2, 4, 3, 5, 7, 6, 8, 9};
  EXPECT_THAT(RunDiagonally(data), want);
}

TEST(RunDiagonally, ForByFourWorks) {
  const std::vector<std::vector<int32_t>> data{
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  const std::vector<int32_t> want{1,  2,  5, 3,  6,  9,  4,  7,
                                  10, 13, 8, 11, 14, 12, 15, 16};
  EXPECT_THAT(RunDiagonally(data), want);
}

}  // namespace
}  // namespace algo