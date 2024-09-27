#include "dp/traverse_array.h"
#include <cstdint>
#include <vector>

namespace algo {

int32_t Run(int32_t y, int32_t x, std::vector<std::vector<int32_t>>& ways) {
  if (y == 0 && x == 0) return 1;

  if (ways[y][x] == 0) {
    // We just initialized the array with 0. Now fill it.
    int32_t ways_top = y == 0 ? 0 : Run(y - 1, x, ways);
    int32_t ways_left = x == 0 ? 0 : Run(y, x - 1, ways);
    ways[y][x] = ways_top + ways_left;
  }

  return ways[y][x];
}

int32_t NumberOfWays(int32_t row, int32_t col) {
  std::vector<std::vector<int32_t>> ways(row, std::vector<int32_t>(col, 0));
  return Run(row - 1, col - 1, ways);
}

}  // namespace algo