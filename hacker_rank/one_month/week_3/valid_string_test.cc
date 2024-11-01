#include "hacker_rank/one_month/week_3/valid_string.h"
#include <gtest/gtest.h>

.namespace {
  TEST(IsValid, Works) {
    EXPECT_FALSE(IsValid("aabbcd"));
    EXPECT_FALSE(IsValid("aabbccddeefghi"));
    EXPECT_TRUE(IsValid("abcdefghhgfedecba"));
  }
}  // namespace