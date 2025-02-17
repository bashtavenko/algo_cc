// 15.2 Generate non-attacking placements of n-Queens
// Non-attacking placement is one in which no two queens are in the same row,
// column, or diagonal.
//
#ifndef ALGO_CC_RECURSION_NON_ATTACKING_QUEENS_H_
#define ALGO_CC_RECURSION_NON_ATTACKING_QUEENS_H_
#include <cstdint>
#include <vector>

namespace algo {

std::vector<std::vector<int32_t>> FindQueensPosition(int32_t n);

}  // namespace algo

#endif  // ALGO_CC_RECURSION_NON_ATTACKING_QUEENS_H_
