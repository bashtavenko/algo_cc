// 16.3 Count the number of ways to traverse a 2D array.
//
// Start at top left corner and getting to the bottom right corner.  All moves
// rights and down.
//
// The number of ways to get to the bottom-right entry is the number of ways to
// get to the entry immediately above it, plus the number of ways to the entry
// immediately to its left. If somebody gave me those two numbers on the silver
// platter.
//
//(i, j) = (i - 1, j) + (i, j - 1)
//
//    0 1 1  1  1
//    1 2 3  4  5
//    1 3 6  10 15
//    1 4 10 20 35
//    1 5 15 35 70
//
// We just need to cache the results.
//
// 0 1 1
// 1 2 3
// 1 3 6
//
#ifndef ALGO_CC_DP_TRAVERSE_ARRAY_H_
#define ALGO_CC_DP_TRAVERSE_ARRAY_H_
#include <cstdint>

namespace algo {

int32_t NumberOfWays(int32_t row, int32_t col);

}  // namespace algo

#endif  // ALGO_CC_DP_TRAVERSE_ARRAY_H_
