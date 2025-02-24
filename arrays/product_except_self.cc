#include "arrays/product_except_self.h"
#include <numeric>

namespace algo {

// 1, 2, 3, 4
// 24, 12, 8, 6
// Brute force
// const int32_t full_sum = std::accumulate(
//      nums.begin(), nums.end(), 1, [](int32_t a, int32_t b) { return a * b;
//      });
//  for (size_t i = 0; i < nums.size(); ++i) {
//    result[i] = nums[i] == 0 ? 0 : full_sum / nums[i];
//  }
// -1, 1, 0, -3, 3
//  0, 0, 9, 0, 0
// Actually std::accumulate works but it runs in O(n^2) time.
std::vector<int32_t> ProductExceptSelf(const std::vector<int32_t>& nums) {
  size_t n = nums.size();
  std::vector<int32_t> result(n, 1);

  // [1, 2, 3, 4]
  // result = [1, 1, 2, 6]
  int32_t left_product = 1;
  for (size_t i = 0; i < n; ++i) {
    result[i] = left_product;
    left_product *= nums[i];
  }

  int32_t right_product = 1;
  // It could be
  // for (size_t i = n - 1; i < n; --i)
  // but this relies on size being underflow
  for (size_t i = n; i-- > 0;) {
    result[i] *= right_product;
    right_product *= nums[i];
  }

  return result;
}
}  // namespace algo
