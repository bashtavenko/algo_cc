// Given a sorted vector, return sorted squared vector.
// [1, 2, 3] => [1, 4, 9]
// [-2 0 1 3] => [0, 1, 4, 9]
#ifndef ALGO_CC_ARRAYS_SQUARE_SAME_ORDER_H_
#define ALGO_CC_ARRAYS_SQUARE_SAME_ORDER_H_
#include <cstdint>
#include <vector>

namespace algo {

std::vector<int32_t> SquareIt(const std::vector<int32_t>& nums);

}

#endif  // ALGO_CC_ARRAYS_SQUARE_SAME_ORDER_H_
