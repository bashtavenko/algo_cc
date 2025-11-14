// 10.4 Compute closest stars
// Since we need the smallest numbers, we need max_heap and keep popping
// the biggest. What's left is smallest which we then need to sort.
//
#ifndef ALGO_CC_HEAPS_CLOSEST_STARS_H_
#define ALGO_CC_HEAPS_CLOSEST_STARS_H_
#include <cmath>
#include <vector>
#include "absl/strings/str_format.h"

namespace algo {
struct Star {
  double x;
  double y;
  double z;
  // Length of vector is sqrt(v * v)
  double Distance() const { return std::sqrt(x * x + y * y + z * z); }

  bool operator<(const Star& that) const {
    return Distance() < that.Distance();
  }

  bool operator==(const Star& that) const {
    return Distance() == that.Distance();
  }

  friend std::ostream& operator<<(std::ostream& os, const Star& s) {
    os << absl::StreamFormat("(x = %f, y = %f, z = %f)", s.x, s.y, s.z);
    return os;
  }
};

std::vector<Star> FindClosestStars(std::vector<Star>::const_iterator begin,
                                   const std::vector<Star>::const_iterator& end,
                                   size_t k);

}  // namespace algo

#endif  // ALGO_CC_HEAPS_CLOSEST_STARS_H_
