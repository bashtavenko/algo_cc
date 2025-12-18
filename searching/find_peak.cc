#include "searching/find_peak.h"

namespace algo {

// [1,2,3,1]
size_t FindPeak(const std::vector<int32_t>& nums) {
  size_t lo = 0;
  size_t hi = nums.size() - 1;  // Reason for -1 is we want mid + 1

  while (lo < hi) {  // Don't want lo <= hi because it can hang.
    size_t mid = lo + (hi - lo) / 2;
    if (nums[mid] < nums[mid + 1]) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  return lo;
}

}  // namespace algo