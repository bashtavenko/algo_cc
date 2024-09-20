// If the amount spent by a client on a particular day is greater than or equal
// to the client's 2 x median spending for a trailing number of days, they send
// the client a notification about potential fraud.
//
// Given the number of trailing days d and a client's total daily expenditures
// for a period of n days, determine the number of times the client will receive
// a notification over all n days.
//
// Example: [10, 20, 30, 40, 50] d = 3
// [10, 20, 30] median = 20 40 >= 20 * 2. 40 is notice
// [20, 30, 40] median = 30 50 < 2 * 30, no notice.
// Example 2: days = 5
// 2 3 4 2 3 6 8 4 5
// [2 3 4 2 3] => [2 2 3 3 4] m = 3 6 >= 2 * 3

#ifndef ALGO_CC_HACKER_RANK_SORTING_ACTIVITY_NOTIFICATIONS_H_
#define ALGO_CC_HACKER_RANK_SORTING_ACTIVITY_NOTIFICATIONS_H_
#include <vector>

int ActivityNotifications(std::vector<int>& expenditure, int d);

#endif  // ALGO_CC_HACKER_RANK_SORTING_ACTIVITY_NOTIFICATIONS_H_
