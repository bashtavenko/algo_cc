// Print matrix diagonally
//
// 1 2 3
// 4 5 6
// 7 8 9
//
// 1, 2, 4, 3, 5, 7, 6, 8, 9
//
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
//
//
// Algorithm
// Run in two passes (3 x 3 matrix example);
// Pass 1 - top row (1, 2, 3)
// Pass 2 - right column below diagonal
// meaning 6, 9
// In both cases the idea of decrement x and increment y.

#ifndef ALGO_CC_ARRAYS_DIAGONAL_H_
#define ALGO_CC_ARRAYS_DIAGONAL_H_

#include <cstdint>
#include <vector>

namespace algo {

std::vector<int32_t> RunDiagonally(
    const std::vector<std::vector<int32_t>>& data);

}  // namespace algo

#endif  // ALGO_CC_ARRAYS_DIAGONAL_H_
