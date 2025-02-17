#include "sorting/merge_two_sorted.h"
#include <cstdint>
#include <vector>

namespace algo {

std::vector<int32_t> MergeTwoSorted(const std::vector<int32_t>& a,
                                    const std::vector<int32_t>& b) {
  std::vector<int32_t> result;
  result.reserve(a.size() + b.size());  // Pre-allocate memory

  std::vector<int32_t>::const_iterator first = a.begin();
  std::vector<int32_t>::const_iterator second = b.begin();

  while (first != a.end() && second != b.end()) {
    if (*first <= *second) {
      result.push_back(*first++);
    } else {
      result.push_back(*second++);
    }
  }

  // Append remaining elements
  result.insert(result.end(), first, a.end());
  result.insert(result.end(), second, b.end());

  return result;
}
}  // namespace algo