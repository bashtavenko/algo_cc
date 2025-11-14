#include "greedy/max_number_k_sum.h"
#include <algorithm>

namespace algo {

// Input: nums = [1,2,3,4], k = 5
// Output: 2
// [1, 3, 3, 3, 4], k = 6
// Output: 1
size_t MaxOperations(std::vector<int32_t>& nums, int32_t k) {
  // Assuming valid input

  std::sort(nums.begin(), nums.end());  // Default is ASC
  size_t result = 0;
  int32_t lo = 0;
  int32_t hi = nums.size() - 1;
  while (lo < hi) {
    if (nums[lo] + nums[hi] < k) {
      ++lo;  // add some more
    } else if (nums[lo] + nums[hi] > k) {
      --hi;  // overshoot
    } else {
      ++result;  // found
      ++lo;
      --hi;
    }
  }

  return result;
}

}  // namespace algo