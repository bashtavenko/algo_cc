// You are given an m x n matrix maze (0-indexed) with empty cells (represented
// as '.') and walls (represented as '+'). You are also given the entrance of
// the maze, where entrance = [entrancerow, entrancecol] denotes the row and
// column of the cell you are initially standing at.
//
// In one step, you can move one cell up, down, left, or right. You cannot step
// into a cell with a wall, and you cannot step outside the maze. Your goal is
// to find the nearest exit from the entrance. An exit is defined as an empty
// cell that is at the border of the maze. The entrance does not count as an
// exit.
//
// Return the number of steps in the shortest path from the entrance to the
// nearest exit, or -1 if no such path exists.
//
#ifndef ALGO_CC_GRAPHS_NEAREST_EXIT_H_
#define ALGO_CC_GRAPHS_NEAREST_EXIT_H_
#include <cstdint>
#include <vector>

namespace algo {

int32_t NearestExit(std::vector<std::vector<char>>& maze,
                    std::vector<int32_t>& entrance);

}  // namespace algo

#endif  // ALGO_CC_GRAPHS_NEAREST_EXIT_H_
