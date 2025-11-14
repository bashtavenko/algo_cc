// Given an integer array nums and an integer k, return the kth largest element
// in the array.
//
// Note that it is the kth largest element in the sorted order, not the kth
// distinct element.
//
// Can you solve it without sorting?
//
// Example 1:
// Input: nums = [3,2,1,5,6,4], k = 2
//               [1,2,3,4,5,6], k = 2
// Output: 5
//
// Example 2:
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//               [1,2,2,3,3,4,5,5,6], k = 4
// Output: 4
#ifndef ALGO_CC_HEAPS_K_LARGEST_H_
#define ALGO_CC_HEAPS_K_LARGEST_H_

#include <cstdint>
#include <vector>

namespace algo {

int32_t FindKthLargest(const std::vector<int32_t>& nums, size_t k);

}  // namespace algo

#endif  // ALGO_CC_HEAPS_K_LARGEST_H_
