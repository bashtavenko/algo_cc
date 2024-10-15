#include "hacker_rank/greedy/greedy_florist.h"
#include <algorithm>
#include <numeric>

// [2, 5, 6] k = 3
// [1, 2, 3, 4] k = 3
// (1 + 1) * 1 = 2
int GetMinimumCostPrototype(int k, std::vector<int> c) {
  const int n = c.size();

  std::sort(c.begin(), c.end(), std::greater_equal<>());

  // [4, 3, 2, 1]
  int friends_bought = 0;
  int i = 0;
  int cost = 0;
  while (i < n) {
    if (friends_bought < k) {
      cost += c[i];
    } else {
      // We still have more people than flowers
      // TODO: previous_purchase should not be hardcoded
      int previous_purchase = 1;
      cost += (previous_purchase + 1) * c[i];
    }
    ++i;
    ++friends_bought;
  }

  return cost;
}

int GetMinimumCost(int k, std::vector<int> c) {
  const int n = c.size();

  // Sort flowers by descending price
  std::sort(c.begin(), c.end(), std::greater<>());

  int cost = 0;
  int purchases[k];  // To track the number of flowers each friend has bought
  std::fill(purchases, purchases + k, 0);  // Initialize all to 0

  for (int i = 0; i < n; ++i) {
    int friend_index = i % k;  // Distribute flowers evenly among friends
    cost += (purchases[friend_index] + 1) * c[i];
    purchases[friend_index]++;  // Increment the count for that friend
  }

  return cost;
}