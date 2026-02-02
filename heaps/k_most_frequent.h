// Given a large vector of integers, find the top-k most frequent elements.
#ifndef ALGO_CC_K_MOST_FREQUENT_H
#define ALGO_CC_K_MOST_FREQUENT_H

#include <cstdint>
#include <vector>

namespace algo {

// [2, 3, 5, 7, 1, 1, 1, 2, 3], k = 2
// Result: [1, 3] or [2, 3]
std::vector<int32_t> KMostFrequent(const std::vector<int32_t>& nums, size_t k);

} // namespace algo


#endif  // ALGO_CC_K_MOST_FREQUENT_H
