#include "strings/max_vowels_substring.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(MaxVowels, Example1Works) { EXPECT_THAT(MaxVowels("abciiidef", 2), 2); }

TEST(MaxVowels, Example2Works) { EXPECT_THAT(MaxVowels("aeiou", 2), 2); }

TEST(MaxVowels, Example3Works) { EXPECT_THAT(MaxVowels("leetcode", 3), 2); }

TEST(MaxVowels, Example4Works) { EXPECT_THAT(MaxVowels("weallloveyou", 7), 4); }

}  // namespace
}  // namespace algo