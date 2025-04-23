#ifndef ALGO_CC_PRIMITIVES_SATURATING_ADD_H_
#define ALGO_CC_PRIMITIVES_SATURATING_ADD_H_
#include <cstdint>

namespace algo {

// Normally, in C++ or C, when you add two int8_t numbers, they can overflow or
// underflow:
// int8_t a = 100;
// int8_t b = 40;
// int8_t c = a + b;  // c = -116 (oops, overflow!)
// Saturating add means:
// If the result would overflow, you cap it at the maximum (127 for int8_t).
// If the result would underflow, you cap it at the minimum (-128 for int8_t).
int8_t SaturatingAdd(int8_t a, int8_t b);

}  // namespace algo

#endif  // ALGO_CC_PRIMITIVES_SATURATING_ADD_H_
