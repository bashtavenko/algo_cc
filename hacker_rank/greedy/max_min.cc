#include "hacker_rank/greedy/max_min.h"
#include <algorithm>
#include <limits>
#include <vector>

int MaxMin(int k, std::vector<int> arr) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());
  int best_unfairness = std::numeric_limits<int>::max();

  // Slide a window of size k over the sorted array
  for (int i = 0; i <= n - k; ++i) {
    int unfairness = arr[i + k - 1] - arr[i];  // Unfairness for current window
    best_unfairness = std::min(best_unfairness, unfairness);
  }

  return best_unfairness;
}