//  Given a string, determine how many special substrings can be formed
//  from it. A substring has start and finish.
//
//
// 1. All characters are the same:
// "aa" => {a, a, aa}
//
// 2. All characters except the middle one are the same
//
#ifndef ALGO_CC_HACKER_RANK_STRINGS_SUBSTR_COUNT_H_
#define ALGO_CC_HACKER_RANK_STRINGS_SUBSTR_COUNT_H_

#include <string>

long SubstrCount(int n, const std::string& s);

#endif  // ALGO_CC_HACKER_RANK_STRINGS_SUBSTR_COUNT_H_
