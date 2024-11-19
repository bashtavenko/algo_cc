#include "sudoku/checker.h"
#include <cmath>
#include <queue>

namespace algo {

bool IsValid(const std::vector<std::vector<int32_t>>& grid) {
  const size_t n = grid[0].size();

  auto has_duplicate = [&](size_t start_row, size_t end_row, size_t start_col,
                           size_t end_col) {
    std::deque<bool> is_present(n + 1, false);
    for (size_t row = start_row; row < end_row; ++row) {
      for (size_t col = start_col; col < end_col; ++col) {
        if (grid[row][col] != 0 && is_present[grid[row][col]]) {
          return true;
        }
        is_present[grid[row][col]] = true;
      }
    }
    return false;
  };

  // Check row constraint
  for (size_t row = 0; row < n; ++row) {
    if (has_duplicate(row, row + 1, 0, n)) return false;
  }

  // Check column constraint
  for (size_t col = 0; col < n; ++col) {
    if (has_duplicate(0, n, col, col + 1)) return false;
  }

  // Check region constraint
  // In 9x9 grid there are 9 sub-grids
  const size_t region_size = std::sqrt(n);
  for (size_t region_row = 0; region_row < region_size; ++region_row) {
    for (size_t region_col = 0; region_col < region_size; ++region_col) {
      if (has_duplicate(
              region_size * region_row, region_size * (region_row + 1),
              region_size * region_col, region_size * (region_col + 1))) {
        return false;
      }
    }
  }
  return true;
}

}  // namespace algo
