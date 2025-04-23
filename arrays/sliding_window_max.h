#ifndef ALGO_CC_ARRAYS_WINDOW_MAX_
#define ALGO_CC_ARRAYS_WINDOW_MAX_
#include <cstdint>
#include <vector>

namespace algo {
// Slide the window of size k and find the maximum in that window
// Example
// {3, 4, 1, 2, 7, 5}, 2) = > {4, 4, 2, 7, 7};
std::vector<int32_t> SlidingWindowMax(const std::vector<int32_t>& nums, int k);
}  // namespace algo

#endif  // ALGO_CC_ARRAYS_WINDOW_MAX_
