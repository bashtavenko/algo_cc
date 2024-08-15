#include "sorting/merge_two_sorted.h"
#include <cstdint>
#include <vector>

namespace algo {

std::vector<int32_t> MergeTwoSorted(const std::vector<int32_t>& a,
                                    const std::vector<int32_t>& b) {
  std::vector<int32_t> result;
  result.reserve(a.size() + b.size());  // Pre-allocate memory

  auto it_a = a.begin();
  auto it_b = b.begin();

  while (it_a != a.end() && it_b != b.end()) {
    if (*it_a < *it_b) {
      result.push_back(*it_a++);
    } else if (*it_a > *it_b) {
      result.push_back(*it_b++);
    } else {  // equal
      result.push_back(*it_a++);
    }
  }

  // Append remaining elements
  result.insert(result.end(), it_a, a.end());
  result.insert(result.end(), it_b, b.end());

  return result;
}
}  // namespace algo