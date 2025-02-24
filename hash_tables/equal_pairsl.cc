#include <string>
#include "hash_tables/equal_pairs.h"
#include "unordered_map"

namespace algo {

//  {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}}}
int32_t EqualPairs(const std::vector<std::vector<int32_t>>& grid) {
  const int32_t n = grid.size();
  std::unordered_map<std::string, int32_t> row_map;  // key-frequency
  std::unordered_map<std::string, int32_t> col_map;  // key-frequency

  // Build frequency map for rows.
  for (int row = 0; row < n; ++row) {
    std::string key;
    for (int col = 0; col < n; ++col) {
      key += std::to_string(grid[row][col]) + ",";
    }
    ++row_map[key];
  }

  // Build frequency map for columns.
  for (int col = 0; col < n; ++col) {
    std::string key;
    for (int row = 0; row < n; ++row) {
      key += std::to_string(grid[row][col]) + ",";
    }
    ++col_map[key];
  }

  int32_t count = 0;
  // For each row pattern, if there's a matching column pattern,
  // multiply their frequencies. This comes into play if there are
  // duplicates.
  for (const auto& [key, freq] : row_map) {
    if (col_map.contains(key)) {
      count += freq * col_map[key];
    }
  }

  return count;
}

}  // namespace algo