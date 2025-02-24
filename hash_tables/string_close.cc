#include "hash_tables/string_close.h"
#include <unordered_map>
#include <unordered_set>

namespace algo {

// "abc", "bca"
// "cabbba", "abbccc"
bool CloseStrings(absl::string_view word1, absl::string_view word2) {
  if (word1.size() != word2.size()) return false;

  std::unordered_map<char8_t, int32_t> freq1;
  std::unordered_map<char8_t, int32_t> freq2;
  std::unordered_set<char8_t> chars1;
  std::unordered_set<char8_t> chars2;

  for (char c : word1) {
    ++freq1[c];
    chars1.insert(c);
  }
  for (char c : word2) {
    ++freq2[c];
    chars2.insert(c);
  }

  if (chars1 != chars2) return false;  // Character sets must match

  std::vector<int32_t> counts1;
  std::vector<int32_t> counts2;
  for (const auto& [_, v] : freq1) counts1.push_back(v);
  for (const auto& [_, v] : freq2) counts2.push_back(v);

  std::sort(counts1.begin(), counts1.end());
  std::sort(counts2.begin(), counts2.end());

  // The equality operator for std::vector compares both the size and the order
  // of elements. Two vectors are considered equal if and only if they have the
  // same number of elements and each corresponding element is equal.
  return counts1 == counts2;  // Frequencies must match (unordered)
}

}  // namespace algo