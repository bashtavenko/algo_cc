#include "hacker_rank/socks.h"
#include <unordered_map>
#include <vector>

int GetSocksPairs(const std::vector<int>& ar) {
  std::unordered_map<int, int> pairs;
  for (auto& value : ar) {
    if (pairs.count(value) == 0) {
      pairs[value] = 1;
    } else {
      ++pairs[value];
    }
  }

  int result = 0;
  for (auto& [k, v] : pairs) {
    result += v / 2;
  }

  return result;
}