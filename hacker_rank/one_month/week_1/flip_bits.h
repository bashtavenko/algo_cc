// You will be given a list of 32-bit unsigned integers.
// Flip all the bits (1->0 and 0->1) and return the result
// as an unsigned integer.
#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_1_FLIP_BITS_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_1_FLIP_BITS_H_
#include <cstdint>

// Ensures masking to return 0 for signing bit
// ~ is bitwise NOT
int32_t FlipBits(int32_t x) { return ~x & 0xFFFFFFFF; }

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_1_FLIP_BITS_H_
