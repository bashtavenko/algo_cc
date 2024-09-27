// Given an array of integers, find the subset of non-adjacent elements with the
// maximum sum. Calculate the sum of that subset. It is possible that the
// maximum sum is 0, the case when all elements are negative.
// This is not classic of max sub-array, but subset of non-adjacent elements.
//
// Example
// -2, 1, 3, -4, 5
// Subset      Sum
//[-2, 3, 5]   6
//[-2, 3]      1
//[-2, -4]    -6
//[-2, 5]      3
//[1, -4]     -3
//[1, 5]       6
//[3, 5]       8

#ifndef ALGO_CC_HACKER_RANK_DP_MAX_SUBSET_SUM_H_
#define ALGO_CC_HACKER_RANK_DP_MAX_SUBSET_SUM_H_
#include <vector>

int MaxSubsetSum(const std::vector<int>& arr);

#endif  // ALGO_CC_HACKER_RANK_DP_MAX_SUBSET_SUM_H_
