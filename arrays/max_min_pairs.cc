#include "arrays/max_min_pairs.h"
#include <algorithm>

namespace algo {

int32_t MinMaxPairs(std::vector<int32_t>& nums) {
  std::ranges::sort(nums);
  int32_t max_sum = 0;
  for (size_t i = 0; i < nums.size(); i += 2) {
    // Min is not needed because after sorting the first value is smaller
    max_sum += nums[i];
  }
  return max_sum;
}

}  // namespace algo
