#include "hacker_rank/search/pairs.h"
#include <unordered_set>
#include <vector>

// [1, 2, 3, 4], k = 1
// [2, 1], [3, 2] [4, 3]
// {{1:0}, {2:1}, {3:2}, {4:3}}
// .....
// [1, 5, 3, 4, 2], k = 2
// [5, 3], [4, 2], [3, 1]
// {{1:0}, {5:1}, {3:2}}
int Pairs(int k, std::vector<int> arr) {
  std::unordered_set<int> set;
  int count = 0;
  for (const int& value : arr) {
    //    C++ 20
    //    if (set.contains(value - k)) ++count;
    //    if (set.contains(value + k)) ++count;
    if (auto it = set.find(value - k); it != set.end()) ++count;
    if (auto it = set.find(value + k); it != set.end()) ++count;
    set.insert(value);
  }
  return count;
}