#include "hacker_rank/greedy/luck_balance.h"
#include <algorithm>
#include <vector>

int LuckBalance(int k, std::vector<std::vector<int>>& contests) {
  int luck_balance = 0;
  // Separate important and non-important.
  std::vector<int> important_contests;
  for (const auto& contest : contests) {
    if (contest.back() == 1) {
      important_contests.push_back(contest.front());
    } else {
      luck_balance += contest.front();
    }
  }
  std::sort(important_contests.begin(), important_contests.end(),
            std::greater<>());

  // Go greedy
  for (size_t i = 0; i < important_contests.size(); ++i) {
    if (k > 0) {
      luck_balance += important_contests[i];
      --k;
    } else {
      luck_balance -= important_contests[i];
    }
  }

  return luck_balance;
}
