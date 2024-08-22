#include "greedy/max_water.h"
#include <cstdint>
#include <vector>

namespace algo {

// Returns the area of max trapped water.
int32_t GetMaxTrappedWater(const std::vector<int32_t>& heights) {
  size_t lo = 0;
  size_t hi = heights.size() - 1;
  int32_t max_water = 0;

  while (lo < hi) {
    int32_t width = hi - lo;
    max_water = std::max(max_water, width * std::min(heights[lo], heights[lo]));
    // This is similar to two-sum problem.
    if (heights[lo] < heights[hi]) {
      ++lo;   // Add some more from the left
    } else {  // heights[lo] >= heights[hi]
      --hi;   // Decrease from the right
    }
  }

  return max_water;
}

}  // namespace algo
