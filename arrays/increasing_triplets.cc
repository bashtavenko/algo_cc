#include "arrays/increasing_triplets.h"
#include <numeric>
#include <valarray>

namespace algo {

// 1, 2, 3, 4, 5
// 1, 1, -2, 6
bool IncreasingTriplets(const std::vector<int32_t>& nums) {
  int32_t x = std::numeric_limits<int32_t>::max();
  int32_t y = std::numeric_limits<int32_t>::max();

  for (const auto& v : nums) {
    if (v <= x) {
      x = v;  // Update x to be the smallest so far
    } else if (v <= y) {
      y = v;  // Update y only if it's greater than x
    } else {
      return true;  // Found a triplet: x < y < v
    }
  }

  return false;
}

}  // namespace algo
