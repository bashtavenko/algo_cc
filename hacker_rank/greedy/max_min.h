// You will be given a list of integers arr, and a single integer k. You must
// create an array of length k from elements of arr such that its unfairness is
// minimized. Call that array arr'
// Unfairness of an array is calculated as max(arr') - min(arr')
//
// Example
// arr = [1, 4, 7, 2] k = 2
// Pick any two elements, say arr' = [4, 7]
// Unfairness = max(4, 7) - min(4, 7) = 7 - 4 = 3
// Testing for all pairs, the solution [1, 2] provides minimum unfairness
// Example 1
// arr = [10, 100, 300, 200, 1000, 20, 30] k = 3
// max(10, 20, 30) - min(10, 20, 30) = 30 - 10 = 20

#ifndef ALGO_CC_HACKER_RANK_GREEDY_MAX_MIN_H_
#define ALGO_CC_HACKER_RANK_GREEDY_MAX_MIN_H_
#include <vector>

int MaxMin(int k, std::vector<int> arr);

#endif  // ALGO_CC_HACKER_RANK_GREEDY_MAX_MIN_H_
