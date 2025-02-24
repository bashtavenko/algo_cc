// Given an integer array nums, return true if there exists a triple of indices
// (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such
// indices exists, return false.
//
#ifndef ALGO_CC_ARRAYS_INCREASING_TRIPLETS_H_
#define ALGO_CC_ARRAYS_INCREASING_TRIPLETS_H_
#include <cstdint>
#include <vector>

namespace algo {

bool IncreasingTriplets(const std::vector<int32_t>& nums);

}  // namespace algo

#endif  // ALGO_CC_ARRAYS_INCREASING_TRIPLETS_H_
