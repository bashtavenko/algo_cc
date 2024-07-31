#include "strings/base_conversion.h"
#include <cstdint>
#include <string>

namespace algo {

// This is value mod base recursively.
// This is the same idea of converting int to string
//  convert int to string - mod base and then divide.
// It can be done iteratively or recursively
std::string ConstructFromBase(u_int16_t num_as_int, u_int16_t base) {
  char c =
      static_cast<char>(num_as_int % base >= 10 ? 'A' + num_as_int % base - 10
                                                : '0' + num_as_int % base);
  return num_as_int == 0 ? "" : ConstructFromBase(num_as_int / base, base) + c;
}

std::string ConvertBase(std::string const& num_as_string, u_int16_t b1,
                        u_int16_t b2) {
  bool is_negative = num_as_string.front() == '-';
  // Reduction - each digit multiplies by b1 and added
  // This is the same idea of string to int, multiply by base
  u_int16_t num_as_int = 0;
  for (size_t i = (is_negative == true ? 1 : 0); i < num_as_string.size();
       ++i) {
    num_as_int *= b1;
    num_as_int += std::isdigit(num_as_string[i]) ? num_as_string[i] - '0'
                                                 : num_as_string[i] - 'A' + 10;
  }

  return (is_negative ? "-" : "") +
         (num_as_int == 0 ? "0" : ConstructFromBase(num_as_int, b2));
}
}  // namespace algo
