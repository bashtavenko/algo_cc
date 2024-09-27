//  18.2 Flip color matrix classic with BFS and DFS
//  That means flipping color for this cell and neighbouring cells.
#ifndef ALGO_CC_GRAPHS_FLIP_COLOR_H_
#define ALGO_CC_GRAPHS_FLIP_COLOR_H_
#include <cstdint>
#include <vector>

namespace algo {

void FlipColorBFS(int32_t x, int32_t y, std::vector<std::vector<bool>>& data);
void FlipColorDFS(int32_t x, int32_t y, std::vector<std::vector<bool>>& data);

}  // namespace algo

#endif  // ALGO_CC_GRAPHS_FLIP_COLOR_H_
