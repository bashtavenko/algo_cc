#include "hacker_rank/greedy/max_min.h"
#include <algorithm>
#include <limits>
#include <vector>

// arr = [1, 2, 4, 7] k = 2
int MaxMinFirstApproach(int k, std::vector<int> arr) {
  int n = arr.size();
  std::sort(arr.begin(), arr.end());
  int lo = 0;
  int hi = n;
  int best_unfairness = std::numeric_limits<int>::max();

  int window[k];
  std::fill(window, window + k, 0);

  while (lo < hi) {
    int offset = lo + k - 1;
    if (offset > n) break;
    int first = arr[lo];
    int second = arr[offset];
    int unfairness = std::max(first, second) - std::min(first, second);
    best_unfairness = std::min(best_unfairness, unfairness);
    ++lo;
  }

  return best_unfairness;
}

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