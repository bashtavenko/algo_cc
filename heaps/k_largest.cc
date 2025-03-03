#include "heaps/k_largest.h"
#include <queue>

namespace algo {

// Runs in O(n log(n)
int32_t FindKthLargestWithMaxHeap(const std::vector<int32_t>& nums, int32_t k) {
  std::priority_queue<int32_t> max_heap;
  for (const int32_t& v : nums) max_heap.push(v);

  int32_t result = 0;
  for (int i = 0; i < k; ++i) {
    result = max_heap.top();
    max_heap.pop();
  }

  return result;
}

// Runs in O(n log(k)
int32_t FindKthLargest(const std::vector<int32_t>& nums, int32_t k) {
  std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>>
      min_heap;

  for (const auto& num : nums) {
    min_heap.push(num);

    // This will only store k-largest elements seen so far
    // which is O(n log(k) and NOT 0(n log(n) for max heap.
    if (min_heap.size() > k) {
      min_heap.pop();
    }
  }
  return min_heap.top();
}

}  // namespace algo