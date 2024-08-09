#include "heaps/almost_sorted.h"
#include <queue>

namespace algo {

std::vector<int32_t> SortAlmost(size_t k,
                                const std::vector<int32_t>::const_iterator& end,
                                std::vector<int32_t>::const_iterator begin) {
  std::priority_queue<int32_t, std::vector<int32_t>, std::greater<>> min_heap;

  // We want to work with iterators.

  // Add first k elements to the priority queue.
  for (size_t i = 0; i < k && begin != end; ++i) {
    // Dereference first
    min_heap.push(*begin++);
  }

  // We want to keep the queue at most k-elements.
  // To do that, add and them popup.
  // The iterator is at k + 1
  std::vector<int32_t> result;
  while (begin != end) {  // This is subtle - should be != and not <=
    min_heap.push(*begin++);
    result.push_back(min_heap.top());
    min_heap.pop();
  }

  // Popup remaining elements
  while (!min_heap.empty()) {
    result.push_back(min_heap.top());
    min_heap.pop();
  }

  return result;
}

}  // namespace algo
