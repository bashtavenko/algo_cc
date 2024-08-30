#include "hacker_rank/repeated_string.h"
#include <string>

long RepeatedString(const std::string& s, long n) {
  // "abcac"
  // "abcacabcac"
  //
  // "aba"
  // "abaabaabaa"
  if (s.empty()) return 0;

  long full_repeats = n / s.length();
  long remaining_chars = n % s.length();

  // Count 'a's in the full string
  long count_in_full = 0;
  for (char c : s) {
    if (c == 'a') count_in_full++;
  }

  // Count 'a's in the remaining part
  long count_in_remaining = 0;
  for (long i = 0; i < remaining_chars; i++) {
    if (s[i] == 'a') count_in_remaining++;
  }

  // Calculate total count
  return (full_repeats * count_in_full) + count_in_remaining;
}