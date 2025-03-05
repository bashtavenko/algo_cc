#include "arrays/square_same_order.h"
#include <valarray>

namespace algo {

std::vector<int32_t> SquareIt(const std::vector<int32_t>& nums) {
  int n = nums.size();
  std::vector<int> result(n);
  int lo = 0;
  int hi = n - 1;
  int pos = n - 1;

  while (lo <= hi) {
    if (std::abs(nums[lo]) > std::abs(nums[hi])) {
      result[pos] = nums[lo] * nums[lo];
      ++lo;
    } else {
      result[pos] = nums[hi] * nums[hi];
      --hi;
    }
    --pos;
  }
  return result;
}

}  // namespace algo
