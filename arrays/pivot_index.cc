#include "arrays/pivot_index.h"
#include <numeric>

namespace algo {

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// total_sum = 28
// left_prefix_sum [0, 1, 8, 11, 17, ...]
// At index 3
// left_prefix = 11
// total_sum - left_prefix_sum - num[1] = 28 - 11 - 6 == 11
// The rest of array is equal
int32_t PivotIndex(const std::vector<int32_t>& nums) {
  int32_t total_sum = std::accumulate(nums.begin(), nums.end(), 0);
  int32_t left_sum = 0;

  for (int i = 0; i < nums.size(); ++i) {
    if (left_sum == total_sum - left_sum - nums[i]) {
      return i;
    }
    left_sum += nums[i];
  }

  return -1;
}
}  // namespace algo