// Find the shortest path to the given object through BFS.
#ifndef ALGO_CC_GRAPHS_SHORTEST_PATH_H_
#define ALGO_CC_GRAPHS_SHORTEST_PATH_H_
#include <cstdint>
#include <ostream>
#include <vector>

namespace algo {
enum class CellType { kOpen, kBlocked, kObject };

struct Coordinate {
  int32_t x;
  int32_t y;
  Coordinate(int x, int y) : x(x), y(y) {};
};

int32_t ShortestPath(std::vector<std::vector<CellType>>& grid);

}  // namespace algo

#endif  // ALGO_CC_GRAPHS_SHORTEST_PATH_H_
