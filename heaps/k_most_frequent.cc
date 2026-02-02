#include "heaps/k_most_frequent.h"
#include <queue>
#include <unordered_map>

namespace algo {

std::vector<int32_t> KMostFrequent(const std::vector<int32_t>& nums, size_t k) {
  std::unordered_map<int32_t, size_t> freq;  // Frequency, Value}
  for (const auto& num : nums) freq[num]++;

  // Pair is sorted lexicographically
  // Alternatively, we can provide a lambda comparator
  using Element = std::pair<int32_t, size_t>;
  std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;

  for (const auto& [num, freq] : freq) {
    pq.emplace(freq, num);
    if (pq.size() > k) pq.pop();
  }
  std::vector<int32_t> result;
  while (!pq.empty()) {
    result.emplace_back(pq.top().first);
    pq.pop();
  }
  return result;
}

}  // namespace algo
