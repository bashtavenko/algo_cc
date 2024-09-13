// You are given an unordered array consisting of consecutive integers  [1, 2,
// 3, ..., n] without any duplicates. You are allowed to swap any two elements.
// Find the minimum number of swaps required to sort the array in ascending
// order.
//
// Example
// arr = [7, 1, 3, 2, 4, 5, 6]
// i   arr                         swap (indices)
// 0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
// 1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
// 2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
// 3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
// 4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
// 5   [1, 2, 3, 4, 5, 6, 7]
// It took 5 swaps
//
// It has CONSECUTIVE integers.

#ifndef ALGO_CC_HACKER_RANK_ARRAYS_MINIMUM_SWAP_H_
#define ALGO_CC_HACKER_RANK_ARRAYS_MINIMUM_SWAP_H_
#include <vector>

int MinimumSwap(std::vector<int>& arr);

#endif  // ALGO_CC_HACKER_RANK_ARRAYS_MINIMUM_SWAP_H_
