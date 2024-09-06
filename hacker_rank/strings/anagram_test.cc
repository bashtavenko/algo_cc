#include "hacker_rank/strings/anagram.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(MakeAnagram, Works) {
  EXPECT_THAT(MakeAnagram("cde", "dcf"), 2);
  EXPECT_THAT(MakeAnagram("cde", "abc"), 4);
}