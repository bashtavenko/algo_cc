#ifndef ALGO_CC_SORTING_LINE_SWEEPS_H_
#define ALGO_CC_SORTING_LINE_SWEEPS_H_
#include <cstdint>
#include <vector>

namespace algo {
// Given intervals, return the maximum number of overlapping intervals at any
// point It does not mean that if any two intervals overlap. This is close to
// Fast Rectangle Overlap algorithm.
int32_t LineSweeps1D(std::vector<std::pair<int32_t, int32_t>>& input);
}  // namespace algo

#endif  // ALGO_CC_SORTING_LINE_SWEEPS_H_
