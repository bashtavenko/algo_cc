// A string is a child of another string if it can be formed by
// deleting 0 or more characters from the other string. Given two strings of
// equal length, what's the longest string that can be constructed such that it
// is a child of both.
// Return the length of the longest string which is a common child
// "ABCD", "ABDC" => {"ABC", "ABD"} 3
// "AA", "BB" => {} 0
//
#ifndef ALGO_CC_HACKER_RANK_STRINGS_STRING_CHILD_H_
#define ALGO_CC_HACKER_RANK_STRINGS_STRING_CHILD_H_

#include <string>
#include <vector>

int CommonChildDP(const std::string& s1, const std::string& s2);

// These two work as a brute force
int CommonChild(const std::string& s1, const std::string& s2);
std::vector<std::string> NChooseK(const std::string& s, int k);

#endif  // ALGO_CC_HACKER_RANK_STRINGS_STRING_CHILD_H_
