// Given  arrays  of different sizes, find the number of distinct triplets (p,
// q, r) where p is an element of corresponding array (a, b, c) satisfying
// condition p <= q and q >= r. For example, a = [3, 5, 7], b = [3, 6], c = [4,
// 6, 9] there are (3,6,4), (3,6,6), (5,6,4), (5,6,6)

#ifndef ALGO_CC_HACKER_RANK_SEARCH_TRIPLE_SUM_H_
#define ALGO_CC_HACKER_RANK_SEARCH_TRIPLE_SUM_H_
#include <vector>

// This passes all unit tests but exceeds on time limit
// Probably don't need to loop all arrays, just the pointers.
long Triplets(const std::vector<int>& a, const std::vector<int>& b,
              const std::vector<int>& c);

#endif  // ALGO_CC_HACKER_RANK_SEARCH_TRIPLE_SUM_H_
