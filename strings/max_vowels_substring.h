// Given a string s and an integer k, return the maximum number of vowel letters
// in any substring of s with length k.
//
// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
#ifndef ALGO_CC_STRINGS_MAX_VOWELS_SUBSTRING_H_
#define ALGO_CC_STRINGS_MAX_VOWELS_SUBSTRING_H_
#include <cstdint>
#include <string>
#include "absl/strings/string_view.h"

namespace algo {

int32_t MaxVowels(absl::string_view s, int32_t k);

}  // namespace algo

#endif  // ALGO_CC_STRINGS_MAX_VOWELS_SUBSTRING_H_
