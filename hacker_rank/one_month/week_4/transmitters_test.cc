#include "hacker_rank/one_month/week_4/transmitters.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(Transmitters, Works) {
  EXPECT_THAT(Transmitters(std::vector<int>{1, 2, 3, 5, 9}, 1), 3);
  EXPECT_THAT(Transmitters(std::vector<int>{7, 2, 4, 6, 5, 9, 12, 11}, 2), 3);
}

}  // namespace