#include "hacker_rank/one_month/week_2/equilibrium.h"
#include <numeric>

bool EquilibriumBruteForce(const std::vector<int> arr) {
  for (size_t i = 0; i < arr.size(); ++i) {
    int left = std::accumulate(arr.begin(), arr.begin() + i, 0);
    int right = std::accumulate(arr.begin() + i + 1, arr.end(), 0);
    if (left == right) return true;
  }
  return false;
}

bool Equilibrium(const std::vector<int> arr) {
  int total_sum = std::accumulate(arr.begin(), arr.end(), 0);
  int left_sum = 0;

  for (size_t i = 0; i < arr.size(); ++i) {
    int right_sum = total_sum - left_sum - arr[i];
    if (left_sum == right_sum) return true;
    left_sum += arr[i];
  }

  return false;
}