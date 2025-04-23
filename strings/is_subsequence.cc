#include <string>
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace strings {

// Given two strings s and t, return true if s is a subsequence of t, or false
// otherwise. A subsequence of a string is a new string that is formed from the
// original string by deleting some (can be none) of the characters without
// disturbing the
//  relative positions of the remaining characters. (i.e., "ace" is a
//  subsequence of "abcde" while "aec" is not).
// "ace"  "abcde" -> true
// "axc"  "ahbgdc" -> false
bool IsSubsequence(const std::string& s, const std::string& t) {
  if (s.empty()) return true;
  int s_index = 0;
  int t_index = 0;

  while (t_index < t.length()) {
    if (t[t_index] == s[s_index]) {
      s_index++;

      if (s_index == s.length()) {
        return true;
      }
    }
    t_index++;
  }
  return false;
}

TEST(IsSubsequence, Works) { EXPECT_TRUE(IsSubsequence("abc", "ahbgdc")); }

TEST(IsSubsequence, Works2) { EXPECT_TRUE(IsSubsequence("ace", "abcde")); }

}  // namespace strings
}  // namespace algo
