// Given a string of a lowercase letters determine the index of a character that
// can be removed to make a string a palindrome.
//
// "bcbc" could be 0 or 3

#ifndef ALGO_CC_HACKER_RANK_STRINGS_PALIDROME_INDEX_H_
#define ALGO_CC_HACKER_RANK_STRINGS_PALIDROME_INDEX_H_

#include <cstdint>
#include "absl/strings/string_view.h"

namespace algo {

int32_t PalidromeIndex(absl::string_view s);

}  // namespace algo

#endif  // ALGO_CC_HACKER_RANK_STRINGS_PALIDROME_INDEX_H_
