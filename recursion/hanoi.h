// 15.1 Tower of hanoi
#ifndef ALGO_CC_RECURSION_HANOI_H_
#define ALGO_CC_RECURSION_HANOI_H_
#include <cstdint>
#include <vector>

namespace algo {

inline constexpr size_t kNumPegs = 3;

std::vector<std::vector<size_t>> ComputeTowerOfHanoi(size_t num_rings);

}  // namespace algo

#endif  // ALGO_CC_RECURSION_HANOI_H_
