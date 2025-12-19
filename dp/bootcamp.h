// Dynamic programming
//
// Basic bits
#ifndef ALGO_CC_DP_BOOTCAMP_H_
#define ALGO_CC_DP_BOOTCAMP_H_
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace algo {

int32_t FibonacciBasic(int32_t n);
int32_t FibonacciCached(int32_t n, std::unordered_map<int32_t, int32_t>* m);
int32_t FibonacciIterative(int32_t n);

// [904, 40, 523, 12, -335, -385, -124, 481, -31]
// Starts at index 0 up to index 3
// There are two ways to do this:
// 1. Cormen - Maximum subarray divide and conquer. Quite a mess. We need a
// cross-sum.
// 2. DP, which is
//    a) accumulate running sum
//    b) compute a min sum and max sum
//    c) return a max sum.
//    Why min sum? Because we can subtract from a running sum to get a max sum.
int32_t FindMaximumSubarray(const std::vector<int32_t>& data);

}  // namespace algo

#endif  // ALGO_CC_DP_BOOTCAMP_H_
