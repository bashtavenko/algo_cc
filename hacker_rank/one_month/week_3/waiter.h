// You are a waiter at a party. There is a pile of numbered plates. Create an
// empty  array. At each iteration i, remove each plate from the top of the
// stack in order. Determine if the number on the plate is evenly divisible by
// the i prime number. If it is, stack it in pile B. Otherwise, stack it in
// stack A. Store the values in B from top to bottom in answers.
//
// In the next iteration, do the
// same with the values in stack A. Once the required number of iterations is
// complete, store the remaining values in A in answers, again from top to
// bottom. Return the answers array.
// This is designed to get very boring and very quickly.

#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_WAITER_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_WAITER_H_
#include <vector>

std::vector<int> Waiter(const std::vector<int>& number, int q);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_WAITER_H_
