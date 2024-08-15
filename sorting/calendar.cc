#include "sorting/calendar.h"
#include <algorithm>
#include <cstdint>
#include <vector>

namespace algo {

int32_t FindMaximumEvents(const std::vector<Event>& events) {
  // Convert events to points, double them.
  std::vector<Endpoint> points;
  for (const auto& event : events) {
    points.emplace_back(Endpoint{.time = event.start, .is_start = true});
    points.emplace_back(Endpoint{.time = event.finish, .is_start = false});
  }

  std::sort(points.begin(), points.end());
  int max_events = 0;
  int num_events = 0;
  for (const Endpoint& endpoint : points) {
    if (endpoint.is_start) {
      ++num_events;
      max_events = std::max(num_events, max_events);
    } else {
      --num_events;
    }
  }

  return max_events;
}

}  // namespace algo
