// Maximum sub-array from Cormen.
//
// Find contiguous nonempty array whose values have the largest sum.
//
// We cannot simply sum from min to max elements
// Day     0    1  2   3   4
// Price   10  11  7   10  6
// Change      1   -4  3   -4
// Max is 3 after 2 and after 3. $7 is not the lowest and $10 is not the
// highest. This is not buy-sell-stock once because of the negative values.
//
// If there were only positive numbers, it would be just a matter of summing all
// numbers.
//
// In the simplest case of [2, 3] it's a matter of picking up the maximum from
// left or right but we need cross-sum (max sum from both sides). Left: 2,
// Right: 3, Cross: 5 [2, 3, 7, -1]
// Left: 5, Right: 6, Cross: 12 (Here cross is 12 because left is 5 and right is
// 7) [7, -1] => 3
//
#ifndef ALGO_CC_ARRAYS_MAX_SUBARRAY_H_
#define ALGO_CC_ARRAYS_MAX_SUBARRAY_H_
#include <cstdint>
#include <ostream>
#include <vector>
#include "absl/strings/str_format.h"

namespace algo {

struct Result {
  int32_t lo;
  int32_t hi;
  int64_t sum;

  bool operator==(const Result& that) const {
    return that.lo == lo && that.hi == hi && that.sum == sum;
  }

  friend std::ostream& operator<<(std::ostream& os, const Result& that) {
    os << absl::StrFormat("(%i, %i, %i)", that.lo, that.hi, that.sum);
    return os;
  }
};

Result MaxSubarray(const std::vector<int32_t>& arr);

}  // namespace algo

#endif  // ALGO_CC_ARRAYS_MAX_SUBARRAY_H_
