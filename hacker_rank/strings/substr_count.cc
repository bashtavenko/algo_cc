#include "hacker_rank/strings/substr_count.h"
#include <string>

// "aaaa" = {a, a, a, a, aa, aaa, aaaa, aa, aaa, aa}
// 5, "asasd" => 7
// Because {a, s, a, s, d, asa, sas}
// d
// abcbaba => 10
// { a, b, c, b, a, b, a, bcb, bab, aba }

long SubstrCount(int n, const std::string& s) {
  long count = n;  // Each individual character is a special substring

  // 1. Count substrings where all characters are the same
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    int j = i + 1;
    while (j < n && s[j] == c) {
      ++count;
      ++j;
    }
  }

  // 2. Count substrings where all characters except the middle one are the
  // same. The same way, try to substring and check the middle
  for (int i = 1; i < n - 1; ++i) {
    int lo = i - 1;
    int hi = i + 1;
    if (s[lo] != s[i] && s[lo] == s[hi]) {
      ++count;
      while (lo > 0 && hi < n - 1 && s[lo - 1] == s[lo] && s[hi + 1] == s[hi]) {
        ++count;
        --lo;
        ++hi;
      }
    }
  }

  return count;
}