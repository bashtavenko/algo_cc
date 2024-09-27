#include "hacker_rank/dp/max_subset_sum.h"
#include <algorithm>

//  [-2, 1, 3, -4, 5]
//   0  1   3   0  8

int MaxSubsetSum(const std::vector<int>& arr) {
  const int n = arr.size();
  if (n == 0) return 0;
  if (n == 1) return std::max(0, arr[0]);  // Handle negative

  std::vector<int> dp(n);
  dp[0] = std::max(0, arr[0]);
  dp[1] = std::max(dp[0], arr[1]);  // Same as above

  for (int i = 2; i < n; ++i) {
    // Max of three elements - {(i - 1), (i - 2) + arr[i], arr[i]}
    dp[i] = std::max({dp[i - 1], dp[i - 2] + arr[i], arr[i]});
  }

  return dp[n - 1];
}