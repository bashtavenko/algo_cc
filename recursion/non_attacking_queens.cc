#include "recursion/non_attacking_queens.h"
#include <memory>
#include "functional"

namespace algo {

std::vector<std::vector<int32_t>> FindQueensPosition(int32_t n) {
  std::vector<std::vector<int32_t>> result;
  auto board = std::vector<std::vector<int32_t>>(n, std::vector<int32_t>(n));

  // Test if newly placed queens will conflict any earlier queens placed before.
  auto is_valid = [&](const std::vector<int32_t>& col_placement) {
    const size_t row_id = col_placement.size() - 1;
    for (size_t row = 0; row < row_id; ++row) {
      const int32_t diff = std::abs(col_placement[row] - col_placement[row_id]);
      if (diff == 0 || diff == row_id) {
        // A column or diagonal is violated
        return false;
      }
    }
    return true;
  };

  std::function<void(size_t, std::vector<int32_t>*)> solve =
      [&](size_t row, std::vector<int32_t>* col_placement) {
        if (row == n) {
          // All queens are legally placed
          result.emplace_back(*col_placement);
        } else {
          for (size_t col = 0; col < n; ++col) {
            col_placement->emplace_back(col);
            if (is_valid(*col_placement)) {
              solve(row + 1, col_placement);
            }
            col_placement->pop_back();  // Ignore the last placement
          }
        }
      };

  solve(0, std::make_unique<std::vector<int32_t>>().get());
  return result;
}

}  // namespace algo