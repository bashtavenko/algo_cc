// 10.3 Sort almost-sorted array
#ifndef ALGO_CC_HEAPS_ALMOST_SORTED_H_
#define ALGO_CC_HEAPS_ALMOST_SORTED_H_
#include <cstdint>
#include <queue>
#include <vector>

namespace algo {

std::vector<int32_t> SortAlmost(size_t k,
                                const std::vector<int32_t>::const_iterator& end,
                                std::vector<int32_t>::const_iterator begin);

}  // namespace algo

#endif  // ALGO_CC_HEAPS_ALMOST_SORTED_H_
