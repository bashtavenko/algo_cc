#include "hacker_rank/hash_tables/anagramic_pairs.h"
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

int FindAnagramPairsMyAttempt(const std::string& s) {
  int substring_count = 0;
  std::unordered_map<std::string, std::vector<std::string>>
      sorted_strings_to_anagram;
  for (size_t len = 1; len <= s.size(); ++len) {
    for (size_t i = 0; i <= s.size() - len; ++i) {
      std::string substr = s.substr(i, len);
      std::string sorted(substr);
      std::sort(sorted.begin(), sorted.end());
      sorted_strings_to_anagram[sorted].emplace_back(substr);
    }
  }

  for (const auto& [_, anagram] : sorted_strings_to_anagram) {
    if (anagram.size() >= 2) ++substring_count;
  }

  return substring_count;
}

// Standard solution for anagram checking - sort and put it into hash map.
int FindAnagramPairs(const std::string& s) {
  int anagram_pairs = 0;
  std::unordered_map<std::string, int> sorted_substrings;

  for (size_t len = 1; len <= s.size(); ++len) {
    for (size_t i = 0; i <= s.size() - len; ++i) {
      std::string substr = s.substr(i, len);
      std::sort(substr.begin(), substr.end());
      anagram_pairs += sorted_substrings[substr]++;
    }
  }

  return anagram_pairs;
}