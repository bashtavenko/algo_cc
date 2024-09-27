#include "hacker_rank/search/ice_cream.h"
#include <unordered_map>
#include <vector>

// [2, 1, 3, 5, 6] money 5
//  Answer 2 + 3
Result WhatFlavorsBruteForce(std::vector<int> cost, int money) {
  Result result;
  for (int i = 0; i < cost.size(); ++i) {
    for (int j = i + 1; j < cost.size(); ++j) {
      if (cost[i] + cost[j] == money) {
        result.first_index = i + 1;
        result.second_index = j + 1;
      }
    }
  }
}

// [2, 1, 3, 5, 6] money 5
//  Answer 2 + 3
Result WhatFlavorsBruteForce2(std::vector<int> cost, int money) {
  Result result;
  int best_sum = 0;
  for (int i = 0; i < cost.size(); ++i) {
    int j = 1;
    result.first_index = i;
    while (j < cost.size()) {
      int current_sum = cost[result.first_index] + cost[i];
      if (current_sum <= money) {
        if (current_sum > best_sum) {
          best_sum = current_sum;
          result.second_index = j;
        }
      }
      ++j;
    }
  }
  return result;
}

Result WhatFlavors(const std::vector<int>& cost, int money) {
  std::unordered_map<int, int> cost_map;
  Result result;

  for (int i = 0; i < cost.size(); ++i) {
    int complement = money - cost[i];

    if (cost_map.find(complement) != cost_map.end()) {
      result.first_index = cost_map[complement] + 1;
      result.second_index = i + 1;
      return result;
    }

    cost_map[cost[i]] = i;
  }

  return result;  // Return default result if no solution found
}