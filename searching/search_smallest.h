// 11.3 Find the position of the smallest element in a cyclically sorted array.
//
// Cyclical means it is possible to shift entities that array becomes
// sorted.
//
// 378, 478, 550, 631, 103, 203, 220, 234, 279, 368
//
// Answer [4] = 103
// Essentially it's NOT a deep/peek finding because an array
// is sorted but has one minimum.
//
// Close to 1d nearest neighbour search
//
#ifndef ALGO_CC_SEARCHING_SEARCH_SMALLEST_H_
#define ALGO_CC_SEARCHING_SEARCH_SMALLEST_H_

#include <cstdint>
#include <vector>

namespace algo {

size_t SearchSmallest(const std::vector<int32_t>& data);

}  // namespace algo

#endif  // ALGO_CC_SEARCHING_SEARCH_SMALLEST_H_
