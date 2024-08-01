#ifndef ALGO_CC_ARRAYS_SPIRAL_H_
#define ALGO_CC_ARRAYS_SPIRAL_H_
#include <cstdint>
#include <vector>

namespace algo {

// 5.18 Compute spiral ordering of a matrix
std::vector<int32_t> Compute(
    const std::vector<std::vector<int32_t>>& square_matrix);
}  // namespace algo

#endif  // ALGO_CC_ARRAYS_SPIRAL_H_
