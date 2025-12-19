#include "dp/rod_cutting.h"
#include <functional>
#include <limits>

namespace algo {

// This isn't "true" dynamic programming because it is inefficient.
int32_t CutRodBasic(const std::vector<Rod>& rods, int32_t length) {
  std::function<int32_t(int32_t)> recurse = [&](int32_t length) {
    if (length == 0) return 0;
    int32_t revenue = std::numeric_limits<int32_t>::min();
    // Returns the max price of whichever is current or l1 + l2 revenue
    for (int32_t i = 1; i <= length; ++i) {
      revenue = std::max(revenue, rods[i - 1].price + recurse(length - i));
    }
    return revenue;
  };

  return recurse(length);
}

// Same as above but with caching
int32_t CutRodBasicMemoized(const std::vector<Rod>& rods, int32_t length) {
  std::unordered_map<int32_t, int32_t> cache;
  std::function<int32_t(int32_t)> recurse = [&](int32_t length) {
    if (length == 0) {
      return 0;
    } else if (!cache.contains(length)) {
      int32_t revenue = std::numeric_limits<int32_t>::min();
      // Returns the max price of whichever is current or l1 + l2 revenue
      for (int32_t i = 1; i <= length; ++i) {
        revenue = std::max(revenue, rods[i - 1].price + recurse(length - i));
      }
      cache[length] = revenue;
    }
    return cache[length];
  };

  return recurse(length);
}

int32_t CutRodBottomUp(const std::vector<Rod>& rods, int32_t length) {
  std::unordered_map<int32_t, int32_t> cache = {{0, 0}};
  for (int32_t l = 1; l <= length; ++l) {
    int32_t revenue = std::numeric_limits<int32_t>::min();
    for (int32_t i = 1; i <= l; ++i) {
      revenue = std::max(revenue, rods[i - 1].price + cache[l - i]);
    }
    cache[l] = revenue;
  }
  return cache[length];
}

CutRodResult CutRod(const std::vector<Rod>& rods, int32_t length) {
  std::unordered_map<int32_t, int32_t> cache = {{0, 0}};
  std::unordered_map<int32_t, int32_t> choices;
  int32_t revenue = std::numeric_limits<int32_t>::min();
  for (int32_t cur_length = 1; cur_length <= length; ++cur_length) {
    for (int32_t cur_rod = 1; cur_rod <= cur_length; ++cur_rod) {
      // Don't need to check cache existence since it is built from the bottom
      // up
      if (revenue < rods[cur_rod - 1].price + cache[cur_length - cur_rod]) {
        revenue = rods[cur_rod - 1].price + cache[cur_length - cur_rod];
        choices[cur_length] = cur_rod;
      }
    }
    cache[cur_length] = revenue;
  }

 //  1  2  3  4  5  6  7          cur_length
 //  1  2  3  2  2  6  1          cur_rod
  std::vector<int32_t> path;
  while (length > 0) {
    path.emplace_back(choices[length]); // What's left after subtracting
    length -= choices[length];
  }

  CutRodResult result{.revenue = revenue, .cuts = path};
  return result;
}

}  // namespace algo
