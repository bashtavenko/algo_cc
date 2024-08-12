#include "searching/first_occurrence.h"
#include <cstdint>
#include <vector>

namespace algo {

size_t SearchFirst(const std::vector<int32_t>& sorted, int32_t target) {
  size_t lo = 0;
  size_t hi = sorted.size();
  size_t result = 0;
  while (lo < hi) {
    size_t mid = lo + (hi - lo) / 2;
    if (target < sorted[mid]) {
      hi = mid - 1;
    } else if (target > sorted[mid]) {
      lo = mid + 1;
    } else {
      // We already found the first occurrence.
      result = mid;
      hi = mid - 1;  // Maybe this could be break;
    }
  }
  return result;
}

}  // namespace algo
