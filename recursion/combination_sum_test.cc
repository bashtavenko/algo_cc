#include "recursion/combination_sum.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

using ::testing::UnorderedElementsAreArray;

TEST(CombinationSum, Example1) {
  EXPECT_THAT(
      CombinationSum(3, 7),
      UnorderedElementsAreArray(std::vector<std::vector<int32_t>>{{1, 2, 4}}));
}

TEST(Combination, Example2) {
  EXPECT_THAT(CombinationSum(3, 9),
              UnorderedElementsAreArray(std::vector<std::vector<int32_t>>{
                  {1, 2, 6}, {1, 3, 5}, {2, 3, 4}}));
}

TEST(Combination, Example3) {
  EXPECT_THAT(CombinationSum(4, 1),
              UnorderedElementsAreArray(std::vector<std::vector<int32_t>>{}));
}

}  // namespace
}  // namespace algo