//  A string is said to be a special string if either of two conditions is met:
//
// All characters are the same, e.g. aaa.
// All characters except the middle one are the same, e.g. aadaa.
// A special substring is any substring of a string which meets one of those
// criteria. Given a string, determine how many special substrings can be formed
// from it.
// This is a very confusing problem with confusing solution.
#ifndef ALGO_CC_HACKER_RANK_STRINGS_SUBSTR_COUNT_H_
#define ALGO_CC_HACKER_RANK_STRINGS_SUBSTR_COUNT_H_

#include <string>

long SubstrCount(const std::string& s);

#endif  // ALGO_CC_HACKER_RANK_STRINGS_SUBSTR_COUNT_H_
