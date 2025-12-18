#include "graphs/flip_color.h"
#include <cstdint>
#include <queue>
#include <vector>

namespace algo {

struct Coordinate {
  size_t x;  // Columns
  size_t y;  // Rows
};

// Classic BFS
void FlipColorBFS(int32_t x, int32_t y, std::vector<std::vector<bool>>& data) {
  // (y, x)
  static constexpr int8_t kShift[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  const bool color = data[y][x];
  std::queue<Coordinate> q;
  data[y][x] = !color;
  q.emplace(Coordinate(x, y));
  while (!q.empty()) {
    Coordinate curr = q.front();
    q.pop();
    for (auto& [dy, dx] : kShift) {
      // These are int32_t not size_t because the values can
      // become negative.
      const int32_t next_y = curr.y + dy;
      const int32_t next_x = curr.x + dx;
      if (next_y >= 0 && static_cast<size_t>(next_y) < data.size() &&
          next_x >= 0 && static_cast<size_t>(next_x) < data[dy].size() &&
          data[next_y][next_x] == color) {
        // Flips the color
        data[next_y][next_x] = !color;
        q.emplace(Coordinate(next_x, next_y));
      }
    }
  }
}

void FlipColorDFS(int32_t x, int32_t y, std::vector<std::vector<bool>>& data) {
  static constexpr int8_t kShift[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  const bool color = data[y][x];
  data[y][x] = !color;
  for (auto& [dy, dx] : kShift) {
    const int32_t next_y = y + dy;
    const int32_t next_x = x + dx;
    if (next_y >= 0 && static_cast<size_t>(next_y) < data.size() &&
        next_x >= 0 && static_cast<size_t>(next_x) < data[y].size() &&
        data[next_y][next_x] == color) {
      FlipColorDFS(next_x, next_y, data);
    }
  }
}

}  // namespace algo