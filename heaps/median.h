// 10.5 Compute the median of online data
// Created by s15o on 8/10/24.
//
#ifndef ALGO_CC_HEAPS_MEDIAN_H_
#define ALGO_CC_HEAPS_MEDIAN_H_
#include <cstdint>
#include <vector>

namespace algo {

std::vector<double> OnlineMedian(
    std::vector<int32_t>::const_iterator seq_begin,
    const std::vector<int32_t>::const_iterator seq_end);

}  // namespace algo

#endif  // ALGO_CC_HEAPS_MEDIAN_H_
