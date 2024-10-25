#include "hacker_rank/one_month/week_2/sum_xor.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(SumXor, Works) {
  EXPECT_THAT(SumXor(4), 4);
  EXPECT_THAT(SumXor(5), 2);
}

}  // namespace