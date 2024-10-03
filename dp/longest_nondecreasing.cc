#include "dp/longest_nondecreasing.h"
#include <algorithm>

namespace algo {

int LongestNonDecreasingSubsequenceLength(const std::vector<int32_t>& arr) {
  std::vector<int32_t> dp(arr.size(), 1);
  for (size_t i = 1; i < arr.size(); ++i) {
    for (size_t j = 0; j < i; ++j) {
      if (arr[i] >= arr[j]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
  }
  return *std::max_element(dp.begin(), dp.end());
}

}  // namespace algo