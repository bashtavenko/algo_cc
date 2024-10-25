#include "hacker_rank/one_month/week_2/dynamic_array.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using ::testing::Eq;

TEST(DynamicArray, Works) {
  EXPECT_THAT(
      DynamicArray(2,
                   std::vector<std::vector<int>>{
                       {1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}}),
      Eq(std::vector<int>{7, 3}));
}
}  // namespace