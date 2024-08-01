#include "strings/strings_int.h"
#include <string>

namespace algo {
// This is std::to_string
std::string IntToString(int32_t x) {
  bool is_negative = (x < 0) ? true : false;

  // mod 10 and then divide by 10
  // 123
  // "3"
  // "2"
  // "1"
  // "321"
  // Adding string to the back is faster than in front and
  // then reverse
  std::string s;
  do {
    s += '0' + std::abs(x % 10);  // push_back
    x /= 10;
  } while (x);

  if (is_negative) s += '-';

  return {s.rbegin(), s.rend()};  // string reversal
}

int32_t StringToInt(const std::string& s) {
  // 10^2 x d2 + 10^1 + d1 ...
  int32_t result = 0;
  // Start from 0 for positive or 1 (skipping "-")
  for (size_t i = s.front() == '-' ? 1 : 0; i < s.size(); ++i) {
    const int32_t digit = s[i] - '0';
    result = result * 10 + digit;
  }
  return s[0] == '-' ? -result : result;
}

}  // namespace algo
