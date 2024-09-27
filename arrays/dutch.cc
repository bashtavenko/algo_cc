#include "arrays/dutch.h"
#include <vector>

namespace algo {

void DutchFlagPartition(size_t pivot_index, std::vector<Color>& a) {
  Color v = a[pivot_index];
  size_t lt = 0;
  size_t eq = 0;
  size_t gt = a.size();
  // Invariants
  // lt: a[0, smaller -1]
  // eq: a[lt, eq - 1]
  // not yet seen: a[eq, gt - 1]
  // gt: a[larger, a.size() - 1]
  // So, [eq, gt - 1] is what we have not yet seen.
  while (eq < gt) {
    if (a[eq] < v) {
      std::swap(a[lt++], a[eq++]);
    } else if (a[eq] == v) {
      ++eq;
    } else {
      // a[eq] > v
      std::swap(a[eq], a[--gt]);
    }
  }
}
}  // namespace algo
