#include "recursion/power_set.h"
#include <cmath>
#include <cstdint>
#include <vector>

namespace algo {

std::vector<std::vector<int32_t>> GenerateFromBits(
    const std::vector<int32_t>& input_set) {
  std::vector<std::vector<int32_t>> result;
  // Power set size is 2^n
  for (int32_t i = 0; i < (1 << input_set.size()); ++i) {
    int32_t bit_array = i;
    std::vector<int32_t> subset;
    for (size_t j = 0; bit_array; ++j) {
      if (bit_array & 1) {
        subset.emplace_back(input_set[j]);
      }
      bit_array >>= 1;
    }
    result.emplace_back(std::move(subset));
  }

  return result;
}

// This is similar to permutations.
void MakeSet(const std::vector<int32_t>& input_set, size_t to_be_selected,
             std::vector<int32_t>* selected_so_far,
             std::vector<std::vector<int32_t>>& power_set) {
  if (to_be_selected == input_set.size()) {
    power_set.emplace_back(*selected_so_far);
    return;
  }
  selected_so_far->emplace_back(input_set[to_be_selected]);
  MakeSet(input_set, to_be_selected + 1, selected_so_far, power_set);
  selected_so_far->pop_back();  // Removes the latest, stack
  MakeSet(input_set, to_be_selected + 1, selected_so_far, power_set);
}

std::vector<std::vector<int32_t>> Generate(
    const std::vector<int32_t>& input_set) {
  std::vector<std::vector<int32_t>> power_set;
  std::vector<int32_t> selected_so_far;
  MakeSet(input_set, 0, &selected_so_far, power_set);
  return power_set;
}

}  // namespace algo
