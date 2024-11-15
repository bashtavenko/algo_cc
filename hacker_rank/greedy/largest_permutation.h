// You are given an unordered array of unique integers incrementing from 1. You
// can swap any two elements a limited number of times. Determine the largest
// lexicographical value array that can be created by executing no more than the
// limited number of swaps.
//
// Example
// [2, 1, 3], k = 1
// With one swap the permutations are [1, 2, 3], [3, 1, 2], [2, 3, 1]
// The largest is [3, 1, 2]

#ifndef ALGO_CC_HACKER_RANK_GREEDY_LARGEST_PERMUTATION_H_
#define ALGO_CC_HACKER_RANK_GREEDY_LARGEST_PERMUTATION_H_
#include <vector>

std::vector<int> LargestPermutation(const std::vector<int>& a, size_t k);

#endif  // ALGO_CC_HACKER_RANK_GREEDY_LARGEST_PERMUTATION_H_
