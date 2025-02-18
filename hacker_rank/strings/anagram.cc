#include "hacker_rank/strings/anagram.h"
#include <unordered_map>

//  "cde" => e
// "dcf" => f
// ...
// "cde" => d, e
// "abc" => a, b
int MakeAnagram(const std::string& a, const std::string& b) {
  std::unordered_map<char, int> char_count;
  for (const auto& c : a) {
    // operator[] adds / update and returns reference to the mapped value
    // No need to contains or count.
    ++char_count[c];
  }

  // We only have one map and the count can be negative
  // because the first string character does have this one.
  for (const auto& c : b) {
    --char_count[c];
  }

  int deletions = 0;
  for (const auto& [_, v] : char_count) {
    deletions += std::abs(v);  // In can be negative because we decrement
  }

  return deletions;
}