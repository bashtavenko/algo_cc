#include "hacker_rank/one_month/week_2/zigzag.h"
#include <algorithm>

// [1, 2, 3, 4, 5] => [1, 2, 5, 3, 2]
void Zigzag(std::vector<int>& arr) {
  const int n = arr.size();
  const int k = (n + 1) / 2;
  std::sort(arr.begin(), arr.end());
  std::swap(arr[k - 1], arr[n - 1]);
  int lo = k;
  int hi = n - 2;
  while (lo < hi) {
    std::swap(arr[lo], arr[hi]);
    ++lo;
    --hi;
  }
}