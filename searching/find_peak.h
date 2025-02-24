// Given a 0-indexed integer array nums, find a peak element, and return its
// index. If the array contains multiple peaks, return the index to any of the
// peaks.
//
// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is
// always considered to be strictly greater than a neighbor that is outside the
// array.
//
// You must write an algorithm that runs in O(log n) time.
#ifndef ALGO_CC_SEARCHING_FIND_PEAK_H_
#define ALGO_CC_SEARCHING_FIND_PEAK_H_
#include <cstdint>
#include <vector>

namespace algo {

size_t FindPeak(const std::vector<int32_t>& nums);

}  // namespace algo

#endif  // ALGO_CC_SEARCHING_FIND_PEAK_H_
