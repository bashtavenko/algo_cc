#include "heaps/sorted_arrays.h"
#include <cstdint>
#include <queue>
#include <vector>

namespace algo {

// 1. Type, 3. Comparator
struct IteratorCurrentAndEnd {
  // Iterator for the current array index
  // For example,
  //  {{3, 5, 7}, {0, 6}, {0, 6, 28}}
  // There could be 0, 1, 2 which correspond to rows
  std::vector<int32_t>::const_iterator current;

  // End of the current iterator. For example,
  // {{3, 5, 7}, {0, 6}, {0, 6, 28}}
  // Row 1 has two elements whereas the other have three.
  std::vector<int32_t>::const_iterator end;

  bool operator>(const IteratorCurrentAndEnd& that) const {
    return *current > *that.current;
  }
};

std::vector<int32_t> MergeSortedArrays(
    const std::vector<std::vector<int32_t>>& sorted_arrays) {
  // 2. Container
  std::priority_queue<IteratorCurrentAndEnd, std::vector<IteratorCurrentAndEnd>,
                      std::greater<>>
      min_heap;

  for (const std::vector<int32_t>& current_array : sorted_arrays) {
    if (!current_array.empty()) {
      min_heap.emplace(IteratorCurrentAndEnd{.current = current_array.cbegin(),
                                             .end = current_array.cend()});
    }
  }

  // As an example,
  // {3, 5, 7}, {0, 6}, {0, 6, 28}};
  // We have
  // 0
  // 3
  // 0
  std::vector<int32_t> result;
  while (!min_heap.empty()) {
    auto smallest_array = min_heap.top();
    min_heap.pop();
    result.emplace_back(*smallest_array.current);

    // The whole point is std::next which means keep on going
    // to the same array and priority queue keeps the smallest element.
    if (std::next(smallest_array.current) != smallest_array.end) {
      min_heap.emplace(
          IteratorCurrentAndEnd{.current = std::next(smallest_array.current),
                                .end = smallest_array.end});
    }
  }

  return result;
}

}  // namespace algo
