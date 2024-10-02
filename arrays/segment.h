// Find the largest consecutive segment within budget.
// Returns the largest segment within budget.

#ifndef ALGO_CC_ARRAYS_SEGMENT_H_
#define ALGO_CC_ARRAYS_SEGMENT_H_
#include <cstdint>
#include <vector>
#include "absl/strings/str_format.h"

namespace algo {

struct Segment {
  size_t lo;
  size_t hi;

  bool operator==(const Segment& that) const {
    return that.lo == lo && that.hi == hi;
  }

  friend std::ostream& operator<<(std::ostream& os, const Segment& that) {
    os << absl::StrFormat("(%i, %i)", that.lo, that.hi);
    return os;
  }
};

Segment GetLargestWithBudget(const std::vector<int32_t>& a, int32_t budget);

}  // namespace algo

#endif  // ALGO_CC_ARRAYS_SEGMENT_H_
