#include "arrays/longest_ones.h"

namespace algo {

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
//                           x x x x x x
//
int32_t LongestOnes(const std::vector<int32_t>& nums, int32_t k) {
  size_t window_start = 0;
  size_t max_length = 0;
  int32_t flip_count = 0;

  for (size_t window_end = 0; window_end < nums.size(); ++window_end) {
    if (nums[window_end] == 0) {
      ++flip_count;
    }

    // If we exceed `k` flips, shrink the window.
    while (flip_count > k) {
      if (nums[window_start] == 0) {
        --flip_count;
      }
      ++window_start;
    }

    max_length = std::max(max_length, window_end - window_start + 1);
  }

  return max_length;
}

}  // namespace algo
