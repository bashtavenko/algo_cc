// We have dynamic array which contains queries and the size of output vector n.
// Each queries contain 3 integers.
// last_answer = 0
// Query 1
//   idx = ((x ^ last_answer) % n
//   Append y to arr[idx]
// Query 2
//  idx = ((x ^ last_answer) % n
//   Assign the value arr[idx][y % size(arr[idx]) to last answer
// Return the result of each type 2 query in the order it was presented.
// Example: n = 2 (there should be size of 2)
// 1 0 5
// 1 1 7
// 1 0 3
// 2 1 0
// 2 1 1
// Result: [7, 3]
// This is an extremely and boring problem.

#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_DYNAMIC_ARRAY_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_DYNAMIC_ARRAY_H_
#include <vector>

std::vector<int> DynamicArray(int n, std::vector<std::vector<int>> queries);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_DYNAMIC_ARRAY_H_
