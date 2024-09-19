#include "hacker_rank/sorting/bubble_sort.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(CountSwaps, Works) {
  std::vector<int> data{6, 4, 1};
  SortResult want{.num_swaps = 3, .first_element = 1, .last_element = 6};
  EXPECT_THAT(CountSwaps(data), want);
}