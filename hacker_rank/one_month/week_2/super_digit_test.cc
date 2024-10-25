#include "hacker_rank/one_month/week_2/super_digit.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(SuperDigit, Works) { EXPECT_THAT(SuperDigit("9875", 1), 2); }

}  // namespace