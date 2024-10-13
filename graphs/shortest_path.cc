#include "graphs/shortest_path.h"
#include <limits>
#include <queue>
#include <vector>

namespace algo {

int32_t ShortestPath(std::vector<std::vector<CellType>>& grid) {
  int32_t m = grid.size();
  int32_t n = grid[0].size();
  using enum CellType;

  // Find starting position on each sides
  auto starting_pos = [&]() {
    std::vector<Coordinate> result;

    // Top row, y = 0
    for (int32_t x = 0; x < n; ++x) {
      if (grid[0][x] == kOpen) {
        result.emplace_back(Coordinate(x, 0));
      }
    }
    // Bottom row, y = m - 1
    for (int32_t x = 0; x < n; ++x) {
      if (grid[m - 1][x] == kOpen) {
        result.emplace_back(Coordinate(x, m - 1));
      }
    }
    // Left column, x = 0, 0 < y < m - 1
    for (int32_t y = 0; y < m - 1; ++y) {
      if (grid[y][0] == kOpen) {
        result.emplace_back(Coordinate(0, y));
      }
    }
    // Right column, x = n - 1, 0 < y < m - 1
    for (int32_t y = 0; y < m - 1; ++y) {
      if (grid[y][n - 1] == kOpen) {
        result.emplace_back(Coordinate(n - 1, y));
      }
    }

    return result;
  };

  // Runs the shortest path. Returns -1 if kObject was not found
  auto run_bfs = [&](const Coordinate& s) {
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    std::queue<Coordinate> q;
    int32_t moves = 0;
    static constexpr int32_t kShift[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    visited[s.y][s.x] = true;
    q.emplace(s);
    while (!q.empty()) {
      ++moves;
      Coordinate curr = q.front();
      q.pop();
      for (auto& [y, x] : kShift) {
        const int32_t next_y = curr.y + y;
        const int32_t next_x = curr.x + x;
        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m &&
            grid[next_y][next_x] != kBlocked && !visited[next_y][next_x]) {
          if (grid[next_y][next_x] == kObject) return moves;
          visited[next_y][next_x] = true;
          q.emplace(Coordinate(next_x, next_y));
        }
      }
    }
    return -1;
  };

  int32_t shortest_path = std::numeric_limits<int32_t>::max();
  for (const auto& start : starting_pos()) {
    int32_t current_cost = run_bfs(start);
    if (current_cost == -1) continue;
    shortest_path = std::min(shortest_path, current_cost);
  }
  return shortest_path;
}

}  // namespace algo