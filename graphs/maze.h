// 18.1 Search maze classic DFS
//

#ifndef ALGO_CC_GRAPHS_MAZE_H_
#define ALGO_CC_GRAPHS_MAZE_H_
#include <cstdint>
#include <vector>

namespace algo {

enum class Color { kWhite, kBlack };

struct Coordinate {
  size_t x;  //  top left -> (col)
  size_t y;  //  top bottom  (row)

  bool operator==(const Coordinate& that) const {
    return x == that.x && y == that.y;
  }
};

std::vector<Coordinate> SearchMaze(const Coordinate& s, const Coordinate& e,
                                   std::vector<std::vector<Color>> maze);

}  // namespace algo

#endif  // ALGO_CC_GRAPHS_MAZE_H_
