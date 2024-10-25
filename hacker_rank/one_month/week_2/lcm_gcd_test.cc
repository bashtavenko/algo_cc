#include "hacker_rank/one_month/week_2/lcm_gcd.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using ::testing::Eq;

TEST(GetX, Works) {
  EXPECT_THAT(GetX(std::vector<int>{2, 4}, std::vector<int>{16, 32, 16}),
              Eq(std::vector<int>{4, 8, 16}));
}

}  // namespace