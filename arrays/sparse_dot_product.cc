#include "arrays/sparse_dot_product.h"
#include <unordered_map>

namespace algo {

int32_t DotProductWithMaps(const std::vector<int32_t>& v1,
                           const std::vector<int32_t>& v2) {
  // Assume vectors have the same sizes
  const int32_t n = v1.size();

  // Compress vectors
  // index: value
  std::unordered_map<int32_t, int32_t> map1;
  for (int i = 0; i < n; ++i) {
    if (v1[i] != 0) {
      map1[i] = v1[i];
    }
  }

  std::unordered_map<int32_t, int32_t> map2;
  for (int i = 0; i < n; ++i) {
    if (v2[i] != 0) {
      map2[i] = v2[i];
    }
  }

  int result = 0;
  for (int i = 0; i < n; ++i) {
    if (map1.contains(i) && map2.contains(i)) result += map1[i] * map2[i];
  }

  return result;
}

int32_t DotProduct(const std::vector<int32_t>& v1,
                   const std::vector<int32_t>& v2) {
  // Assume vectors have the same size
  const size_t n = v1.size();

  // Store nonzero elements as (index, value) pairs.
  std::vector<std::pair<size_t, int32_t>> nonzero1;
  std::vector<std::pair<size_t, int32_t>> nonzero2;

  for (size_t i = 0; i < n; ++i) {
    if (v1[i] != 0) {
      nonzero1.emplace_back(i, v1[i]);
    }
  }

  for (size_t i = 0; i < n; ++i) {
    if (v2[i] != 0) {
      nonzero2.emplace_back(i, v2[i]);
    }
  }

  // Compute dot product using a two-pointer technique.
  int32_t dot = 0;
  size_t i = 0;
  size_t j = 0;
  while (i < nonzero1.size() && j < nonzero2.size()) {
    if (nonzero1[i].first == nonzero2[j].first) {
      // Same index: multiply and add.
      dot += nonzero1[i].second * nonzero2[j].second;
      ++i;
      ++j;
    } else if (nonzero1[i].first < nonzero2[j].first) {
      // Advance in the first vector.
      ++i;
    } else {
      // Advance in the second vector.
      ++j;
    }
  }

  return dot;
}

}  // namespace algo