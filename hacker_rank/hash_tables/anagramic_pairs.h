// Find the number of unordered anagram pairs of substrings of a string.
// Two strings are anagrams of each other if the letters of one string can be
// rearranged to form the other string. Given a string, find the number of pairs
// of substrings of the string that are anagrams of each other.
//
// "mom" => {[m, m], [mo, om]}
// "abba" => {[a,a], [ab, ba], [b, b], [abb, bba]}
// "abcd" => {}
// "ifailuhkqq" => {[i, i], [q, q], [ifa, fai]
// "kkkk" {[k, k], [k, k], [

#ifndef ALGO_CC_HACKER_RANK_HACH_TABLES_ANAGRAMIC_PAIRS_H_
#define ALGO_CC_HACKER_RANK_HACH_TABLES_ANAGRAMIC_PAIRS_H_
#include <string>

int FindAnagramPairs(const std::string& s);

#endif  // ALGO_CC_HACKER_RANK_HACH_TABLES_ANAGRAMIC_PAIRS_H_
