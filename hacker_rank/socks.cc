#include "hacker_rank/socks.h"
#include <unordered_map>
#include <vector>

int GetSocksPairs(const std::vector<int>& ar) {
  std::unordered_map<int, int> map;
  for (auto& value : ar) ++map[value];

  int result = 0;
  for (const auto& [k, v] : map) {
    result += v / 2;
  }
  return result;
}