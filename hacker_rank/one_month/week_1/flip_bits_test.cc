#include "hacker_rank/one_month/week_1/flip_bits.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(FlipBits, Works) {
  EXPECT_THAT(FlipBits(2147483647), 2147483648);
  EXPECT_THAT(FlipBits(1), 4294967294);
  EXPECT_THAT(FlipBits(0), 4294967295);
}

}  // namespace