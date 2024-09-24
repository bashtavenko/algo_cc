#include "hacker_rank/search/triple_sum.h"
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

// [3, 5, 7] [3, 6] [4, 6, 9]
// (3,6,4), (3,6,6), (5,6,4), (5,6,6)
// ...
// [1, 3, 5]
// [2, 3]
// [1, 2, 3]
// (1, 2, 1), (1, 2, 2), (1, 3, 1), (1, 3, 2), (1, 3, 3) ...

// [3, 5, 7] [3, 6] [4, 6, 9]
// (3,6,4), (3,6,6), (5,6,4), (5,6,6)
// ...
// [1, 3, 5]
// [2, 3]
// [1, 2, 3]
// (1, 2, 1), (1, 2, 2), (1, 3, 1), (1, 3, 2), (1, 3, 3) ...

struct Triplet {
  int x;
  int y;
  int z;

  Triplet(int x, int y, int z) : x(x), y(y), z(z) {}

  bool operator==(const Triplet& other) const {
    return x == other.x && y == other.y && z == other.z;
  }
};

struct TripletHash {
  size_t operator()(const Triplet& triplet) const {
    size_t h1 = std::hash<int>()(triplet.x);
    size_t h2 = std::hash<int>()(triplet.y);
    size_t h3 = std::hash<int>()(triplet.z);

    // Combine the hash values with xor
    return h1 ^ (h2 << 1) ^ (h3 << 2);
  }
};

// a = {1, 4, 5}, b = {2, 3, 3}, c = {1, 2, 3}:
//
//(1,2,1), (1,2,2), (1,3,1), (1,3,2), (1,3,3) -> Count: 5
long Triplets(const std::vector<int>& a, const std::vector<int>& b,
              const std::vector<int>& c) {
  long count = 0;
  std::unordered_set<Triplet, TripletHash> set;

  for (int a_val : a) {
    auto b_it = std::lower_bound(b.begin(), b.end(), a_val);

    for (; b_it != b.end(); ++b_it) {
      auto c_it = std::upper_bound(c.begin(), c.end(), *b_it);
      auto c_val = c.begin();
      while (c_val != c_it) {
        Triplet triplet(a_val, *b_it, *c_val);
        if (auto it = set.find(triplet); it != set.end()) break;
        set.insert(triplet);
        ++count;
        ++c_val;
      }
    }
  }
  return count;
}
