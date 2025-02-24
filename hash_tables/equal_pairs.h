// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri,
// cj) such that row ri and column cj are equal.
//
// A row and column pair is considered equal if they contain the same elements
// in the same order (i.e., an equal array).

// Example 1:
// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output: 1
// Explanation: There is 1 equal row and column pair:
//- (Row 2, Column 1): [2,7,7]
//
#ifndef ALGO_CC_HASH_TABLES_EQUAL_PAIRS_H_
#define ALGO_CC_HASH_TABLES_EQUAL_PAIRS_H_
#include <cstdint>
#include <vector>

namespace algo {

int32_t EqualPairs(const std::vector<std::vector<int32_t>>& grid);

}  // namespace algo

#endif  // ALGO_CC_HASH_TABLES_EQUAL_PAIRS_H_
