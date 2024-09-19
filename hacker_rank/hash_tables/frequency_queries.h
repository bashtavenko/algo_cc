// You are given  q queries. Each query is of the form two integers described
// below:
// 1 1 (set)
// 2 2 (delete)
// 3 2 (query) check if any integer is present with frequency x
// Operation   Array   Output
//  (1,1)      [1]
//  (2,2)      [1]
//  (3,2)                  0
//  (1,1)      [1,1]
//  (1,1)      [1,1,1]
//  (2,1)      [1,1]
//  (3,2)                   1
// Example 1:
// 1 5
// 1 6
// 3 2
// Answer is 0 because there is no 2 of any 5's or 6's [5, 6]
// Example 2:
// 1 5  [5]
// 1 6  [5, 6]
// 1 10 [5, 6, 10]
// 1 10 [5, 6, 10, 10]
// 1 6  [5, 6, 10, 10, 6]
// 2 5  [6, 10, 10, 6]
// 3 2
// Answer is 1 because there are two 6's and 10's [6, 10, 10, 6]
// Example 3:
// 3 4
// 2 1003
// 1 16 [16]
// 3 1
// Answer: 1 [16]

#ifndef ALGO_CC_HACKER_RANK_HASH_TABLES_FREQUENCY_QUERIES_H_
#define ALGO_CC_HACKER_RANK_HASH_TABLES_FREQUENCY_QUERIES_H_
#include <vector>

std::vector<int> FreqQuery(const std::vector<std::vector<int>>& queries);

#endif  // ALGO_CC_HACKER_RANK_HASH_TABLES_FREQUENCY_QUERIES_H_
