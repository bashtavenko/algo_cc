#include "sorting/calendar.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>

namespace algo {
namespace {

TEST(FindMaximumEvents, Works) {
  const std::vector<Event> data{Event{1, 5},   Event(6, 10), Event{11, 13},
                                Event(14, 15), Event(2, 7),  Event(8, 9),
                                Event(12, 15), Event(4, 5),  Event(9, 17)};
  EXPECT_THAT(FindMaximumEvents(data), 3);
}

}  // namespace
}  // namespace algo