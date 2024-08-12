#include "searching/square_root.h"
#include <algorithm>
#include <limits>

namespace algo {

enum class Ordering { kSmaller, kEqual, kLarger };
using enum Ordering;

Ordering Compare(double a, double b) {
  double diff = (a - b) / std::max(std::abs(a), std::abs(b));
  return diff < -std::numeric_limits<double>::epsilon()  ? kSmaller
         : diff > std::numeric_limits<double>::epsilon() ? kLarger
                                                         : kEqual;
}

double SquareRoot(double x) {
  double lo;
  double hi;
  if (x < 1.0) {
    lo = x;
    hi = 1.0;
  } else {
    lo = 1.0;
    hi = x;
  }

  while (Compare(lo, hi) != kEqual) {
    double mid = lo + 0.5 * (hi - lo);
    double mid_squared = mid * mid;
    if (Compare(x, mid_squared) == kSmaller) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  return lo;
}

}  // namespace algo