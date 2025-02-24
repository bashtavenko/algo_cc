#include "stacks_queues/dota2.h"
#include <queue>

namespace algo {

// RDD
//
std::string PredictPartyVictorySingleQueueBruteForce(absl::string_view senate) {
  std::queue<char8_t> q;
  for (char c : senate) q.push(c);

  while (!q.empty()) {
    char8_t current_party = q.front();
    q.pop();
    if (q.size() == 1 || q.size() == 0)
      return current_party == 'R' ? "Radiant" : "Dire";

    char8_t next_senator = q.front();
    if (next_senator != current_party) q.pop();
    q.push(current_party);
  }

  return "";
}

std::string PredictPartyVictory(absl::string_view senate) {
  const int n = senate.size();
  std::queue<int> radiant;
  std::queue<int> dire;

  // Separate senators by party using their indices.
  for (int i = 0; i < n; i++) {
    if (senate[i] == 'R')
      radiant.push(i);
    else
      dire.push(i);
  }

  // Simulate the rounds.
  while (!radiant.empty() && !dire.empty()) {
    int r_index = radiant.front();
    radiant.pop();
    int d_index = dire.front();
    dire.pop();

    // The senator with the smaller index gets to ban the other.
    // Reinsert the winning senator with an updated index.
    if (r_index < d_index)
      radiant.push(r_index + n);
    else
      dire.push(d_index + n);
  }

  return radiant.empty() ? "Dire" : "Radiant";
}

}  // namespace algo