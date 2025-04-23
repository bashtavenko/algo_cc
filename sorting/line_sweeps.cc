#include "sorting/line_sweeps.h"
#include <algorithm>
#include <queue>

namespace algo {
int32_t LineSweeps1D(std::vector<std::pair<int32_t, int32_t>>& input) {
  if (input.empty()) return 0;
  std::ranges::sort(input, [](const std::pair<int32_t, int32_t>& first,
                              const std::pair<int32_t, int32_t>& second) {
    return first.first < second.first;
  });
  int32_t max_count = 0;
  std::queue<std::pair<int32_t, int32_t>> q;
  for (const auto& curr_interval : input) {
    // Pop intervals that ended before current start
    while (!q.empty() && q.front().second < curr_interval.first) {
      q.pop();
    }
    // Add current interval
    q.push(curr_interval);
    max_count = std::max(max_count, static_cast<int32_t>(q.size()));
  }

  return max_count;
}
}  // namespace algo
