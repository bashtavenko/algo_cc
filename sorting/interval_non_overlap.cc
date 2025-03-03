#include "sorting/interval_non_overlap.h"
#include <algorithm>

namespace algo {

// [[1,2],[2,3],[3,4],[1,3]]
int32_t EraseOvelapIntervals(std::vector<std::vector<int32_t>>& intervals) {
  if (intervals.empty()) return 0;

  // Sort intervals by end time.
  // Sorting by end times ensures that you always choose the interval that
  // leaves as much room as possible for the rest.
  // Greedy because we sorted and use the first.
  std::sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b) { return a[1] < b[1]; });

  int32_t removal_count = 0;
  int32_t last_end = intervals[0][1];

  // Start from the second interval.
  for (size_t i = 1; i < intervals.size(); ++i) {
    // If the current interval starts before last_end, it overlaps.
    if (intervals[i][0] < last_end) {
      ++removal_count;
    } else {
      // Otherwise, update last_end to the current interval's end.
      last_end = intervals[i][1];
    }
  }

  return removal_count;
}

}  // namespace algo