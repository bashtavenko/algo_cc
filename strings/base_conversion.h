// 6.2 Base conversion
#ifndef ALGO_CC_STRINGS_BASE_CONVERSION_H_
#define ALGO_CC_STRINGS_BASE_CONVERSION_H_
#include <cstdint>
#include <string>

namespace algo {

// Converts num_as_string in base b1 to another base b2 and returns string.
std::string ConvertBase(std::string const& num_as_string, uint16_t b1,
                        uint16_t b2);

}  // namespace algo

#endif  // ALGO_CC_STRINGS_BASE_CONVERSION_H_
