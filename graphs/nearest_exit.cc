#include "graphs/nearest_exit.h"
#include <numeric>
#include <queue>

namespace algo {

int32_t NearestExit(std::vector<std::vector<char>>& maze,
                    std::vector<int32_t>& entrance) {
  // Assume valid input
  const int32_t m = maze.size();     // rows
  const int32_t n = maze[0].size();  // col
  constexpr char8_t kVisited = '+';
  constexpr char8_t kOpened = '.';
  constexpr int32_t kOffsets[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int32_t start_row = entrance[0];
  int32_t start_col = entrance[1];

  std::queue<std::pair<int32_t, int32_t>> q;
  q.push({start_row, start_col});
  int steps = 0;

  while (!q.empty()) {
    int level_size = q.size();

    for (int i = 0; i < level_size; ++i) {
      // This must be value and not a reference!
      // Because after popping out of queue, the reference becomes dangling
      auto [row, col] = q.front();
      q.pop();

      if (!(row == start_row && col == start_col) &&
          (row == 0 || row == m - 1 || col == 0 || col == n - 1)) {
        return steps;
      }

      // Check each neighbour
      for (const auto& [dx, dy] : kOffsets) {
        int next_row = row + dy;
        int next_col = col + dx;

        // Boundary conditions
        if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n &&
            maze[next_row][next_col] == kOpened) {
          maze[next_row][next_col] = kVisited;
          q.push({next_row, next_col});
        }
      }
    }
    ++steps;
  }
  return -1;
}

}  // namespace algo
