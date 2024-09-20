#include "hacker_rank/sorting/activity_notifications.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
TEST(ActivityNotifications, Example1Works) {
  std::vector<int> data{2, 3, 4, 2, 3, 6, 8, 4, 5};
  EXPECT_THAT(ActivityNotifications(data, 5), 2);
}

// TEST(ActivityNotifications, Example2Works) {
//   std::vector<int> data{1, 2, 3, 4, 4};
//   EXPECT_THAT(ActivityNotifications(data, 4), 0);
// }

}  // namespace