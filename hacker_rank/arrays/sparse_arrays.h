// There are inputs and queries. Determine how many times the queries asked for
// input. strings  = ["ab", "ab", "abc"] queries = ["ab", "abc", "bc"] result =
// [2, 1, 0]

#ifndef ALGO_CC_HACKER_RANK_ARRAYS_SPARSE_ARRAYS_H_
#define ALGO_CC_HACKER_RANK_ARRAYS_SPARSE_ARRAYS_H_

#include <string>
#include <vector>

std::vector<int> MatchStrings(const std::vector<std::string>& items,
                              const std::vector<std::string> queries);

#endif  // ALGO_CC_HACKER_RANK_ARRAYS_SPARSE_ARRAYS_H_
