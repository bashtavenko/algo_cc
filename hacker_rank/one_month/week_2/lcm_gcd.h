// Find all integers x satisfy the following two conditions:
// 1. All elements in array 'a' are the factors of x.
//    x % a[i] == 0. Example [2, 4] = {4, 8, 16}.
// 2. x is a factor of all elements in array 'b' b[i] % x == 0
//    Example: [16, 32, 96] => 4, 8, 16
// 'a' => LCM. x must be divisible by all elements of 'a'
// 'b' => GCD. x must divide all elements of b.
#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_LCM_GCD_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_LCM_GCD_H_
#include <vector>

std::vector<int> GetX(const std::vector<int>& a, const std::vector<int>& b);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_LCM_GCD_H_
