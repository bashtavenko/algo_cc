#include "hacker_rank/search/min_time.h"
#include <vector>

//  1   x     x  x
//  2      x     x
//  3   x     x  x
//  ----2--3--4--6--
// [2, 3, 2]
// Day Production  Count
// 2   2               2
// 3   1               3
// 4   2               5
// 6   3               8
// 8   2              10
long MinTime(const std::vector<long>& machines, long goal) {
  int number_of_days = 0;
  // 1
  // 2
  // 3
  std::vector<int> cumulative_machine_count(machines.size(), 0);
  std::vector<int> days(10, 0);
  // Populate days
  for (long day : machines) {
    ++days[day];
  }
  int production = 0;
  int count = 0;
  while (goal > 0) {
    --goal;
  }
  return number_of_days;
}