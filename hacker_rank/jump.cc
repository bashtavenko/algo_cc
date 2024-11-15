#include "hacker_rank/jump.h"
#include <vector>

int JumpOnClouds(const std::vector<int>& c) {
  // 0, 1, 0, 0, 0, 1, 0 => 3 (0 -> 2 -> 4 -> 6)
  // 0, 0, 1, 0, 0, 1, 0 => 4 (0 -> 1 -> 2 -> 3 -> 4)
  int jumps = 0;
  size_t i = 0;

  while (i < c.size() - 1) {
    // Always try to jump two clouds if possible
    if (i + 2 < c.size() && c[i + 2] == 0) {
      i += 2;
    } else {
      i += 1;
    }
    jumps++;
  }

  return jumps;
}
