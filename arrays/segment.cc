#include "arrays/segment.h"
#include <cstdint>
#include <vector>

namespace algo {

// 3, 1, 1, 2, 1, 1
Segment GetLargestWithBudget(const std::vector<int32_t>& a, int32_t budget) {
  Segment result(0, 0);
  int32_t current_sum = 0;
  int32_t best_length = 0;
  int32_t current_length = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    current_sum += a[i];
    while (current_sum > budget) {
      current_sum -= a[result.lo++];
    }
    result.hi = i;
    current_length = result.hi - result.lo;
    if (best_length < current_length) {
      best_length = current_length;
    }
  }
  return result;
}

}  // namespace algo