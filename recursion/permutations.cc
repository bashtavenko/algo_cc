#include "recursion/permutations.h"
#include <cstdint>
#include <functional>
#include <vector>

namespace algo {

std::vector<std::vector<int32_t>> Permutate(std::vector<int32_t> data) {
  std::vector<std::vector<int32_t>> result;

  // Cannot have auto in lambda because of recursion
  std::function<void(int)> recurse = [&](size_t i) {
    if (i == data.size()) {
      result.emplace_back(data);
      return;
    }

    for (size_t j = i; j < data.size(); ++j) {
      std::swap(data[i], data[j]);  // try a new one
      recurse(i + 1);
      std::swap(data[i], data[j]);  // backtrack
    }
  };

  recurse(0);
  return result;
}

}  // namespace algo
