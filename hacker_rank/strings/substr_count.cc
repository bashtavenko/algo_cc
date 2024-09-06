#include "hacker_rank/strings/substr_count.h"
#include <string>

// asasd => 7
// Because {a, s, a, s, d, asa, sas}
// d
// abcbaba => 10
// { a, b, c, b, a, b, a, bcb, bab, aba }
long SubstrCount(const std::string& s) {
  long n = s.length();
  long count = 0;

  // Case 1: All characters in the substring are the same
  for (long i = 0; i < n; i++) {
    long repeat = 0;

    // Count all identical characters in a row
    while (i + repeat < n && s[i] == s[i + repeat]) {
      repeat++;
    }

    // Add all combinations of these identical characters
    count += (repeat * (repeat + 1)) / 2;

    // Move to the end of this block of identical characters
    i += repeat - 1;
  }

  // Case 2: All characters except the middle one are the same
  for (long i = 1; i < n - 1; i++) {
    long left = 1;

    // Check for the middle character being different, and the two ends being
    // identical
    while (i - left >= 0 && i + left < n && s[i] != s[i - left] &&
           s[i - left] == s[i + left]) {
      count++;
      left++;
    }
  }

  return count;
}