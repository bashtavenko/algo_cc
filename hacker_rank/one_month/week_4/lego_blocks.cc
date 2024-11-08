#include "hacker_rank/one_month/week_4/lego_blocks.h"
#include <cmath>
#include <vector>

int LegoBlocks(int n, int m) {
  constexpr int MOD = 1000000007;
  std::vector<long long> row_ways(m + 1, 0);
  std::vector<long long> total_ways(m + 1, 0);
  std::vector<long long> invalid_ways(m + 1, 0);

  // Calculate row combinations
  row_ways[0] = 1;
  row_ways[1] = 1;
  row_ways[2] = 2;
  row_ways[3] = 4;
  for (int i = 4; i <= m; ++i) {
    row_ways[i] = (row_ways[i - 1] + row_ways[i - 2] + row_ways[i - 3] +
                   row_ways[i - 4]) %
                  MOD;
  }

  // Calculate total combinations
  for (int i = 1; i <= m; ++i) {
    total_ways[i] = std::pow(row_ways[i], n);
    total_ways[i] %= MOD;
  }

  // Calculate invalid combinations
  for (int i = 1; i <= m; ++i) {
    invalid_ways[i] = total_ways[i];
    for (int j = 1; j < i; ++j) {
      invalid_ways[i] -= (invalid_ways[j] * total_ways[i - j]) % MOD;
      invalid_ways[i] = (invalid_ways[i] + MOD) % MOD;
    }
  }

  return invalid_ways[m];
}