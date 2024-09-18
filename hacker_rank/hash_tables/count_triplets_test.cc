#include "hacker_rank/hash_tables/count_triplets.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(CountTriplets, Works) {
  EXPECT_THAT(CountTriplets(std::vector<long>{1, 4, 16, 64}, 4), 2);
  EXPECT_THAT(CountTriplets(std::vector<long>{1, 2, 2, 4}, 2), 2);
  EXPECT_THAT(CountTriplets(std::vector<long>{1, 3, 9, 9, 27, 81}, 3), 6);
}