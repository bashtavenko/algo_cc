#include "primitives/parity.h"

namespace algo {
int16_t ParityBruteForce(uint32_t x) {
  int16_t result = 0;
  while (x) {
    // XOR of two bits is equivalent of mod 2. We can compute it in one step.
    result ^= (x & 1);
    x >>= 1;
  }
  return result;
}

int16_t ParityDropsLowest(uint32_t x) {
  int16_t result = 0;
  while (x) {
    result ^= 1;  // Because we know the lowest set bit
    // Bit-fiddling trick:
    // x &(x - 1) equals x with its lowest set bit erased
    // x =     0110 (6)
    // x - 1 = 0101 (5)
    // x &.. = 0100
    x &= (x - 1);
  }
  return result;
}

}  // namespace algo
