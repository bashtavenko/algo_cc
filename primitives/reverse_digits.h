#ifndef ALGO_CC_PRIMITIVES_REVERSE_DIGITS_H_
#define ALGO_CC_PRIMITIVES_REVERSE_DIGITS_H_

#include <cstdint>

namespace algo {

// Mod 10 division to reverse
// 1132 => 2311
// 1132 % 10 = 2   0 * 10 + 2 = 2
// 113 % 10 = 3    2 * 10 + 3 = 23
// 11 % 10 = 1     23 * 10 + 1 = 231
// 1 % 10 = 1      231 * 10 + 1 = 2311
int64_t Reverse (int32_t x);

} // namespace algo

#endif //ALGO_CC_PRIMITIVES_REVERSE_DIGITS_H_
