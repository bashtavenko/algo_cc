// You are given a square grid with some cells open (.) and some blocked (X).
// Your playing piece can move along any row or column until it reaches the edge
// of the grid or a blocked cell. Given a grid, a start and a goal, determine
// the minimum number of moves to get to the goal.
//

#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_GRID_CASTLE_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_GRID_CASTLE_H_
#include <string>
#include <vector>

int MinimumMoves(std::vector<std::string> grid, int start_x, int start_y,
                 int goal_x, int goal_y);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_GRID_CASTLE_H_
