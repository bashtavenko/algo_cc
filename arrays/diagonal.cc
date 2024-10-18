#include "arrays/diagonal.h"
#include <cstdint>
#include <vector>

namespace algo {

std::vector<int32_t> RunDiagonally(
    const std::vector<std::vector<int32_t>>& data) {
  std::vector<int32_t> result;
  size_t m = data.size();     // Number of rows
  size_t n = data[0].size();  // Number of columns

  auto run_diagonal = [&](size_t row, size_t col) {
    while (row < m && col < n) {
      result.push_back(data[row][col]);
      if (col == 0) break;  // Prevent col from under-flowing
      --col;
      ++row;
    }
  };

  // Top row, including main diagonal
  for (size_t col = 0; col < n; ++col) {
    run_diagonal(0, col);
  }
  // Right column, excluding main diagonal
  for (size_t row = 1; row < m; ++row) {
    run_diagonal(row, n - 1);
  }
  return result;
}

}  // namespace algo