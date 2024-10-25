#include "hacker_rank/one_month/week_2/anagram_min.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(AnagramMin, Works) { EXPECT_THAT(AnagramMin("abcdba"), 1); }
}  // namespace