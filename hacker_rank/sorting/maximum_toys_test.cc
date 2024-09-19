#include "hacker_rank/sorting/maximum_toys.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(MaximumToys, Works) {
  std::vector<int> data{1, 2, 3, 4};
  EXPECT_THAT(MaximumToys(data, 7), 3);

  data = {1, 12, 5, 111, 200, 1000, 10};
  EXPECT_THAT(MaximumToys(data, 50), 4);
}