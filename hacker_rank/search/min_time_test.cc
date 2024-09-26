#include "hacker_rank/search/min_time.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(MinTime, BasicWorks) {
  EXPECT_THAT(MinTime(std::vector<long>{2, 3, 2}, 10), 8);
  EXPECT_THAT(MinTime(std::vector<long>{2, 3}, 5), 6);
  EXPECT_THAT(MinTime(std::vector<long>{1, 3, 4}, 10), 7);
  EXPECT_THAT(MinTime(std::vector<long>{4, 5, 6}, 12), 20);
}

}  // namespace