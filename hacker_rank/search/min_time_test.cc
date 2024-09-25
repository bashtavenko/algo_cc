#include "hacker_rank/search/min_time.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(MinTime, BasicWorks) {
  EXPECT_THAT(MinTime(std::vector<long>{2, 3, 2}, 10), 8);
}

}  // namespace