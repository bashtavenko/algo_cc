#include "greedy/sums.h"
#include <algorithm>
#include <unordered_set>
#include <vector>
#include "absl/algorithm/container.h"

namespace algo {

bool HasTwoSum(const std::vector<int32_t>& sorted, int32_t target) {
  size_t lo = 0;
  size_t hi = sorted.size() - 1;

  while (lo < hi) {
    if (sorted[lo] + sorted[hi] == target) {
      return true;
    } else if (sorted[lo] + sorted[hi] < target) {
      ++lo;  // Add some more
    } else {
      --hi;  // Overshoot, decrease
    }
  }
  return false;
}

bool HasThreeSum(std::vector<int32_t> data, int32_t target) {
  std::sort(data.begin(), data.end());
  return absl::c_any_of(data,
                        [&](int32_t v) { return HasTwoSum(data, target - v); });
}

bool HasUnsortedTwoSum(const std::vector<int32_t>& data, int32_t target) {
  std::unordered_set<int32_t> set;
  for (const int32_t& value : data) {
    int32_t complement = target - value;
    if (set.contains(complement)) return true;
    set.insert(value);
  }

  return false;
}

}  // namespace algo