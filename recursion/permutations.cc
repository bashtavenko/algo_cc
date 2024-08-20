#include "recursion/permutations.h"
#include <cstdint>
#include <vector>

namespace algo {

void Run(size_t i, std::vector<int32_t>* data,
         std::vector<std::vector<int32_t>>* result) {
  std::vector<int32_t>& a = *data;
  if (i == a.size()) {
    result->emplace_back(a);
    return;
  }

  for (size_t j = i; j < a.size(); ++j) {
    std::swap(a[i], a[j]);
    Run(i + 1, data, result);
    std::swap(a[i], a[j]);
  }
}

std::vector<std::vector<int32_t>> Permutate(std::vector<int32_t> data) {
  std::vector<std::vector<int32_t>> result;
  Run(0, &data, &result);
  return result;
}

}  // namespace algo
