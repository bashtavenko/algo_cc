// 12.1 Test for palindrome permutations.
// Check if characters of string can be permuted to form a palindrome.
//
// Palindrome reads the same from both ends 'level', 'rotator'.
//
//'edified' -> 'deified' permuted, and now it is palindrome
// Which means we don't need to try every permutation.
// What number of character counts are needed for palindrome?
//'aba' a:2 b:1  odd
//'abcba' a:2, b:2, c:1 odd
//'abccba' a:2, b:2, c:2 even
//'aabbcbbaa' a: 4, b: 4, c: 1 odd
#ifndef ALGO_CC_HASH_TABLES_PALIDROM_H_
#define ALGO_CC_HASH_TABLES_PALIDROM_H_
#include "absl/strings/string_view.h"

namespace algo {

bool CanFormPalidrome(absl::string_view s);

}  // namespace algo

#endif  // ALGO_CC_HASH_TABLES_PALIDROM_H_
