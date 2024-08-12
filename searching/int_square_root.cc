#include "searching/int_square_root.h"
#include <cstdint>

namespace algo {

int32_t SquareRoot(int32_t k) {
  int32_t lo = 0;
  int32_t hi = k;
  int32_t mid = 0;
  while (lo <= hi) {  // Need == because 16 => 4
    mid = lo + (hi - lo) / 2;
    // Same as searching for smallest - use mid instead of target
    auto mid_square = mid * mid;
    if (k < mid_square) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  return lo - 1;
}

}  // namespace algo
