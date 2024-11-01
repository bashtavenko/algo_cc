// An arcade game player wants to climb to the top of the leaderboard and track
// their ranking. The game uses Dense Ranking, so its leaderboard works like
// this:
// * The player with the highest score is ranked number  on the leaderboard.
// * Players who have equal scores receive the same ranking number, and the next
// player(s) receive the immediately following ranking number.
// Example: ranked = [100, 90, 90, 80]
// player = [70, 80, 105]
// Return = [4, 3, 1] for each [70, 80, 105]

#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_RANKING_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_RANKING_H_

#include <vector>
std::vector<int> Rank(const std::vector<int>& ranked,
                      const std::vector<int>& player);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_3_RANKING_H_
