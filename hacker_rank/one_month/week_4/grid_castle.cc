#include "hacker_rank/one_month/week_4/grid_castle.h"
#include <queue>

int MinimumMoves(std::vector<std::string> grid, int start_x, int start_y,
                 int goal_x, int goal_y) {
  static constexpr char kBlocked = 'X';
  const int m = grid.size();
  const int n = grid[0].size();

  struct Coordinate {
    Coordinate(int x, int y) : x(x), y(y) {}
    int x;
    int y;
  };
  std::string s;

  // Alternative to use Coordinate in a hashset is to provide equality operator
  // and a separate struct with a call operator.
  // or it can be
  // std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
  auto visited = std::vector<std::deque<bool>>(m, std::deque<bool>(n, false));

  int moves = 0;
  constexpr int kShift[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  std::queue<Coordinate> q;
  visited[start_y][start_x] = true;
  q.emplace(Coordinate(start_x, start_y));
  while (!q.empty()) {
    ++moves;
    auto curr = q.front();
    q.pop();
    for (const auto& [dy, dx] : kShift) {
      const int new_y = curr.y + dy;
      const int new_x = curr.x + dx;
      if (new_y >= 0 && new_y < m && new_x >= 0 && new_x < n &&
          grid[new_y][new_x] != kBlocked && !visited[new_y][new_x]) {
        if (new_y == goal_y && new_x == goal_x) return moves;
        visited[new_y][new_x] = true;
        q.emplace(Coordinate(new_x, new_y));
      }
    }
  }

  return -1;
}