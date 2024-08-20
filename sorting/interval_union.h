// 13.7 Compute the union of intervals
//       x---x
//         x--
//    x
// ---------
// --------------->
// 0  1  2  3  4
//
//  ------------x
//     (0, 4)
#ifndef ALGO_CC_SORTING_INTERVAL_UNION_H_
#define ALGO_CC_SORTING_INTERVAL_UNION_H_
#include <cstdint>
#include <vector>
#include "absl/strings/str_format.h"

namespace algo {

struct Interval {
 private:
  struct Endpoint {
    bool is_closed;
    int32_t value;

    bool operator==(const Endpoint& that) const {
      return is_closed == that.is_closed && value == that.value;
    }
  };

 public:
  Endpoint left;
  Endpoint right;

  bool operator<(const Interval& that) const {
    if (left.value != that.left.value) {
      return left.value < that.left.value;
    }

    // left endpoints are equal. Closed should be first;
    return left.is_closed && !that.left.is_closed;
  }

  bool operator==(const Interval& that) const {
    return left == that.left && right == that.right;
  }

  template <typename Sink>
  friend void AbslStringify(Sink& sink, const Interval& interval) {
    absl::Format(
        &sink, "{%s, %i} {%s, %i}", interval.left.is_closed ? "true" : "false",
        interval.left.value, interval.right.is_closed ? "true" : "false",
        interval.right.value);
  }

  friend std::ostream& operator<<(std::ostream& os, const Interval& interval) {
    os << absl::StreamFormat("%v", interval);
    return os;
  }
};

std::vector<Interval> MakeUnion(const std::vector<Interval>& data);

}  // namespace algo

#endif  // ALGO_CC_SORTING_INTERVAL_UNION_H_
