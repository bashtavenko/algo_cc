#include "hacker_rank/hach_tables/two_strings.h"
#include <string>
#include <unordered_set>

bool TwoStrings(const std::string& s1, const std::string& s2) {
  std::unordered_set<char> s1_chars;
  for (const char& c : s1) s1_chars.insert(c);

  std::unordered_set<char> s2_chars;
  for (const char& c : s2) s2_chars.insert(c);

  std::unordered_set<char> common;
  for (const char& c : s1_chars) {
    // In C++ 20+
    //  if (s2_chars.contains(c)) common.insert(c);
    if (auto it = s2_chars.find(c); it != s2_chars.end()) {
      common.insert(c);
    }
  }

  return !common.empty();
}
