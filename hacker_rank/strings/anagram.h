// A student is taking a cryptography class and has found anagrams to be very
// useful. Two strings are anagrams of each other if the first string's letters
// can be rearranged to form the second string. In other words, both strings
// must contain the same exact letters in the same exact frequency. For example,
// bacdc and dcbac are anagrams, but bacdc and dcbad are not.
//
// The student decides on an encryption scheme that involves two large strings.
// The encryption is dependent on the minimum number of character deletions
// required to make the two strings anagrams. Determine this number.
//
// Given two strings a and b that may or may not be of the same length,
// determine the minimum number of character deletions required to make and
// anagrams. Any characters can be deleted from either of the strings.

#ifndef ALGO_CC_HACKER_RANK_STRINGS_ANAGRAM_H_
#define ALGO_CC_HACKER_RANK_STRINGS_ANAGRAM_H_

#include <string>

int MakeAnagram(const std::string& a, const std::string& b);

#endif  // ALGO_CC_HACKER_RANK_STRINGS_ANAGRAM_H_
