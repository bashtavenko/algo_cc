#include "arrays/increasing_triplets.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(IncreasingTriplets, Works) {
  auto nums = std::vector<int32_t>({1, 2, 3, 4, 5});
  EXPECT_TRUE(IncreasingTriplets(nums));

  nums = std::vector<int32_t>({5, 4, 3, 2, 1});
  EXPECT_FALSE(IncreasingTriplets(nums));

  nums = std::vector<int32_t>({2, 1, 5, 0, 4, 6});
  EXPECT_TRUE(IncreasingTriplets(nums));

  nums = std::vector<int32_t>({1, 1, -2, 6});
  EXPECT_FALSE(IncreasingTriplets(nums));
}

}  // namespace
}  // namespace algo
