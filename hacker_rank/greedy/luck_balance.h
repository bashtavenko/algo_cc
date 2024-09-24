// There are contests associated with luck (L) and importance (1 is important,
// otherwise no);
// Contest	L[i]	T[i]
// 1		5	1
// 2            1	1
// 3            4	0
// L[i] is the amount of luck associated with a contest. If Lena wins the
// contest, her luck balance will decrease by L[i].
//  If she loses it, her luck balance will increase by L[i]
//  T[i] denotes the contest's importance rating. It's
//   equal to 1  if the contest is important, and it's equal to 0 if it's
// unimportant.
// Luck starts with 0
// k - the number of important contests Lena can lose.
// If Lena loses no more than k important contests, what is the maximum amount
// of luck she can have after competing in all the preliminary contests? Example
// if k = 2 and there are two, the luck is 5 + 1 + 4 = 10;
// if k = 1, she would choose to win the lowest important value;

#ifndef ALGO_CC_HACKER_RANK_GREEDY_LUCK_BALANCE_H_
#define ALGO_CC_HACKER_RANK_GREEDY_LUCK_BALANCE_H_
#include <vector>

int LuckBalance(int k, std::vector<std::vector<int>>& contests);

#endif  // ALGO_CC_HACKER_RANK_GREEDY_LUCK_BALANCE_H_
