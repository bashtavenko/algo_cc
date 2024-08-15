// 13.5 Determine the maximum number of events that take place concurrently.
// or find the height in the calendar.
//             e8                      e9
//          |----|           |------------------------|
//             e5          e6              e7
//      |---------------| |--|         |------]
//          e1            e2         e3      e4
//   |-----------|  |----------|  |------|  |---|
//---------------------------------------------------------->
// 0  1           5  6          10 11     13 14  15    17
//
// Maximum number of concurrent events is 3 (e1, e5, e8) or (e3, e7, e9) or (e4,
// e7, e9)
//
// Convert intervals to points and then sort points ascending by x and is_start:
// X  is_start
// 1  y
// 2  y
// 4  y
// 5  n
// 5  n
//....
// 9  y  # If x is the same, start should come before finish
// 9  n
//
// Then walk that sorted list of points and track counts.
//
#ifndef ALGO_CC_SORTING_CALENDAR_H_
#define ALGO_CC_SORTING_CALENDAR_H_
#include <cstdint>
#include <vector>

namespace algo {
struct Event {
  int32_t start;
  int32_t finish;
};

// For the Event(1, 5) => Endpoints[{1, true}, {5, false}}
struct Endpoint {
  int32_t time;
  bool is_start;

  bool operator<(const Endpoint that) const {
    // Sort by time, breaking ties by putting start before finish time.
    return time != that.time ? time < that.time : (is_start && !is_start);
  }
};

int32_t FindMaximumEvents(const std::vector<Event>& events);

}  // namespace algo

#endif  // ALGO_CC_SORTING_CALENDAR_H_
