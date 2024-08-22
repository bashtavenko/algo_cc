#include "heaps/closest_stars.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(FindClosestStars, Works) {
  const std::vector<Star> data{
      {1, 2, 3}, {4, 5, 6}, {1, 1, 1}, {100, 200, 300}};
  const std::vector<Star> want{{1, 1, 1}, {1, 2, 3}};
  auto result = FindClosestStars(data.cbegin(), data.cend(), 2);
  EXPECT_THAT(result, want);
}

}  // namespace
}  // namespace algo