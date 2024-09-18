// You are given an array you need to find number of tripets of indices (i, j,
// k) such that the elements at those indices are in geometric progression for a
// given common ratio r  and i < j < k
// Example [1, 4, 16, 64] r = 4
// [1, 4, 16], [4, 16, 64]
//
// 1, 3, 9, 9, 27, 81, 3) r = 3
// [1, 3, 9], [1, 3, 9], [3, 9, 27], [3, 9, 27], [9, 27, 81], [9, 27, 81]
//
// Geometric progression
// 2, 6, 18, 54 with a ratio of 3.

#ifndef ALGO_CC_HACKER_RANK_HASH_TABLES_COUNT_TRIPLETS_H_
#define ALGO_CC_HACKER_RANK_HASH_TABLES_COUNT_TRIPLETS_H_
#include <vector>

long CountTriplets(std::vector<long> arr, long r);

#endif  // ALGO_CC_HACKER_RANK_HASH_TABLES_COUNT_TRIPLETS_H_
