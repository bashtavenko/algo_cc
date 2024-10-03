// 16.12 Find the longest non-decreasing subsequence.
// This means that elements should not be adjacent.
// Example:
// [0, 8, 4, 12, 2, 10, 6, 14, 1, 9]
// There are two:
// [0, 4, 10, 14] and [0, 2, 6, 9] both have length of 4
#ifndef ALGO_CC_DP_LONGEST_NONDECREASING_H_
#define ALGO_CC_DP_LONGEST_NONDECREASING_H_
#include <cstdint>
#include <vector>

namespace algo {

int LongestNonDecreasingSubsequenceLength(const std::vector<int32_t>& arr);

}  // namespace algo

#endif  // ALGO_CC_DP_LONGEST_NONDECREASING_H_
