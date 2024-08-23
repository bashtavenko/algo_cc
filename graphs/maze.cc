#include "graphs/maze.h"
#include <vector>

namespace algo {

bool IsReachable(const std::vector<std::vector<Color>>& maze,
                 const Coordinate& cur) {
  return 0 <= cur.x && cur.x < maze.size() && 0 <= cur.y &&
         cur.y < maze[cur.x].size() && maze[cur.y][cur.x] == Color::kWhite;
}

bool RunDFS(const Coordinate& cur, const Coordinate& e,
            std::vector<std::vector<Color>>* p, std::vector<Coordinate>* path) {
  auto& maze = *p;
  if (!IsReachable(maze, cur)) return false;

  path->emplace_back(cur);
  maze[cur.y][cur.x] = Color::kBlack;  // Marked
  if (cur == e) return true;

  // (y, x)
  static constexpr int8_t kShift[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (auto& [y, x] : kShift) {
    if (RunDFS({cur.x + x, cur.y + y}, e, p, path)) return true;
  }

  // Could not find a path, back it off.
  path->pop_back();
  return false;
}

std::vector<Coordinate> SearchMaze(const Coordinate& s, const Coordinate& e,
                                   std::vector<std::vector<Color>> maze) {
  std::vector<Coordinate> path;
  if (!RunDFS(s, e, &maze, &path)) return {};
  return path;
}

}  // namespace algo