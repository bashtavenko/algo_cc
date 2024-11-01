#include "hacker_rank/one_month/week_3/ranking.h"
#include <algorithm>
#include <vector>

std::vector<int> Rank(const std::vector<int>& ranked,
                      const std::vector<int>& player) {
  // Remove duplicates and sort ranked in descending order
  std::vector<int> unique_ranked(ranked.begin(), ranked.end());
  auto last = std::unique(unique_ranked.begin(), unique_ranked.end());
  unique_ranked.erase(last, unique_ranked.end());

  std::vector<int> output;
  int rank = unique_ranked.size();   // Initial rank
  int i = unique_ranked.size() - 1;  // Pointer for ranked scores

  // Evaluate each player's score
  for (const int& score : player) {
    // Move up the leaderboard until player's score fits
    while (i >= 0 && score >= unique_ranked[i]) {
      --i;
      --rank;
    }
    output.push_back(rank + 1);  // Rank is 1-indexed
  }

  return output;
}