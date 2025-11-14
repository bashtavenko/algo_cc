#include "arrays/sliding_window_max.h"
#include <algorithm>
#include <deque>

namespace algo {

// 3, 4, 1, 2, 7, 5
// O(nk)
// Fine if n is small (~10^3 or so), but too slow if n is large (~10^5, 10^6).
// Sliding window and not JUMPING window
std::vector<int32_t> SlidingWindowMaxOnk(const std::vector<int32_t>& nums,
                                         int k) {
  std::vector<int32_t> result;
  for (size_t i = 0; i <= nums.size() - k; ++i) {
    auto current_max = std::max_element(nums.begin() + i, nums.begin() + i + k);
    result.push_back(*current_max);
  }
  return result;
}

// O(n)
std::vector<int32_t> SlidingWindowMax(const std::vector<int32_t>& nums, int k) {
  std::vector<int32_t> result;
  // The deque always stores indices of elements,
  // and these elements are in decreasing order of values from front to back
  // dequeue.front() is the maximum of the current window
  // Deque acts like a clean filtered list of "Who could possibly be max?"
  // You throw out anyone who's too old (outside window).
  // You throw out anyone who’s weaker(smaller value)
  //"Big strong soldiers walk to battle."
  // If a bigger soldier shows up,
  // smaller soldiers behind get scared and leave.
  // If a soldier gets to old(outside the k - range),
  //  they exit front quietly
  std::deque<int32_t> dq;
  for (size_t i = 0; i < nums.size(); ++i) {
    // Pop front elements outside the current window
    while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
    // Elements smaller than the current value never be max
    while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) result.push_back(nums[dq.front()]);
  }
  return result;
}

}  // namespace algo