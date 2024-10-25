#include "hacker_rank/one_month/week_2/dynamic_array.h"

std::vector<int> DynamicArray(int n, std::vector<std::vector<int>> queries) {
  int last_answer = 0;
  std::vector<int> result;
  auto arr = std::vector<std::vector<int>>(n);
  int idx = 0;
  for (const std::vector<int>& query : queries) {
    int x = query[1];
    int y = query[2];
    idx = (x ^ last_answer) % n;
    if (query[0] == 1) {
      // Type 1
      arr[idx].push_back(y);
    } else {
      // Type 2
      last_answer = arr[idx][y % arr[idx].size()];
      result.push_back(last_answer);
    }
  }
  return result;
}