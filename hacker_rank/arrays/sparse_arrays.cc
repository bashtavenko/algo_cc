#include "hacker_rank/arrays/sparse_arrays.h"

// items  = ["ab", "ab", "abc"]
// queries = ["ab", "abc", "bc"]
// result = [2, 1, 0]
std::vector<int> MatchStrings(const std::vector<std::string>& items,
                              const std::vector<std::string> queries) {
  std::vector<int> result(queries.size(), 0);
  for (size_t i = 0; i < queries.size(); ++i) {
    const std::string query = queries[i];
    for (const std::string& item : items) {
      if (query == item) ++result[i];
    }
  }
  return result;
}