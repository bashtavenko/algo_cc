// 15.9 Sudoku solver
// 9x9 grid  with 3 x 3 sections
// Constraints:
//  No duplicates in rows
//  No duplicates in columns
//  All sections contain all numbers from 1 to 9
//
// Ideas:
//    Recursive solver with backtracking. Tries all numbers recursively and
//    backtracks if that number didn't work.  Check validity on add (row,
//    column, region)
#ifndef ALGO_CC_SUDOKU_SOLVER_H_
#define ALGO_CC_SUDOKU_SOLVER_H_

#include <cstdint>
#include <vector>

namespace algo {

// 9x9 grid  with 3 x 3 sections
// Constraints:
//  No duplicates in rows
//  No duplicates in columns
//  All sections contain all numbers from 1 to 9
//
// Recursive solver with backtracking. Tries all numbers recursively and
// backtracks if that number didn't work.  Check validity on add (row,
// column, region);
bool Solve(std::vector<std::vector<int32_t>>& grid);

}  // namespace algo

#endif  // ALGO_CC_SUDOKU_SOLVER_H_
