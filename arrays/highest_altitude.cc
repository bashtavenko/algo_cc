//
// Created by s15o on 2/28/25.
//

#include "arrays/highest_altitude.h"

namespace algo {

// gain = [-5, 1, 5, 0,-7]
// a = [0,-5,-4, 1, 1,-6]
//
// prefix_sum = [0, -5, -4, 1, 1, -6]
int32_t HighestAltitude(const std::vector<int32_t>& gain) {
  const size_t n = gain.size();
  // The prefix_sum array represents the altitude at each point. Since the biker
  // starts at 0, prefix_sum[0] is 0. Then, for each gain, we update the next
  // point’s altitude by adding the current gain to the previous altitude.
  std::vector<int32_t> prefix_sum(n + 1);
  prefix_sum[0] = 0;

  // Compute prefix sums (cumulative altitudes)
  // What's cool is that it has index that we need
  for (size_t i = 0; i < gain.size(); ++i) {
    prefix_sum[i + 1] = prefix_sum[i] + gain[i];
  }

  // Find the highest
  int32_t highest = prefix_sum[0];
  for (size_t i = 1; i < prefix_sum.size(); ++i) {
    highest = std::max(highest, prefix_sum[i]);
  }

  return highest;
}

}  // namespace algo
