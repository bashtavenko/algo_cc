// 17.7 Compute the maximum water tapped.
//
//[1, 2, 1, 3, 4, 4, 5, 6, 2, 1, 3, 1, 3, 2, 1, 2, 4, 1]
// 4 - 16
// Meaning that "water" should be leveled. At 4 and 16 the value
// is the same of 4.
//
// Brute force is O(n^3), divide and conquer is O(n^2)
//
// This is similar to invariants such as two-sum and others.
// Work from both ends while (lo < hi)
// std::max(... std::min)
//"""
//

#ifndef ALGO_CC_GREEDY_MAX_WATER_H_
#define ALGO_CC_GREEDY_MAX_WATER_H_
#include <cstdint>
#include <vector>

namespace algo {

int32_t GetMaxTrappedWater(const std::vector<int32_t>& heights);

}  // namespace algo

#endif  // ALGO_CC_GREEDY_MAX_WATER_H_
