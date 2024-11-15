#include "hacker_rank/search/min_time.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <numeric>

namespace {

TEST(MinTime, BasicWorks) {
  EXPECT_THAT(MinTime(std::vector<long>{2, 3, 2}, 10), 8);
  EXPECT_THAT(MinTime(std::vector<long>{2, 3}, 5), 6);
  EXPECT_THAT(MinTime(std::vector<long>{1, 3, 4}, 10), 7);
  EXPECT_THAT(MinTime(std::vector<long>{4, 5, 6}, 12), 20);
}
long GetProduction(long day, const std::vector<long>& machines) {
  long sum = 0L;
  for (const long& machine : machines) {
    sum += day / machine;
  }
  return sum;
}

// Example: goal is 10 items. You have three machines that take
// machines = [2, 3, 2] days to produce an item.
// Day Production  Count
// 2   2               2
// 3   1               3
// 4   2               5
// 6   3               8
// 8   2              10
TEST(Accumulate, Works) {
  std::vector<long> machines{2, 3, 2};

  auto items_at_day = [&](long day) {
    return std::accumulate(
        machines.begin(), machines.end(), 0L,
        [day](long sum, long machine) { return sum + day / machine; });
  };

  EXPECT_THAT(items_at_day(2), 2);
  EXPECT_THAT(items_at_day(3), 3);
  EXPECT_THAT(items_at_day(8), 10);

  EXPECT_THAT(GetProduction(2, machines), 2);
  EXPECT_THAT(GetProduction(3, machines), 3);
  EXPECT_THAT(GetProduction(8, machines), 10);
}

}  // namespace