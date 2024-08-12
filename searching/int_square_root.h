// 10.4 Returns the largest integer whose square is less than or equal the given
// number.
//
// Input: 16 => 4
// 300 => 17 since 17 ^ 2 = 289 and 18 ^2 = 324 > 300
// 21 => 4
// 25 => 5
#ifndef ALGO_CC_SEARCHING_INT_SQUARE_ROOT_H_
#define ALGO_CC_SEARCHING_INT_SQUARE_ROOT_H_

#include <cstdint>

namespace algo {

int32_t SquareRoot(int32_t k);

}  // namespace algo

#endif  // ALGO_CC_SEARCHING_INT_SQUARE_ROOT_H_
