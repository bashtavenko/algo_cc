#include "hacker_rank/greedy/min_diff.h"
#include <algorithm>
#include <limits>
#include <vector>

int MinimumAbsoluteDifBruteForce(const std::vector<int>& arr) {
  int min_diff = std::numeric_limits<int>::max();
  for (size_t i = 0; i < arr.size(); ++i) {
    for (size_t j = i + 1; j < arr.size(); ++j) {
      min_diff = std::min(min_diff, std::abs(arr[i] - arr[j]));
    }
  }

  return min_diff;
}

int MinimumAbsoluteDif(const std::vector<int>& a) {
  std::vector<int> arr(a.begin(), a.end());
  if (arr.size() < 2) {
    return 0;  // Or handle this case as appropriate for your use case
  }

  // Sort the array
  std::sort(arr.begin(), arr.end());

  int min_diff = std::numeric_limits<int>::max();

  // Compare adjacent elements
  for (size_t i = 1; i < arr.size(); ++i) {
    min_diff = std::min(min_diff, std::abs(arr[i] - arr[i - 1]));
  }

  return min_diff;
}
