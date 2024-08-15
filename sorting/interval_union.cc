#include "sorting/interval_union.h"
#include <algorithm>
#include <vector>

namespace algo {

std::vector<Interval> MakeUnion(const std::vector<Interval>& data) {
  if (data.empty()) return {};

  std::vector<Interval> a{data.begin(), data.end()};

  // Sort intervals based on left endpoints
  std::sort(a.begin(), a.end());

  std::vector<Interval> result;

  // The gist is to check the previous intervals in the results
  // before adding a new one and actually updating the right endpoint.
  // What a mess.
  for (const Interval i : a) {
    if (!result.empty() &&
        (i.left.value < result.back().right.value ||
         (i.left.value == result.back().right.value &&
          (i.left.is_closed || result.back().right.is_closed)))) {
      if (i.right.value > result.back().right.value ||
          (i.right.value == result.back().right.value && i.right.is_closed)) {
        result.back().right = i.right;
      }
    } else {
      result.emplace_back(i);
    }
  }
  return result;
}

}  // namespace algo