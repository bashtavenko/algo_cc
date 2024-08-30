#include "hacker_rank/repeated_string.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>

TEST(RepeatedString, BasicsWorks) {
  EXPECT_THAT(RepeatedString("abcac", 10), 4);
  EXPECT_THAT(RepeatedString("aba", 10), 7);
}