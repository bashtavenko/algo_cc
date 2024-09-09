#include "hacker_rank/strings/substr_count.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>

TEST(SubstrCount, Works) {
  EXPECT_THAT(SubstrCount(2, "aa"), 3);
  EXPECT_THAT(SubstrCount(4, "aaaa"), 10);
  EXPECT_THAT(SubstrCount(5, "asasd"), 7);
  EXPECT_THAT(SubstrCount(7, "abcbaba"), 10);
}