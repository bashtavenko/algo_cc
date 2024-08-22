#include "heaps/closest_stars.h"
#include <queue>
#include <vector>

namespace algo {

std::vector<Star> FindClosestStars(std::vector<Star>::const_iterator begin,
                                   const std::vector<Star>::const_iterator& end,
                                   size_t k) {
  // We want max_heap
  std::priority_queue<Star, std::vector<Star>, std::less<>> max_heap;

  // Just add them while keeping size no greater than k.
  while (begin != end) {
    max_heap.emplace(*begin++);
    if (max_heap.size() == k + 1) {
      max_heap.pop();
    }
  }

  std::vector<Star> closest_stars;
  while (!max_heap.empty()) {
    closest_stars.emplace_back(max_heap.top());
    max_heap.pop();
  }
  return {closest_stars.rbegin(), closest_stars.rend()};
}

}  // namespace algo
