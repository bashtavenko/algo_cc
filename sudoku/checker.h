// 5.17 Sudoku checker

#ifndef ALGO_CC_SUDOKU_CHECKER_H_
#define ALGO_CC_SUDOKU_CHECKER_H_

#include <cstdint>
#include <vector>

namespace algo {

// Checks if partially assembled grid is valid
bool IsValid(const std::vector<std::vector<int32_t>>& grid);

}  // namespace algo

#endif  // ALGO_CC_SUDOKU_CHECKER_H_
