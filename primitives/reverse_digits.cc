#include "reverse_digits.h"
#include <cstdlib>

namespace algo {

int64_t Reverse(int32_t x) {
  int64_t result = 0;
  int64_t x_remaining = std::abs(x);
  while (x_remaining) {
    result = result * 10 + x_remaining % 10;
    x_remaining /= 10;
  }

  return x < 0 ? -result : result;
}

}  // namespace algo
