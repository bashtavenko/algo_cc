#include "hacker_rank/search/triple_sum.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>

namespace {

TEST(Triplets, BasicsWorks) {
  EXPECT_THAT(Triplets(std::vector<int>{3, 5, 7}, std::vector<int>{3, 6},
                       std::vector<int>{4, 6, 9}),
              4);
}

TEST(Triplets, Basics2Works) {
  EXPECT_THAT(Triplets(std::vector<int>{1, 3, 5}, std::vector<int>{2, 3},
                       std::vector<int>{1, 2, 3}),
              8);
}

TEST(Triplets, Basics3Works) {
  EXPECT_THAT(Triplets(std::vector<int>{1, 4, 5}, std::vector<int>{2, 3, 3},
                       std::vector<int>{1, 2, 3}),
              5);
}

TEST(Triplets, Basics4Works) {
  EXPECT_THAT(Triplets(std::vector<int>{1, 3, 5, 7}, std::vector<int>{5, 7, 9},
                       std::vector<int>{7, 9, 11, 13}),
              12);
}

// These are the examples of how to get lower or upper bounds
std::vector<int> FindLessOrEqual(const std::vector<int>& data, int target) {
  auto it = std::upper_bound(data.begin(), data.end(), target);
  return std::vector<int>(data.begin(), it);
}

std::vector<int> FindGreaterOrEqual(const std::vector<int>& data, int target) {
  auto it = std::lower_bound(data.begin(), data.end(), target);
  return std::vector<int>(it, data.end());
}

TEST(FindLessOrEqual, Works2) {
  std::vector<int> data{4, 6, 9};
  std::vector<int> want{4, 6};
  EXPECT_THAT(FindLessOrEqual(data, 6), want);
}

TEST(FindGreatOrEqual, Works) {
  std::vector<int> data{3, 6};
  std::vector<int> want{3, 6};
  EXPECT_THAT(FindGreaterOrEqual(data, 3), want);
}
}  // namespace