#include "sorting/array_intersection.h"
#include <algorithm>
#include <cstdint>
#include <vector>

namespace algo {

std::vector<int32_t> Intersect(const std::vector<int32_t>& a,
                               const std::vector<int32_t>& b) {
  std::vector<int32_t> result;
  // If arrays do not have duplicates:
  //    for (const auto& value : a) {
  //      if (std::binary_search(b.begin(), b.end(), value)) {
  //        result.emplace_back(value);
  //      }
  //    }
  for (size_t i = 1; i < a.size(); ++i) {
    if (a[i] != a[i - 1] && std::binary_search(b.begin(), b.end(), a[i])) {
      result.emplace_back(a[i]);
    }
  }
  return result;
}

}  // namespace algo
