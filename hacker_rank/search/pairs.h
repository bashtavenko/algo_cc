// Given an array of integers and a target value, determine the number of pairs
// of array elements that have a difference equal to the target value.
// Example
// [1, 2, 3, 4], k = 1
// 2 - 1 = 1; 3 - 2 = 1; 4 - 3 = 1; Return 3;
// Example 1
// [1, 5, 3, 4, 2], k = 2
// There are 3 pairs of integers in the set with a difference of 2: [5,3], [4,2]
// and [3,1].
#ifndef ALGO_CC_HACKER_RANK_SEARCH_PAIRS_H_
#define ALGO_CC_HACKER_RANK_SEARCH_PAIRS_H_
#include <vector>

int Pairs(int k, std::vector<int> arr);

#endif  // ALGO_CC_HACKER_RANK_SEARCH_PAIRS_H_
