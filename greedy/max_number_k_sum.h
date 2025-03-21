// You are given an integer array nums and an integer k.
//
// In one operation, you can pick two numbers from the array whose sum equals k
// and remove them from the array.
//
// Return the maximum number of operations you can perform on the array.
// Input: nums = [1,2,3,4], k = 5
// Output: 2
// Explanation: Starting with nums = [1,2,3,4]:
//- Remove numbers 1 and 4, then nums = [2,3]
//- Remove numbers 2 and 3, then nums = []
// There are no more pairs that sum up to 5, hence a total of 2 operations.
//
// Input: nums = [3,1,3,4,3], k = 6
// Output: 1
// Explanation: Starting with nums = [3,1,3,4,3]:
// Remove the first two 3's, then nums = [1,4,3]
// There are no more pairs that sum up to 6, hence a total of 1 operation.

#ifndef ALGO_CC_GREEDY_MAX_NUMBER_K_SUM_H_
#define ALGO_CC_GREEDY_MAX_NUMBER_K_SUM_H_

#include <cstdint>
#include <vector>

namespace algo {

size_t MaxOperations(std::vector<int32_t>& nums, size_t k);

}  // namespace algo

#endif  // ALGO_CC_GREEDY_MAX_NUMBER_K_SUM_H_
