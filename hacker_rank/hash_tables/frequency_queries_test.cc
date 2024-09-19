#include "hacker_rank/hash_tables/frequency_queries.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(FreqQuery, Example1Works) {
  const std::vector<std::vector<int>> data{{1, 5}, {1, 6}, {3, 2}};
  const std::vector<int> want{0};
  EXPECT_THAT(FreqQuery(data), want);
}

TEST(FreqQuery, Example2Works) {
  const std::vector<std::vector<int>> data{{1, 5},  {1, 6}, {3, 2}, {1, 10},
                                           {1, 10}, {1, 6}, {2, 5}, {3, 2}};
  const std::vector<int> want{0, 1};
  EXPECT_THAT(FreqQuery(data), want);
}

TEST(FreqQuery, Example3Works) {
  const std::vector<std::vector<int>> data{{3, 4}, {2, 1003}, {1, 16}, {3, 1}};
  const std::vector<int> want{0, 1};
  EXPECT_THAT(FreqQuery(data), want);
}