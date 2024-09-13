#include "hacker_rank/arrays/new_year_chaos.h"
#include <cmath>
#include <vector>

Result MinimumSwaps(const std::vector<int>& q) {
  Result result;
  int n = q.size();

  for (int i = n - 1; i >= 0; --i) {
    if (q[i] - (i + 1) > 2) {
      result.too_chaotic = true;
      return result;
    }

    // Check up to 2 position ahead
    for (int j = std::max(0, q[i] - 2); j < i; ++j) {
      if (q[j] > q[i]) {
        ++result.bribes;
      }
    }
  }

  return result;
}
