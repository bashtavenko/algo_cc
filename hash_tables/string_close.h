// Two strings are considered close if you can attain one from the other using
// the following operations:
//
// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
//
// Operation 2: Transform every occurrence of one existing character into
// another existing character, and do the same with the other character.
//
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into
// a's) You can use the operations on either string as many times as necessary.
//
// Given two strings, word1 and word2, return true if word1 and word2 are close,
// and false otherwise.
//
// Example 1:
// Input: word1 = "abc", word2 = "bca"
// Output: true
// Explanation: You can attain word2 from word1 in 2 operations.
// Apply Operation 1: "abc" -> "acb"
// Apply Operation 1: "acb" -> "bca"
//
// Example 2:
//
// Input: word1 = "a", word2 = "aa"
// Output: false
// Explanation: It is impossible to attain word2 from word1, or vice versa, in
// any number of operations.
//
// Example 3:
// Input: word1 = "cabbba", word2 = "abbccc"
// Output: true
// Explanation: You can attain word2 from word1 in 3 operations.
// Apply Operation 1: "cabbba" -> "caabbb"
// Apply Operation 2: "caabbb" -> "baaccc"
// Apply Operation 2: "baaccc" -> "abbccc"
// *****************
// Key ideas
// If two strings can be transformed into each other if:
//  1. The same unique character set
//      Example: "abc" and "bca" are fine, but "abc" and "def" are not
//  2. The same frequency histogram (unordered frequencies should match)
//      Example: "aabbcc" and "ccbbaa" are equivalent because they both contain
//      {2, 2, 2}

#ifndef ALGO_CC_HASH_TABLES_STRING_CLOSE_H_
#define ALGO_CC_HASH_TABLES_STRING_CLOSE_H_
#include "absl/strings/string_view.h"

namespace algo {

bool CloseStrings(absl::string_view word1, absl::string_view word2);

}  // namespace algo

#endif  // ALGO_CC_HASH_TABLES_STRING_CLOSE_H_
