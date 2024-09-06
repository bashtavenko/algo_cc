#include "hacker_rank/strings/substr_count.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>

TEST(SubstrCount, Works) {
  EXPECT_THAT(SubstrCount("mnonopoo"), 12);
  EXPECT_THAT(SubstrCount("asasd"), 7);
  EXPECT_THAT(SubstrCount("abcbaba"), 11);  // Should be 10?
}