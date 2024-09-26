#include "hacker_rank/search/min_time.h"
#include <algorithm>
#include <numeric>
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
// 5
// 6   3               8
// 7
// 8   2              10

struct ProductionItem {
  int day;
  int production;
  int count;
};

// 1. Create ProductionItems
// 2. Sum up counts
// 3. Loop through the log

long MinTimeFirstAttempt(const std::vector<long>& machines, long goal) {
  constexpr int kMaxDays = 30;
  std::vector<ProductionItem> production(kMaxDays + 1);

  // Day setup
  for (int day = 1; day <= kMaxDays; ++day) {
    production[day] = ProductionItem{.day = day};
  }

  // Propagate each machine
  for (const auto& machine_day : machines) {
    int day = machine_day;
    while (day < kMaxDays) {
      ++production[day].production;
      ++production[day].count;
      day += machine_day;
    }
  }

  // Prune zeros
  std::vector<ProductionItem> production_no_dup;
  for (const ProductionItem& production_item : production) {
    if (production_item.production > 0)
      production_no_dup.emplace_back(production_item);
  }

  // Rollup
  for (size_t i = 1; i < production_no_dup.size(); ++i) {
    production_no_dup[i].count =
        production_no_dup[i - 1].count + production_no_dup[i].production;
  }

  for (const ProductionItem& item : production_no_dup) {
    if (item.count >= goal) return item.day;
  }

  return -1;
}

long MinTime(const std::vector<long>& machines, long goal) {
  if (machines.empty() || goal <= 0) return 0;

  // machines [2, 3, 2], goal = 10
  // std::max_element
  long max_days = *std::max_element(machines.begin(), machines.end()) * goal;

  //  int sum = std::accumulate(v.begin(), v.end(), 0);
  //  int product = std::accumulate(v.begin(), v.end(), 1,
  //  std::multiplies<int>());
  auto items_at_day = [&](long day) {
    return std::accumulate(
        machines.begin(), machines.end(), 0L,
        [day](long sum, long machine) { return sum + day / machine; });
  };

  // The point is because we are looking for the monotonous sequence of days,
  // we can do binary search to find the best option.
  long lo = 0, hi = max_days;
  while (lo < hi) {
    long mid = lo + (hi - lo) / 2;
    if (items_at_day(mid) >= goal) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  return lo;
}