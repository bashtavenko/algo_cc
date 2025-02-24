// Given a binary array nums and an integer k, return the maximum number of
// consecutive 1's in the array if you can flip at most k 0's.
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
//                         x x x x x x
// Example 2
// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
//                   x x x x x x x x x x
// IF WE EXCEED `K` FLIPS, SHRINK THE WINDOW.
#ifndef ALGO_CC_ARRAYS_LONGEST_ONES_H_
#define ALGO_CC_ARRAYS_LONGEST_ONES_H_
#include <cstdint>
#include <vector>

namespace algo {

int32_t LongestOnes(const std::vector<int32_t>& nums, int32_t k);

}  // namespace algo

#endif  // ALGO_CC_ARRAYS_LONGEST_ONES_H_
