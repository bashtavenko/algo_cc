#include "hacker_rank/one_month/week_1/lonely_integer.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
TEST(LonelyInteger, Works) {
  EXPECT_THAT(LonelyInteger(std::vector<int>{1, 2, 3, 4, 3, 2, 1}), 4);
}

}  // namespace
