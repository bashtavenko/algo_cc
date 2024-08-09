#include "heaps/median.h"
#include <cstdint>
#include <queue>
#include <vector>

namespace algo {

// 1, 0, 3, 5, 2, 0, 1
// 1: L = [1], H = [], median is 1.
// 0: L = [1], H = [0], median is (1 + 0) / 2 = 0.5.
// 3: L = [1, 3], H = [0], median is 1.
// 5: L = [3, 5], H = [1, 0], median is (3 + 1) / 2 = 2
// 2: L = [2, 3, 5], H = [1, 0], median is 2.
// 0: L = [2, 3, 5], H = [1, 0, 0], median is (2 + 1) / 2 = 1.5.
// 1: L = [1, 2, 3, 5], H = [1, 0, 0], median is 1.

std::vector<double> OnlineMedian(
    std::vector<int32_t>::const_iterator seq_begin,
    const std::vector<int32_t>::const_iterator seq_end) {
  // Can call it lower L
  std::priority_queue<int32_t, std::vector<int32_t>, std::greater<>> min_heap;
  // Higher or H
  std::priority_queue<int32_t, std::vector<int32_t>, std::less<>> max_heap;
  std::vector<double> result;

  while (seq_begin != seq_end) {
    min_heap.push(*seq_begin++);    // L
    max_heap.push(min_heap.top());  // H
    min_heap.pop();

    // We popped min_heap. Need to adjust max_heap when max is larger.
    if (max_heap.size() > min_heap.size()) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }

    result.push_back(min_heap.size() == max_heap.size()
                         ? 0.5 * (min_heap.top() + max_heap.top())
                         : min_heap.top());
  }

  return result;
}

}  // namespace algo
