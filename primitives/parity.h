#ifndef ALGO_CC_PRIMITIVES_PARITY_H_
#define ALGO_CC_PRIMITIVES_PARITY_H_

#include <cstdint>

namespace algo {

// 4.1 Compute parity
//
// If the numbers of ones are odd, return 1, otherwise return 0
// 1011 => 1
// 10001000 = > 0
// This is a brute force.
int16_t ParityBruteForce(uint32_t x);

// Drops lowest bit
int16_t ParityDropsLowest(uint32_t);

} // namespace algo

#endif //ALGO_CC_PRIMITIVES_PARITY_H_
