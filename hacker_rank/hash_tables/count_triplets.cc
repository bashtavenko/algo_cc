#include "hacker_rank/hash_tables/count_triplets.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Triplet {
  int i;
  int j;
  int k;

  Triplet(int i, int j, int k) : i(i), j(j), k(k) {};

  bool operator==(const Triplet& other) const {
    return i == other.i && j == other.j && k == other.k;
  }
};

struct TripletHash {
  size_t operator()(const Triplet& triplet) const {
    size_t h1 = std::hash<int>()(triplet.i);
    size_t h2 = std::hash<int>()(triplet.j);
    size_t h3 = std::hash<int>()(triplet.k);

    // Combine the hash values with xor
    return h1 ^ (h2 << 1) ^ (h3 << 2);
  }
};

long CountTripletsBruteForce(std::vector<long> arr, long r) {
  std::unordered_set<Triplet, TripletHash> cache;
  long count = 0;
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 1; j < arr.size(); ++j) {
      for (int k = 2; k < arr.size(); ++k) {
        Triplet triplet(i, j, k);
        if (auto it = cache.find(triplet); it != cache.end()) continue;
        if (arr[j] / arr[i] == r && arr[k] / arr[j] == r) {
          cache.insert(triplet);
          ++count;
        }
      }
    }
  }
  return count;
}

long CountTriplets(std::vector<long> arr, long r) {
  // Occurrences of numbers we've seen so far
  std::unordered_map<long, long> left;
  // Potential third elements in a triplet.
  std::unordered_map<long, long> right;
  long count = 0;

  // Count all occurrences
  for (long num : arr) {
    ++right[num];
  }

  for (long num : arr) {
    --right[num];

    if (num % r == 0) {
      long prev = num / r;
      long next = num * r;
      count += left[prev] * right[next];
    }

    ++left[num];
  }

  return count;
}