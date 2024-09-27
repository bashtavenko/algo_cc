#include "arrays/diagonal.h"
#include <cstdint>
#include <functional>
#include <vector>

namespace algo {

std::vector<int32_t> RunDiagonally(
    const std::vector<std::vector<int32_t>>& data) {
  std::vector<int32_t> result;

  auto run_diagonal = [&](size_t x, size_t y) {
    int32_t new_x = x;
    int32_t new_y = y;
    while (new_x >= 0 && new_x <= static_cast<int32_t>(data[0].size()) - 1 &&
           new_y >= 0 && new_y <= static_cast<int32_t>(data.size()) - 1) {
      result.push_back(data[new_y][new_x]);
      --new_x;
      ++new_y;
    }
  };

  // Top row, including main diagonal
  for (size_t x = 0; x < data[0].size(); ++x) {
    run_diagonal(x, 0);
  }
  // Right column, excluding main diagonal
  for (size_t y = 1; y < data.size(); ++y) {
    run_diagonal(data[0].size() - 1, y);
  }
  return result;
}

}  // namespace algo