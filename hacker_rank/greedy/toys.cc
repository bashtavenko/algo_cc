#include "hacker_rank/greedy/toys.h"
#include <algorithm>

// Example 1: w = [1 2 3 21 7 12 14 21]
// [1, 2, 3] (1 ... 1 + 4 = 5)
// [21] (21...25) two times
// [7] (7 ... 11)
// [12, 14] (12...14)
int MakeContainers(std::vector<int>& w) {
  std::sort(w.begin(), w.end());

  int container_count = 0;
  size_t i = 0;

  while (i < w.size()) {
    int max_weight = w[i] + 4;
    ++container_count;

    // Fill the current container with all items that fit
    while (i < w.size() && w[i] <= max_weight) {
      ++i;
    }
  }
  return container_count;
}
