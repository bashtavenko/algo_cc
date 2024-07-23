#include "arrays/spiral.h"
#include <vector>

namespace algo {

std::vector<int32_t> Compute(
    std::vector<std::vector<int32_t>> const& square_matrix) {
  std::vector<std::vector<int32_t>> data(square_matrix.begin(),
                                         square_matrix.end());
  std::vector<int32_t> result;
  // This is pretty cool.
  // We change direction when out of bounds or already visited.
  static constexpr int16_t kShift[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int dir = 0;   // 0 (east), 1(south), 2(west), 3(north)
  size_t y = 0;  // row
  size_t x = 0;  // col

  for (size_t i = 0; i < data.size() * data.size(); ++i) {
    result.emplace_back(data[y][x]);
    data[y][x] =
        0;  // Assume there is no value 0 in the array, kind of marking.
    int32_t next_y = y + kShift[dir][0];
    int32_t next_x = x + kShift[dir][1];

    if (next_y < 0 || next_y >= data.size() || next_x < 0 ||
        next_x >= data.size() || data[next_y][next_x] == 0) {
      // Changes direction if it out of bound OR it is "marked".
      dir = (dir + 1) % 4;
      next_y = y + kShift[dir][0];
      next_x = x + kShift[dir][1];
    }
    y = next_y;
    x = next_x;
  }
  return result;
}
}  // namespace algo
