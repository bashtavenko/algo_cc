#include "hacker_rank/one_month/week_2/anagram_min.h"
#include <string>
#include <unordered_map>

int AnagramMin(const std::string& s) {
  const int n = s.size();

  // If the string length is odd, it can't be split equally
  if (n % 2 != 0) return -1;

  int mid = n / 2;
  std::string first_half = s.substr(0, mid);
  std::string second_half = s.substr(mid, mid);

  // Count the frequency of characters in the first and second halves
  std::unordered_map<char, int> freq_first;
  std::unordered_map<char, int> freq_second;

  for (const char& c : first_half) {
    ++freq_first[c];
  }

  for (const char& c : second_half) {
    ++freq_second[c];
  }

  // Count the minimum number of changes
  int changes = 0;
  for (const auto& [char_first, count_first] : freq_first) {
    int count_second = freq_second[char_first];
    if (count_first > count_second) {
      changes += (count_first - count_second);
    }
  }

  return changes;
}