#include "arrays/diagonal.h"
#include <cstdint>
#include <vector>

namespace algo {

void Run(size_t x, size_t y, const std::vector<std::vector<int32_t>>& data,
         std::vector<int32_t>* result) {
  std::vector<int32_t>& r = *result;

  int32_t new_x = x;
  int32_t new_y = y;
  while (new_x >= 0 && new_x <= static_cast<int32_t>(data[0].size()) - 1 &&
         new_y >= 0 && new_y <= static_cast<int32_t>(data.size()) - 1) {
    r.push_back(data[new_y][new_x]);
    --new_x;
    ++new_y;
  }
}

std::vector<int32_t> RunDiagonally(
    const std::vector<std::vector<int32_t>>& data) {
  std::vector<int32_t> result;
  // Top row, including main diagonal
  for (size_t x = 0; x < data[0].size(); ++x) {
    Run(x, 0, data, &result);
  }
  // Right column, excluding main diagonal
  for (size_t y = 1; y < data.size(); ++y) {
    Run(data[0].size() - 1, y, data, &result);
  }
  return result;
}

}  // namespace algo