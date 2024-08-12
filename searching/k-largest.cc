#include "searching/k-largest.h"
#include <cstdint>
#include <random>
#include <vector>

namespace algo {

int32_t PartitioningAroundPivot(int32_t lo, int32_t hi, int32_t pivot_index,
                                std::vector<int32_t>* a) {
  std::vector<int32_t>& data = *a;

  // We need to keep pivot value at the end of the array
  // and then restore it after we are done.
  int32_t pivot_value = data[pivot_index];
  int32_t new_pivot_index = lo;
  std::swap(data[pivot_index], data[hi]);  // pivot goes to the end.
  for (int32_t i = lo; i < hi; ++i) {
    if (data[i] > pivot_value) {
      std::swap(data[i], data[new_pivot_index++]);
    }
  }
  std::swap(data[hi], data[new_pivot_index]);  // restore
  return new_pivot_index;
}

int32_t FindKthLargest(int32_t k, std::vector<int32_t>* a) {
  std::vector<int32_t>& data = *a;
  int32_t lo = 0;
  int32_t hi = data.size();
  std::default_random_engine gen((std::random_device())());
  while (lo < hi) {
    // Similar to mid. It is kind of binary search
    int32_t pivot_idx = std::uniform_int_distribution<int32_t>(lo, hi)(gen);
    int32_t new_pivot_idx = PartitioningAroundPivot(lo, hi, pivot_idx, &data);
    if (new_pivot_idx == k - 1) {
      return data[new_pivot_idx];
    } else if (new_pivot_idx > k - 1) {
      hi = new_pivot_idx - 1;
    } else {
      lo = new_pivot_idx + 1;
    }
  }
}
}  // namespace algo
