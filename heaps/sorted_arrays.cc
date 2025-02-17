#include "heaps/sorted_arrays.h"
#include <cstdint>
#include <queue>
#include <vector>

namespace algo {

// 1. Type, 3. Comparator
struct IteratorRowAndCol {
  // Iterator for the current array index
  // For example,
  //  {{3, 5, 7}, {0, 6}, {0, 6, 28}}
  // There could be 0, 1, 2 which correspond to rows
  // There are m x n matrix where m (row) is the array index
  std::vector<int32_t>::const_iterator row;

  // End of the current iterator. For example,
  // {{3, 5, 7}, {0, 6}, {0, 6, 28}}
  // Row 1 has two elements whereas the other have three.
  // There are m x n matrix and n is a column
  std::vector<int32_t>::const_iterator col;

  bool operator>(const IteratorRowAndCol& that) const {
    return *row > *that.row;
  }
};

std::vector<int32_t> MergeSortedArrays(
    const std::vector<std::vector<int32_t>>& sorted_arrays) {
  // 2. Container
  std::priority_queue<IteratorRowAndCol, std::vector<IteratorRowAndCol>,
                      std::greater<>>
      min_heap;

  for (const std::vector<int32_t>& current_array : sorted_arrays) {
    if (!current_array.empty()) {
      min_heap.emplace(IteratorRowAndCol{.row = current_array.cbegin(),
                                         .col = current_array.cend()});
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
    result.emplace_back(*smallest_array.row);

    // The whole point is std::next which means keep on going
    // to the same array and priority queue keeps the smallest element.
    // In fact, directly increment iterator would be fine, but std::next is
    // more explicit vs this
    // if (smallest_array.current++ != smallest_array.end) // ...
    if (std::next(smallest_array.row) != smallest_array.col) {
      min_heap.emplace(IteratorRowAndCol{.row = std::next(smallest_array.row),
                                         .col = smallest_array.col});
    }
  }

  return result;
}

}  // namespace algo
