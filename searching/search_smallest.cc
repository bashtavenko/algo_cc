#include "searching/search_smallest.h"
#include <cstdint>
#include <vector>

namespace algo {

size_t SearchSmallest(const std::vector<int32_t>& data) {
  size_t lo = 0;
  size_t hi = data.size() - 1;  // The only difference is -1
  size_t mid;
  while (lo < hi) {  // Don't want <=
    mid = lo + (hi - lo) / 2;
    // This is canonical binary search
    // if (target > data[mid]) lo = mid + 1
    // the only difference is that target -> data[mid]
    if (data[mid] > data[hi]) {
      lo = mid + 1;
    } else {
      // (data[mid] <= data[hi])
      hi = mid;
    }
  }
  // Ends when lo == high
  return lo;
}

}  // namespace algo
