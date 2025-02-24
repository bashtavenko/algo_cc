#include "arrays/longest_binary_subarray.h"

namespace algo {

// [1,1,0,1]
// [0, 1, 1, 1, 0, 1, 1, 0, 1]
size_t LongestBinarySubarray(const std::vector<int32_t>& nums) {
  size_t window_start = 0;
  size_t longest_size = 0;
  size_t delete_count = 0;

  for (size_t window_end = 0; window_end < nums.size(); ++window_end) {
    if (nums[window_end] == 0) {
      ++delete_count;
    }

    // Shrink the window if more than one 0 is encountered
    while (delete_count > 1) {
      if (nums[window_start] == 0) {
        --delete_count;
      }
      ++window_start;
    }

    longest_size = std::max(longest_size, window_end - window_start);
  }

  return longest_size;
}

}  // namespace algo
