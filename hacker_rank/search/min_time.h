// You are planning production for an order. You have a number of machines that
// each have a fixed number of days to produce an item. Given that all the
// machines operate simultaneously, determine the minimum number of days to
// produce the required order.
//
// Example: goal is 10 items. You have three machines that take
// machines = [2, 3, 2] days to produce an item.
// Day Production  Count
// 2   2               2
// 3   1               3
// 4   2               5
// 6   3               8
// 8   2              10
// It takes 8 days to produce 10 items using these machines.
// machines: days to produce one item per machine.
//
// Example 1:
// Goal is 5 [2, 3]
// Days Production Count
//  2      1          1       // machine 1 completed
//  3      1          2       // machine 2 completed
//  4      1          3       // machine 1 completed
//  6      2          5       // machine 1 + 2 completed
// Answer: 6 days

#ifndef ALGO_CC_HACKER_RANK_SEARCH_MIN_TIME_H_
#define ALGO_CC_HACKER_RANK_SEARCH_MIN_TIME_H_
#include <vector>

long MinTime(const std::vector<long>& machines, long goal);

#endif  // ALGO_CC_HACKER_RANK_SEARCH_MIN_TIME_H_
