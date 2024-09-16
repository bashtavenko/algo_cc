#include "hacker_rank/hach_tables/two_strings.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(TwoStrings, Works) {
  EXPECT_TRUE(TwoStrings("and", "art"));
  EXPECT_FALSE(TwoStrings("be", "cat"));
  EXPECT_TRUE(TwoStrings("hello", "world"));
  EXPECT_FALSE(TwoStrings("hi", "world"));
}